# Chaotic-Order

A cross-platform game built with [raylib](https://www.raylib.com/) in C++.

## Quick Start

### Setting up

**For Fish shell users:**
```bash
git clone <your-repo-url>
cd Chaotic-Order
chmod +x setup.fish
./setup.fish
```

**For Bash shell users:**
```bash
git clone <your-repo-url>
cd Chaotic-Order
chmod +x setup.sh
./setup.sh
```

2. **Build and run:**
   ```bash
   make          # Build the game
   make run      # Run the game
   make clean    # Clean build files
   ```

## Platform Support

- ✅ **Linux** (Ubuntu, Arch, Fedora, etc.)
- ✅ **macOS** (via Homebrew)
- ✅ **Windows** (via MSYS2/MinGW64)
- ⚠️  **Windows (Visual Studio)** - Requires manual raylib setup

## Development

- **Source files**: Add `.cpp` files to `src/`
- **Headers**: Add `.h` files to `include/`
- **Assets**: Add textures, sounds, fonts to `assets/`
- **Building**: The Makefile automatically detects your platform

## Project Structure

```
Chaotic-Order/
├── src/           # Source files (.cpp)
├── include/       # Header files (.h)
├── assets/        # Game assets
│   ├── textures/  # Image files
│   ├── sounds/    # Audio files
│   └── fonts/     # Font files
├── build/         # Compiled files (auto-generated)
├── Makefile       # Cross-platform build config
├── setup.fish     # Fish shell setup script
├── setup.sh       # Bash shell setup script
└── README.md      # This file
```

## Troubleshooting

### Linux: "raylib not found"
```bash
sudo ldconfig  # Refresh library cache
pkg-config --libs raylib  # Check if raylib is found
```

### macOS: "command not found: brew"
Install Homebrew first:
```bash
/bin/bash -c "$(curl -fsSL https://raw.githubusercontent.com/Homebrew/install/HEAD/install.sh)"
```

### Windows: Build errors
- Use MSYS2/MinGW64 for easiest setup
- Make sure raylib is in your PATH
- Try building with: `mingw32-make` instead of `make`

### WSL: Display issues
Install an X server on Windows (like VcXsrv) and set:
```bash
export DISPLAY=:0
```

### Permission denied
Make scripts executable:
```bash
chmod +x setup.fish setup.sh
```

## Contributing

1. Fork the repository
2. Create a feature branch
3. Make your changes
4. Test on your platform
5. Submit a pull request