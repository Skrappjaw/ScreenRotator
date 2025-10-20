#include <QApplication>
#include "displaymanager.h"
#include "orientationsensor.h"
#include "trayicon.h"
#include "rotateinput.h"
#include <QtDBus/QDBusConnection>
#include <QDebug>

// Global rotation mode variable
RotationMode currentMode = AUTO;

// Global variable to store last sensor reading
Orientation lastSensorReading = TopUp;

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    QDBusConnection connection = QDBusConnection::sessionBus();
    if(!connection.registerService("net.gulinux.ScreenRotator")) {
      qCritical() << "Unable to register DBUS interface \"net.gulinux.ScreenRotator\". More than one instances running?";
      return 1;
    }
    
    DisplayManager displayManager;
    OrientationSensor sensor;
    RotateInput rotateInput;
    
    // Always create tray icon for lock control
    TrayIcon tray;
    
    // Set component references for tray icon
    tray.setRotationComponents(&displayManager, &rotateInput, &sensor);
    
    // Connect sensor to display and input rotation
    QObject::connect(&sensor, &OrientationSensor::reading, [&](Orientation orientation) {
        // Always store the latest sensor reading (regardless of current mode)
        lastSensorReading = orientation;
        
        // Only apply if in AUTO mode
        if (currentMode == AUTO) {
            displayManager.setOrientation(orientation);
            rotateInput.rotate(orientation);
        }
    });
    
    return app.exec();
}
