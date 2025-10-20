# Changelog

All notable changes to this enhanced ScreenRotator fork are documented in this file.

## [Enhanced Fork] - 2025-01-20

### ✨ Added
- **Advanced Manual Rotation Controls**: Added 4 manual rotation modes (Normal, Left, Right, Upside Down)
- **Smart Auto-Select Feature**: When switching from manual to auto mode, screen returns to current sensor-detected orientation
- **Enhanced Context Menu**: Right-click tray icon provides access to all rotation modes
- **Improved Tray Icon Integration**: Left-click toggles between auto-rotation and locked modes
- **Real-time Tooltip Updates**: Tray icon tooltip shows current rotation mode status
- **Comprehensive Documentation**: Detailed README with installation, usage, and troubleshooting guides
- **OpenSUSE/KDE Optimization**: Optimized for OpenSUSE Tumbleweed with KDE Plasma desktop

### 🔧 Enhanced
- **User Interface**: Improved system tray integration with intuitive controls
- **Rotation Logic**: Enhanced rotation mode management with global state tracking
- **Touch Input Handling**: Improved coordinate transformation for multiple touchscreen devices
- **Desktop Integration**: Better integration with KDE desktop environment
- **Error Handling**: Improved error handling and debug output

### 🐛 Fixed
- **Icon Loading**: Fixed icon loading with proper fallback mechanisms
- **Sensor Reading Storage**: Fixed global sensor reading storage for auto-select functionality
- **Mode Transitions**: Fixed smooth transitions between different rotation modes

### 📚 Documentation
- **README.md**: Complete rewrite with enhanced features, installation instructions, and usage guide
- **Installation Guide**: Added OpenSUSE-specific installation instructions
- **Troubleshooting**: Added comprehensive troubleshooting section
- **Technical Details**: Added architecture and component documentation

### 🎯 Target Hardware
- **Primary**: HP Envy x360 e14 convertible laptop
- **OS**: OpenSUSE Tumbleweed
- **Desktop**: KDE Plasma
- **Compatibility**: X11-based desktop environments

---

## [Original] - 2018

### Original Features (by GuLinux)
- Basic automatic screen rotation based on accelerometer readings
- X11 display rotation support
- Touch input coordinate transformation
- System tray integration
- Qt5-based implementation

### Original Credits
- **Author**: Marco Gulino (GuLinux)
- **License**: GPL v3
- **Repository**: https://github.com/GuLinux/ScreenRotator
