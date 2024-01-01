#ifndef GAME_H
#define GAME_H

#include <SDL.h>
#include <SDL_ttf.h>

#include <vector>

#include "../../PongLib/PlayerScore/PlayerScore.h"
#include "../Entity/Entity.h"
#include "../Renderer/Renderer.h"
#include "../Window/Window.h"

class Game {
   private:
    bool m_isRunning{false};
    Window* m_window{nullptr};
    Renderer* m_renderer{nullptr};
    std::vector<Entity*> m_entities{};
    Entity* m_playerEntity{nullptr};
    TTF_Font* m_gameFont{nullptr};
    std::vector<PlayerScore*> m_scores{};

    void setIsRunning(bool boolean) { m_isRunning = boolean; };

    void exitGame();

   public:
    Game() = delete;

    Game(Window* window, Renderer* renderer);

    ~Game();

    bool isRunning() { return m_isRunning; };

    void gameLoop(SDL_Event& event);

    void addEntity(Entity* ent);

    void addPlayerEntity(Entity* ent) { m_playerEntity = ent; };

    void renderEntities();

	void renderScores();

    void checkCollision();
};

#endif
