# CPP Pong v0.1

This is a practice project using SDL2 to implement Pong, and practice using CMake.

## Status:

Is currently a black window.

## Roadmap:

### Engine:
- [x] Manhandle CMake to work with Windows without VS or VSC.
- [x] Window Class
- [x] Renderer Class
- [x] Game Class
- [x] 2D Vector Class
- [x] Entity Class

- [ ] Set up Game class to handle entities, loop through, etc

### Game:
- [ ] Paddle Class
    - [ ] Moving Up/Down
    - [ ] Bounds Checking
- [ ] Player Controls
- [ ] Ball Class
    - [ ] Movement
    - [ ] Velocity
    - [ ] Redirection/Bouncing
- [ ] Collision Checking
- [ ] Player Class
- [ ] Simple AI for CPU player
- [ ] Winchecking on Game Class
- [ ] Win Screen
- [ ] Play Again
- [ ] Start Screen

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
