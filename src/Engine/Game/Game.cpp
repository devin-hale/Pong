#include "Game.h"

// Private
void Game::exitGame() {
    setIsRunning(false);
    SDL_Quit();
};

// Public
Game::Game(Window* window, Renderer* renderer)
    : m_window{window}, m_renderer{renderer} {
    setIsRunning(true);
};

Game::~Game() {
    delete m_window;
    m_window = nullptr;
    delete m_renderer;
    m_renderer = nullptr;
}

void Game::gameLoop(SDL_Event& event) {
    while (SDL_PollEvent(&event)) {
        switch (event.type) {
            case SDL_QUIT:
                exitGame();
                break;

            case SDL_KEYDOWN: {
                switch (event.key.keysym.sym) {
                    case SDLK_ESCAPE:
                        exitGame();
                        break;
                }
            }
        }
    }
};
