#include "Game.h"

void Game::gameLoop(SDL_Event& event) {
        while (SDL_PollEvent(&event)) {
            switch (event.type) {
                case SDL_QUIT:
                    setRunning(false);
                    break;

                case SDL_KEYDOWN: {
                    switch (event.key.keysym.sym) {
                        case SDLK_ESCAPE:
                            setRunning(false);
                            break;
                    }
                }
            }
        }
    };

