# Contributing to Enhanced ScreenRotator

Thank you for your interest in contributing to this enhanced ScreenRotator fork! This document provides guidelines for contributing to the project.

## 🎯 Project Goals

This enhanced fork focuses on:
- **Advanced manual rotation controls**
- **Improved user experience**
- **Seamless KDE integration**
- **OpenSUSE optimization**
- **Comprehensive documentation**

## 🚀 Getting Started

### Prerequisites
- Linux system with X11
- Qt5 development environment
- CMake build system
- Git version control

### Development Setup
```bash
# Clone the repository
git clone https://github.com/YOUR_USERNAME/ScreenRotator.git
cd ScreenRotator

# Install dependencies (OpenSUSE)
sudo zypper install -y cmake gcc-c++ qt5-qtbase-devel libXrandr-devel libXi-devel libQt5X11Extras-devel libqt5-qtbase-devel libqt5-qtsensors-devel

# Build the project
mkdir build && cd build
cmake ..
make all
```

## 📝 Contribution Guidelines

### Code Style
- Follow Qt5/C++ best practices
- Use meaningful variable and function names
- Add comments for complex logic
- Maintain consistent indentation (4 spaces)

### Commit Messages
Use clear, descriptive commit messages:
```
feat: add manual rotation mode selection
fix: resolve touch input coordinate transformation
docs: update installation instructions for OpenSUSE
```

### Testing
- Test on target hardware (HP Envy x360 e14)
- Verify all rotation modes work correctly
- Test touch input functionality
- Ensure tray icon integration works properly

## 🐛 Reporting Issues

When reporting issues, please include:
- **OS**: Distribution and version
- **Desktop Environment**: KDE, XFCE, GNOME, etc.
- **Hardware**: Laptop model and specifications
- **Steps to Reproduce**: Detailed steps to reproduce the issue
- **Expected Behavior**: What should happen
- **Actual Behavior**: What actually happens
- **Debug Output**: Any error messages or debug output

## 🔧 Development Areas

### High Priority
- **Hardware Compatibility**: Testing on different convertible laptop models
- **Desktop Environment Support**: Ensuring compatibility across different DEs
- **Performance Optimization**: Improving sensor reading and rotation performance
- **Accessibility**: Adding keyboard shortcuts and accessibility features

### Medium Priority
- **Configuration Management**: Adding persistent settings
- **Animation Support**: Smooth rotation transitions
- **Multi-Monitor Support**: Handling multiple displays
- **Logging System**: Comprehensive logging for debugging

### Low Priority
- **Wayland Support**: Future compatibility with Wayland
- **Mobile Integration**: Support for tablet mode detection
- **Advanced Sensors**: Support for additional sensor types

## 📋 Pull Request Process

1. **Fork** the repository
2. **Create** a feature branch (`git checkout -b feature/amazing-feature`)
3. **Commit** your changes (`git commit -m 'Add amazing feature'`)
4. **Push** to the branch (`git push origin feature/amazing-feature`)
5. **Open** a Pull Request

### Pull Request Guidelines
- Provide a clear description of changes
- Include screenshots for UI changes
- Reference any related issues
- Ensure all tests pass
- Update documentation as needed

## 🧪 Testing Guidelines

### Manual Testing Checklist
- [ ] Application starts without errors
- [ ] Tray icon appears and functions correctly
- [ ] Auto-rotation works with accelerometer
- [ ] Manual rotation modes work correctly
- [ ] Touch input coordinates are properly transformed
- [ ] Context menu functions properly
- [ ] Auto-start configuration works
- [ ] Application exits cleanly

### Hardware Testing
- **Primary**: HP Envy x360 e14 (OpenSUSE Tumbleweed + KDE)
- **Secondary**: Other convertible laptop models
- **Desktop Environments**: KDE, XFCE, GNOME
- **Distributions**: OpenSUSE, Ubuntu, Fedora

## 📚 Documentation

### Required Documentation Updates
- **README.md**: Update for new features
- **CHANGELOG.md**: Document all changes
- **Code Comments**: Add inline documentation
- **API Documentation**: Document public interfaces

### Documentation Style
- Use clear, concise language
- Include code examples where helpful
- Provide troubleshooting information
- Keep installation instructions up-to-date

## 🤝 Community Guidelines

### Code of Conduct
- Be respectful and inclusive
- Provide constructive feedback
- Help others learn and grow
- Follow the golden rule

### Communication
- **Issues**: Use GitHub Issues for bug reports and feature requests
- **Discussions**: Use GitHub Discussions for questions and community support
- **Pull Requests**: Use PR comments for code review discussions

## 📄 License

By contributing to this project, you agree that your contributions will be licensed under the GNU General Public License v3.0.

## 🙏 Recognition

Contributors will be recognized in:
- **README.md**: Contributors section
- **CHANGELOG.md**: Release notes
- **GitHub**: Contributor statistics

---

**Thank you for contributing to the convertible laptop community!** 🚀
