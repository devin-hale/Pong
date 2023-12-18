#include "main.h"

#include <SDL.h>

#include "Game/Game.h"
#include "Renderer/Renderer.h"
#include "Window/Window.h"
#include "version.h"

int main(int argc, char* argv[]) {
    std::cout << "Pong v" << Pong_VERSION_MAJOR << "." << Pong_VERSION_MINOR
              << "\n";
    if (SDL_Init(SDL_INIT_EVERYTHING) < 0) {
        std::cout << "Failed to initialize SDL2\n";
        return -1;
    }

    Window* window{new Window{}};
    Renderer* renderer{new Renderer{window->getWindow()}};
    Game* game{new Game{window, renderer}};

    while (game->isRunning()) {
        SDL_Event event;
        game->gameLoop(event);
		renderer->render();
    }

    delete game;
    return 0;
}
