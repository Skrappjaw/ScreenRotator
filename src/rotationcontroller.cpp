/*
 * Rotation Controller for ScreenRotator
 * Handles auto-rotation locking and manual rotation control
 */

#include "rotationcontroller.h"
#include <QDebug>

RotationController::RotationController(QObject* parent)
    : QObject(parent)
    , m_autoRotationLocked(false)
    , m_currentOrientation(TopUp)
{
}

void RotationController::setAutoRotationLocked(bool locked)
{
    if (m_autoRotationLocked != locked) {
        m_autoRotationLocked = locked;
        qDebug() << "Auto-rotation" << (locked ? "locked" : "unlocked");
    }
}

void RotationController::setManualOrientation(Orientation orientation)
{
    m_currentOrientation = orientation;
    emit rotationRequested(orientation);
    qDebug() << "Manual rotation to:" << orientation;
}

void RotationController::onSensorReading(Orientation orientation)
{
    if (!m_autoRotationLocked) {
        m_currentOrientation = orientation;
        emit rotationRequested(orientation);
        qDebug() << "Auto-rotation to:" << orientation;
    }
}
