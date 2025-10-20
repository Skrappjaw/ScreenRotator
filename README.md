# ScreenRotator - Enhanced Convertible Laptop Screen Rotation Manager

[![License: GPL v3](https://img.shields.io/badge/License-GPLv3-blue.svg)](https://www.gnu.org/licenses/gpl-3.0)
[![Platform: X11](https://img.shields.io/badge/Platform-X11-green.svg)](https://www.x.org/)
[![Desktop: KDE](https://img.shields.io/badge/Desktop-KDE-blue.svg)](https://kde.org/)

A Qt-based screen rotation manager that automatically rotates your display based on accelerometer sensor readings. **Enhanced with advanced manual rotation controls, improved user interface, and seamless KDE integration.**

## ✨ Enhanced Features

### 🎯 **Core Functionality**
- **Automatic Screen Rotation**: Detects laptop orientation via accelerometer and rotates display accordingly
- **Manual Rotation Control**: Lock screen to any of 4 orientations (Normal, Left, Right, Upside Down)
- **Smart Auto-Lock Toggle**: Left-click tray icon to quickly toggle between auto-rotation and locked modes
- **Context Menu**: Right-click tray icon for full control over all rotation modes
- **Auto-Select**: When switching from manual to auto mode, screen returns to current sensor-detected orientation

### 🖥️ **Display & Input Management**
- **X11 Display Rotation**: Uses xrandr for smooth display rotation
- **Touch Input Rotation**: Automatically rotates touch coordinates to match display orientation
- **Multi-Device Support**: Handles multiple touchscreen devices with coordinate transformation matrices
- **Hardware Acceleration**: Optimized for convertible laptops with touchscreen capabilities

### 🎨 **User Interface**
- **System Tray Integration**: Clean tray icon with intuitive tooltips
- **Visual Feedback**: Real-time tooltip updates showing current rotation mode
- **Silent Operation**: Runs in background without cluttering desktop
- **KDE Integration**: Seamlessly integrates with KDE desktop environment

## 🚀 Quick Start

### Prerequisites
- **OS**: Linux with X11 (tested on OpenSUSE Tumbleweed)
- **Desktop**: KDE Plasma (also works with XFCE, GNOME, etc.)
- **Hardware**: Convertible laptop with accelerometer sensor and touchscreen

### Installation

#### For OpenSUSE Tumbleweed with KDE:
```bash
# Install dependencies
sudo zypper install -y cmake gcc-c++ qt5-qtbase-devel libXrandr-devel libXi-devel libQt5X11Extras-devel libqt5-qtbase-devel libqt5-qtsensors-devel

# Clone and build
git clone https://github.com/skrappjaw/ScreenRotator.git
cd ScreenRotator
mkdir build && cd build
cmake ..
make all
sudo make install
```

#### For Ubuntu/Debian:
```bash
# Install dependencies
sudo apt install -y git cmake build-essential qtbase5-dev libxrandr-dev libxi-dev libqt5x11extras5-dev libqt5sensors5-dev

# Clone and build
git clone https://github.com/skrappjaw/ScreenRotator.git
cd ScreenRotator
mkdir build && cd build
cmake ..
make all
sudo make install
```

### Auto-Start Configuration
The application automatically installs an autostart entry. It will start automatically when you log into your desktop environment.

## 🎮 Usage Guide

### Tray Icon Controls
- **Left Click**: Toggle between auto-rotation and locked mode
- **Right Click**: Open context menu with all rotation options

### Rotation Modes
1. **Auto Rotation**: Automatically rotates based on accelerometer readings
2. **Lock Current**: Locks screen in current orientation
3. **Manual Normal**: Forces normal (0°) orientation
4. **Manual Left**: Forces left (90°) orientation  
5. **Manual Right**: Forces right (270°) orientation
6. **Manual Upside Down**: Forces upside down (180°) orientation

### Smart Auto-Select Feature
When switching from any manual mode back to auto mode, the screen automatically rotates to match the current physical orientation detected by the accelerometer sensor.

## 🔧 Technical Details

### Architecture
- **Base Framework**: Qt5 with X11 extensions
- **Sensor Integration**: Qt5 Sensors module for accelerometer access
- **Display Management**: X11 RandR extension for display rotation
- **Input Management**: XInput2 for touch coordinate transformation
- **Desktop Integration**: Qt5 Widgets for system tray functionality

### Key Components
- `DisplayManager`: Handles X11 display rotation via xrandr
- `OrientationSensor`: Reads accelerometer data for orientation detection
- `RotateInput`: Rotates touch input coordinates to match display orientation
- `TrayIcon`: System tray integration with context menu and click handlers

### Supported Hardware
- **Tested**: HP Envy x360 e14 convertible laptop
- **Compatible**: Any convertible laptop with accelerometer sensor and touchscreen
- **Desktop Environments**: KDE Plasma, XFCE, GNOME (X11 only)

## 🐛 Troubleshooting

### Common Issues

**Q: ScreenRotator doesn't start automatically**
A: Check if the autostart file exists: `/etc/xdg/autostart/screenrotator-autostart.desktop`

**Q: Touch input is not rotated correctly**
A: Ensure your touchscreen device supports coordinate transformation matrices. Check with `xinput list` and `xinput list-props <device-id>`

**Q: No accelerometer sensor detected**
A: Verify sensor availability: `sensors-detect` or check `/sys/bus/iio/devices/`

**Q: Application crashes on startup**
A: Check Qt5 dependencies are installed: `ldd /usr/local/bin/screenrotator`

### Debug Mode
Run with debug output to troubleshoot issues:
```bash
QT_LOGGING_RULES="*=true" screenrotator
```

## 🤝 Contributing

This is an enhanced fork of the original [ScreenRotator by GuLinux](https://github.com/GuLinux/ScreenRotator). 

### Enhancements Made
- ✅ Advanced manual rotation controls
- ✅ Improved user interface with context menu
- ✅ Smart auto-select functionality
- ✅ Enhanced tray icon integration
- ✅ Comprehensive documentation
- ✅ OpenSUSE/KDE optimization

### Contributing Guidelines
1. Fork the repository
2. Create a feature branch
3. Make your changes
4. Test thoroughly on target hardware
5. Submit a pull request

## 📄 License

This project is licensed under the GNU General Public License v3.0 - see the [LICENSE](LICENSE) file for details.

## 🙏 Acknowledgments

- **Original Author**: [Marco Gulino](https://github.com/GuLinux) for the base ScreenRotator implementation
- **Icon Source**: [IconFinder](https://www.iconfinder.com/icons/326583/orientation_rotation_screen_icon#size=256)
- **Community**: OpenSUSE and KDE communities for excellent documentation and support

## 📞 Support

- **Issues**: Report bugs and feature requests via GitHub Issues
- **Discussions**: Use GitHub Discussions for questions and community support
- **Hardware Testing**: Contributions welcome for testing on different convertible laptop models

---

**Made with ❤️ for the convertible laptop community**