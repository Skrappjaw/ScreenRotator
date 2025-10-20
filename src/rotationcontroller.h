/*
 * Rotation Controller for ScreenRotator
 * Handles auto-rotation locking and manual rotation control
 */

#ifndef ROTATIONCONTROLLER_H
#define ROTATIONCONTROLLER_H

#include <QObject>
#include "orientation.h"

class RotationController : public QObject
{
    Q_OBJECT

public:
    explicit RotationController(QObject* parent = nullptr);
    
    bool isAutoRotationLocked() const { return m_autoRotationLocked; }
    void setAutoRotationLocked(bool locked);
    
    Orientation getCurrentOrientation() const { return m_currentOrientation; }
    void setManualOrientation(Orientation orientation);

public slots:
    void onSensorReading(Orientation orientation);

signals:
    void rotationRequested(Orientation orientation);
    void autoRotationToggled(bool enabled);

private:
    bool m_autoRotationLocked;
    Orientation m_currentOrientation;
};

#endif // ROTATIONCONTROLLER_H

