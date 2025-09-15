# ⚔️ Chaotic-Order
### Take over the board and bring Order ... or unleash Chaos.
Welcome to Chaotic-Order. A fast-paced showdown where you battle an AI for control a 10x10 grid. 

![alt text](./assets/images/demo.png)

## 🎯 Your Mission
- Play as ORDER and build structure by lining up 5 of your pieces to win
    - e.g. line up 5 pieces of the same type horizontally, vertically or diagonally
- Play as CHAOS and wreak havoc by preventing the opponent to algin their pieces

## 🕹️ How to Play
1. Your role will be determined at the start of the game whether you or ORDER or CHAOS
2. Take turn with a bot placing one piece per turn anywhere on the 10x10 grid
3. Use your mouse to determine which piece you want to place
    - Left-click => ✅
    - Right-click => ❌
4. Win the game as ORDER by lining 5 of your pieces in a row in any direction
5. Win the game as CHAOS by filling up the board and preventing the opponent to align their pieces

## 🤖 Meet Your Opponent

This isn’t just any bot. It’s been built to think — fast.
🧠 It scans every possible move.
🎯 It calculates potential outcomes.
⚔️ It plays to win — or to destroy your chances.

Read more on its weaknesses [here](#dev-reflection)

## Quick Start

### Setting up

**For Fish shell users:**
```bash
git clone https://github.com/gatory/Chaotic-Order.git
cd Chaotic-Order
chmod +x setup.fish
./setup.fish
```

**For Bash shell users:**
```bash
git clone https://github.com/gatory/Chaotic-Order.git
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

# Dev-Reflection
## Bot Weaknesses
How the Bot Thinks:
- it scans every empty square and find if either piece will make the game win
- chooses the first square that makes the game win
- iterates through every alignment from 5 to 1 to make the best possible move
- chooses random empty square if no win scenario is found

Weakness:
- the bot will prioritize the first best alignment that makes the game win
- the bot will also prioritize:
    - rows > columns > diagonal up-left/down-right > up-right/down-left
- this means that the bot can get distracted if there are more than 2 possible alignments of the same probability to win

Strengths:
- the bot preys on the players weakness of making hasty decision without thinking thoroughly what the outcome may be
    - the bot may see win scenario where the players missed
- however, generally it is quite easy to win against the bot

## Testing
- throughtout this project, not much testing has been conducted, however, due to the way the project was constructed, testing is minimally needed
- the project was constructed with modular components, meaning that it is easily and removed, and before using the components, they were tested through gameplay by myself
- hence, since the project was tested modularly, overall testing is overlooked
- nevertheless, that is something I will definietly look into once I get more time

## The Next Steps
- implement overall testing to the components used and overall system
- re-think bot logic and minimize weakness:
    - can be done through generative recursion
    - can be done through reinforcement-learning algorithms
- make the overall game design more asthetically pleasing
    - make game intro panel
    - make settiings panel
    - make the ability to swap roles
    - add visual instructions on how to play