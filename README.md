# CPP Pong v0.1

This is a practice project using SDL2 to implement Pong, and practice using CMake.

## Status:

Currently over-engineering an engine for a pong clone just to experiment and try things out.

## Roadmap:

### Engine:
- [x] Manhandle CMake to work with Windows without VS or VSC.
- [x] Window Class
- [x] Renderer Class
- [x] Game Class
- [x] 2D Vector Class
- [x] Entity Class
- [x] Set up Game class to handle entities, loop through, etc

### Game:
- [x] Paddle Class
    - [x] Moving Up/Down
    - [x] Bounds Checking
- [x] Player Controls
- [x] Ball Class
    - [x] Movement
    - [x] Velocity
    - [x] Redirection/Bouncing
- [x] Collision Checking
- [ ] Simple AI for CPU player
- [ ] Winchecking
- [ ] Win Screen
- [ ] Play Again
- [ ] Start Screen
- [ ] Sound Effects

- [ ] Create/Find simple icons
- [ ] Setup installing through CMake

## Dependencies

(If Building with CMake)
- SDL2 (https://github.com/libsdl-org/SDL/releases/tag/release-2.28.5)
    - Ensure that the SDL directory is available in your PATH
    - Place the x64 SDL2.dll in the same build folder as Pong.exe

## How To Build

### Build
- Clone this repo:
    ```git clone https://github.com/devin-hale/Pong```

- Navigate to the folder

- Configure project using CMake
    ```cmake -B /out/build ./```

- Build project using CMake
    ```cmake -B /out/build -S```

- Run Pong.exe
