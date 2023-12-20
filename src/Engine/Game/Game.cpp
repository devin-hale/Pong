#include "Game.h"

#include <iostream>

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

void Game::addEntity(Entity* ent) { m_entities.push_back(ent); };

void Game::renderEntities() {
	m_renderer->setColor(255,255,255,0);
    for (Entity* ent : m_entities) {
        switch (ent->getType()) {
            case Entity::EntityType::Blank:
                break;
            case Entity::EntityType::Ball:
                ent->render(m_renderer->m_drawLinePtr,
                            m_renderer->getRenderer());
                break;
        };
    };
};
