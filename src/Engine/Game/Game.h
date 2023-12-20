#ifndef GAME_H
#define GAME_H

#include <SDL.h>

#include <vector>

#include "../Entity/Entity.h"
#include "../Renderer/Renderer.h"
#include "../Window/Window.h"

class Game {
   private:
    bool m_isRunning{false};
    Window* m_window{nullptr};
    Renderer* m_renderer{nullptr};
    std::vector<Entity*> m_entities{};

    void setIsRunning(bool boolean) { m_isRunning = boolean; };

    void exitGame();

   public:
    Game() = delete;

    Game(Window* window, Renderer* renderer);

    ~Game();

    bool isRunning() { return m_isRunning; };

    void gameLoop(SDL_Event& event);

	void addEntity(Entity* ent);

	void renderEntities();
};

#endif
