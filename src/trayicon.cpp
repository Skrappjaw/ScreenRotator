/*
 * <one line to give the program's name and a brief idea of what it does.>
 * Copyright (C) 2018  Marco Gulino <marco@gulinux.net>
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#include "trayicon.h"
#include "displaymanager.h"
#include "rotateinput.h"
#include "orientation.h"
#include <QSystemTrayIcon>
#include <QTimer>
#include <QMenu>
#include <QAction>
#include <QActionGroup>
#include <QApplication>
#include <QDebug>

using namespace std;
class TrayIcon::Private {
public:
  QSystemTrayIcon tray;
  unique_ptr<QMenu> menu;
  QActionGroup* modeGroup;
  QAction* autoAction;
  QAction* lockedAction;
  QAction* manualNormalAction;
  QAction* manualLeftAction;
  QAction* manualRightAction;
  QAction* manualUpsideAction;
  
  // References to rotation components
  DisplayManager* displayManager;
  RotateInput* rotateInput;
  OrientationSensor* sensor;
};

TrayIcon::TrayIcon(QObject* parent) : QObject{parent}, d{new Private}
{
  // Initialize component references to nullptr
  d->displayManager = nullptr;
  d->rotateInput = nullptr;
  d->sensor = nullptr;
  
  // Try to load from theme first, then fallback to local icon
  QIcon icon = QIcon::fromTheme("screenrotator");
  if (icon.isNull()) {
    // Fallback to local icon file - use absolute path
    icon = QIcon("/home/skrapp/Cursor/convertable_laptop_integrations/ScreenRotator-master/src/resources/16x16/apps/screenrotator.png");
  }
  d->tray.setIcon(icon);
  
  // Create context menu
  d->menu.reset(new QMenu());
  d->modeGroup = new QActionGroup(this);
  
  // Auto/Lock section
  d->autoAction = d->menu->addAction("Auto Rotation");
  d->autoAction->setCheckable(true);
  d->autoAction->setActionGroup(d->modeGroup);
  connect(d->autoAction, &QAction::triggered, this, &TrayIcon::setAutoMode);
  
  d->lockedAction = d->menu->addAction("Lock Current");
  d->lockedAction->setCheckable(true);
  d->lockedAction->setActionGroup(d->modeGroup);
  connect(d->lockedAction, &QAction::triggered, this, &TrayIcon::setLockedMode);
  
  d->menu->addSeparator();
  
  // Manual rotation section
  d->manualNormalAction = d->menu->addAction("Manual Normal");
  d->manualNormalAction->setCheckable(true);
  d->manualNormalAction->setActionGroup(d->modeGroup);
  connect(d->manualNormalAction, &QAction::triggered, this, &TrayIcon::setManualNormal);
  
  d->manualLeftAction = d->menu->addAction("Manual Left");
  d->manualLeftAction->setCheckable(true);
  d->manualLeftAction->setActionGroup(d->modeGroup);
  connect(d->manualLeftAction, &QAction::triggered, this, &TrayIcon::setManualLeft);
  
  d->manualRightAction = d->menu->addAction("Manual Right");
  d->manualRightAction->setCheckable(true);
  d->manualRightAction->setActionGroup(d->modeGroup);
  connect(d->manualRightAction, &QAction::triggered, this, &TrayIcon::setManualRight);
  
  d->manualUpsideAction = d->menu->addAction("Manual Upside Down");
  d->manualUpsideAction->setCheckable(true);
  d->manualUpsideAction->setActionGroup(d->modeGroup);
  connect(d->manualUpsideAction, &QAction::triggered, this, &TrayIcon::setManualUpside);
  
  d->tray.setContextMenu(d->menu.get());
  
  // Connect left-click to handle override behavior
  connect(&d->tray, &QSystemTrayIcon::activated, [this](QSystemTrayIcon::ActivationReason reason) {
    if (reason == QSystemTrayIcon::Trigger) { // Left-click
      handleLeftClick();
    }
  });
  
  updateMenu();
  updateTooltip();
  QTimer::singleShot(100, &d->tray, &QSystemTrayIcon::show);
}

TrayIcon::~TrayIcon()
{
}

void TrayIcon::setRotationComponents(DisplayManager* displayManager, RotateInput* rotateInput, OrientationSensor* sensor)
{
  d->displayManager = displayManager;
  d->rotateInput = rotateInput;
  d->sensor = sensor;
}

Orientation TrayIcon::rotationModeToOrientation(RotationMode mode)
{
  switch (mode) {
    case MANUAL_NORMAL:
      return TopUp;
    case MANUAL_LEFT:
      return LeftUp;
    case MANUAL_RIGHT:
      return RightUp;
    case MANUAL_UPSIDE:
      return TopDown;
    default:
      return TopUp; // Default fallback
  }
}

void TrayIcon::applyOrientation(Orientation orientation)
{
  if (d->displayManager && d->rotateInput) {
    d->displayManager->setOrientation(orientation);
    d->rotateInput->rotate(orientation);
    qDebug() << "Applied orientation:" << orientation;
  }
}


void TrayIcon::handleLeftClick()
{
  // If in any manual mode, override to AUTO
  if (currentMode >= MANUAL_NORMAL) {
    setAutoMode();
  } else {
    // Toggle between AUTO and LOCKED
    if (currentMode == AUTO) {
      setLockedMode();
    } else {
      setAutoMode();
    }
  }
}

void TrayIcon::setAutoMode()
{
  currentMode = AUTO;
  // Apply the last known sensor reading immediately
  applyOrientation(lastSensorReading);
  updateMenu();
  updateTooltip();
  qDebug() << "Mode set to AUTO - applied last sensor reading:" << lastSensorReading;
}

void TrayIcon::setLockedMode()
{
  currentMode = LOCKED;
  updateMenu();
  updateTooltip();
  qDebug() << "Mode set to LOCKED";
}

void TrayIcon::setManualNormal()
{
  currentMode = MANUAL_NORMAL;
  // Immediately apply normal orientation (sensor disabled by mode check)
  applyOrientation(TopUp);
  updateMenu();
  updateTooltip();
  qDebug() << "Mode set to MANUAL_NORMAL - applied TopUp";
}

void TrayIcon::setManualLeft()
{
  currentMode = MANUAL_LEFT;
  // Immediately apply left orientation (sensor disabled by mode check)
  applyOrientation(LeftUp);
  updateMenu();
  updateTooltip();
  qDebug() << "Mode set to MANUAL_LEFT - applied LeftUp";
}

void TrayIcon::setManualRight()
{
  currentMode = MANUAL_RIGHT;
  // Immediately apply right orientation (sensor disabled by mode check)
  applyOrientation(RightUp);
  updateMenu();
  updateTooltip();
  qDebug() << "Mode set to MANUAL_RIGHT - applied RightUp";
}

void TrayIcon::setManualUpside()
{
  currentMode = MANUAL_UPSIDE;
  // Immediately apply upside down orientation (sensor disabled by mode check)
  applyOrientation(TopDown);
  updateMenu();
  updateTooltip();
  qDebug() << "Mode set to MANUAL_UPSIDE - applied TopDown";
}

void TrayIcon::updateMenu()
{
  // Update radio button states
  d->autoAction->setChecked(currentMode == AUTO);
  d->lockedAction->setChecked(currentMode == LOCKED);
  d->manualNormalAction->setChecked(currentMode == MANUAL_NORMAL);
  d->manualLeftAction->setChecked(currentMode == MANUAL_LEFT);
  d->manualRightAction->setChecked(currentMode == MANUAL_RIGHT);
  d->manualUpsideAction->setChecked(currentMode == MANUAL_UPSIDE);
}

void TrayIcon::updateTooltip()
{
  QString tooltip = "Screen Rotator - ";
  switch (currentMode) {
    case AUTO:
      tooltip += "Auto-rotation enabled";
      break;
    case LOCKED:
      tooltip += "Auto-rotation LOCKED";
      break;
    case MANUAL_NORMAL:
      tooltip += "Manual Normal (locked)";
      break;
    case MANUAL_LEFT:
      tooltip += "Manual Left (locked)";
      break;
    case MANUAL_RIGHT:
      tooltip += "Manual Right (locked)";
      break;
    case MANUAL_UPSIDE:
      tooltip += "Manual Upside Down (locked)";
      break;
  }
  d->tray.setToolTip(tooltip);
}
