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