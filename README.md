# ScreenRotator - Enhanced Convertible Laptop Screen Rotation Manager

> **Fork Notice**: This is an enhanced fork of the original [ScreenRotator by GuLinux](https://github.com/GuLinux/ScreenRotator). This version has been tested and optimized for OpenSUSE Tumbleweed with KDE Plasma on X11, and should work with any other Linux distribution using X11.

## Original Description

Simple Qt screen rotation manager that reads from accelerometer sensors and rotates display according to the readings.

Works only in X11 for now.

Similar to the current solution implemented in Gnome, but works on all other desktop environments as well (KDE, XFCE, etc).

## ✨ Enhanced Features in This Fork

### 🎯 **Advanced Manual Controls**
- **Manual Rotation Modes**: Lock screen to any of 4 orientations (Normal, Left, Right, Upside Down)
- **Smart Auto-Select**: When switching from manual to auto mode, screen returns to current sensor-detected orientation
- **Quick Toggle**: Left-click tray icon to toggle between auto-rotation and locked modes

### 🖥️ **Improved User Interface**
- **Enhanced Context Menu**: Right-click tray icon for access to all rotation modes
- **Real-time Tooltips**: Tray icon shows current rotation mode status
- **Better Integration**: Seamless integration with KDE desktop environment

### 🔧 **Technical Improvements**
- **Enhanced Touch Input**: Improved coordinate transformation for multiple touchscreen devices
- **Better Error Handling**: Improved error handling and debug output
- **Optimized Performance**: Enhanced rotation mode management with global state tracking

## Compilation Requirements

- cmake
- gcc
- Qt5 (with modules x11extras, sensors)
- xrandr
- XInput (Xi)

### For OpenSUSE Tumbleweed:
```bash
sudo zypper install -y cmake gcc-c++ qt5-qtbase-devel libXrandr-devel libXi-devel libQt5X11Extras-devel libqt5-qtbase-devel libqt5-qtsensors-devel
```

### For Ubuntu/Debian:
```bash
sudo apt install -y git cmake build-essential qtbase5-dev libxrandr-dev libxi-dev libqt5x11extras5-dev libqt5sensors5-dev
```

## Building

```bash
git clone https://github.com/skrappjaw/ScreenRotator
mkdir ScreenRotator/build
cd ScreenRotator/build
cmake ..
make all
sudo make install
```

## Usage

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

## Compatibility

- **Tested Hardware**: HP Envy x360 e14 convertible laptop
- **OS**: OpenSUSE Tumbleweed (should work on any Linux distribution)
- **Desktop Environment**: KDE Plasma (compatible with XFCE, GNOME, etc.)
- **Display Server**: X11 only (Wayland not supported)

## Troubleshooting

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

## Credits

- **Original Author**: [Marco Gulino (GuLinux)](https://github.com/GuLinux) - Base ScreenRotator implementation
- **Enhanced Fork**: [skrappjaw](https://github.com/skrappjaw) - Manual controls and KDE optimization
- **Icon Source**: [IconFinder](https://www.iconfinder.com/icons/326583/orientation_rotation_screen_icon#size=256)

## License

This project is licensed under the GNU General Public License v3.0 - see the [LICENSE](LICENSE) file for details.

## Links

- **Original Repository**: https://github.com/GuLinux/ScreenRotator
- **Enhanced Fork**: https://github.com/skrappjaw/ScreenRotator
- **Main Icon**: https://www.iconfinder.com/icons/326583/orientation_rotation_screen_icon#size=256

---

**Made with ❤️ for the convertible laptop community**