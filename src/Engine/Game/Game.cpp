#include "Game.h"

#include <SDL_events.h>
#include <SDL_filesystem.h>
#include <SDL_keyboard.h>
#include <SDL_scancode.h>
#include <SDL_ttf.h>

#include <iostream>

#include "../Text/Text.h"

// Private
void Game::exitGame() {
    setIsRunning(false);
    SDL_Quit();
};

// Public
Game::Game(Window* window, Renderer* renderer)
    : m_window{window}, m_renderer{renderer} {
    TTF_Init();

    std::string fontPath = SDL_GetBasePath();
    fontPath += "RobotoMono.ttf";
    std::cout << fontPath << "\n";
    m_gameFont = TTF_OpenFont(fontPath.c_str(), 40);
    setIsRunning(true);

    m_scores.push_back(new PlayerScore{
        1, new Text{new Vec2D{m_window->getWidth() / 4, 20},
                    m_renderer->getRenderer(), 20, 20, m_gameFont}});
};

Game::~Game() {
    delete m_window;
    delete m_renderer;
    for (Entity* ent : m_entities) {
        delete ent;
    };
    TTF_CloseFont(m_gameFont);
    TTF_Quit();
}

void Game::gameLoop(SDL_Event& event) {
    const Uint8* currentKeyStates = SDL_GetKeyboardState(NULL);

    if (currentKeyStates[SDL_SCANCODE_S]) {
        m_playerEntity->setVel(15);
        m_playerEntity->setDirection(90);
        m_playerEntity->move(m_window->getWidth(), m_window->getHeight());
    };

    if (currentKeyStates[SDL_SCANCODE_W]) {
        m_playerEntity->setVel(15);
        m_playerEntity->setDirection(-90);
        m_playerEntity->move(m_window->getWidth(), m_window->getHeight());
    };

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

            case SDL_KEYUP: {
                switch (event.key.keysym.sym) {
                    case SDLK_w:
                    case SDLK_s:
                        m_playerEntity->setVel(0);
                        break;
                }
            }
        }
    }
};

void Game::addEntity(Entity* ent) { m_entities.push_back(ent); };

void Game::renderEntities() {
    m_renderer->setColor(255, 255, 255, 0);
    for (Entity* ent : m_entities) {
        switch (ent->getType()) {
            case Entity::EntityType::Blank:
                break;
            case Entity::EntityType::Net:
            case Entity::EntityType::Paddle:
            case Entity::EntityType::Ball:
                ent->render(m_renderer->m_drawLinePtr,
                            m_renderer->getRenderer());
                break;
        };
    };
};

void Game::renderScores() {
    for (PlayerScore* score : m_scores) {
        score->Render();
    };
}
