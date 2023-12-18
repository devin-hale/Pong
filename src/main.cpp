#include "main.h"

#include <SDL.h>

#include "Game/Game.h"
#include "Renderer/Renderer.h"
#include "Vec2D/Vec2D.h"
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

    Vec2D* start{new Vec2D{window->getWidth() / 2, 0}};
    Vec2D* end{new Vec2D{window->getWidth() / 2, window->getHeight()}};

    while (game->isRunning()) {
        SDL_Event event;
        game->gameLoop(event);

        renderer->renderBackGround();
        renderer->drawLine(start, end);
        renderer->render();
    }

    delete start;
    delete end;
    delete game;
    return 0;
}
