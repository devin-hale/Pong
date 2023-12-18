#ifndef GAME_H
#define GAME_H

#include <SDL.h>

class Game {
   private:
    bool m_running{true};

   public:
    Game(){};

    bool getRunning() { return m_running; };

    void setRunning(bool tf) { m_running = tf; };

    void gameLoop(SDL_Event& event);

	void gameExit();
};

#endif
