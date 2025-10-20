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

#ifndef TRAYICON_H
#define TRAYICON_H

#include <QObject>
#include <memory>
#include "orientation.h"

// Forward declarations
enum RotationMode {
    AUTO,           // Normal auto-rotation based on sensor
    LOCKED,         // Locked in current orientation
    MANUAL_NORMAL,  // Manually locked to normal (0°)
    MANUAL_LEFT,    // Manually locked to left (90°)
    MANUAL_RIGHT,   // Manually locked to right (270°)
    MANUAL_UPSIDE   // Manually locked to upside down (180°)
};

extern RotationMode currentMode;
extern Orientation lastSensorReading;

class DisplayManager;
class RotateInput;
class OrientationSensor;

class TrayIcon : public QObject
{
    Q_OBJECT
public:
    TrayIcon(QObject* parent = nullptr);
    ~TrayIcon();
    
    // Set references to rotation components
    void setRotationComponents(DisplayManager* displayManager, RotateInput* rotateInput, OrientationSensor* sensor);

private slots:
    void handleLeftClick();
    void setAutoMode();
    void setLockedMode();
    void setManualNormal();
    void setManualLeft();
    void setManualRight();
    void setManualUpside();
    void updateTooltip();
    void updateMenu();

private:
    // Helper functions
    Orientation rotationModeToOrientation(RotationMode mode);
    void applyOrientation(Orientation orientation);
    
  class Private;
  std::unique_ptr<Private> d;
};

#endif // TRAYICON_H
