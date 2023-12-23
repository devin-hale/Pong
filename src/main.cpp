#include "main.h"

#include <SDL.h>
#include <SDL_render.h>

#include "Engine/Game/Game.h"
#include "Engine/Renderer/Renderer.h"
#include "Engine/Window/Window.h"
#include "Pong/Ball/Ball.h"
#include "Pong/Net/Net.h"
#include "version.h"

int main(int argc, char* argv[]) {
    std::cout << "Pong v" << Pong_VERSION_MAJOR << "." << Pong_VERSION_MINOR
              << "\n";

    if (SDL_Init(SDL_INIT_EVERYTHING) < 0) {
        std::cout << "Failed to initialize SDL2\n";
        return -1;
    }

    // TODO: Consolidate initialization in Game constructor
    Window* window{new Window{}};
    Renderer* renderer{new Renderer{window->getWindow()}};
    Game* game{new Game{window, renderer}};

	Net* net{new Net(window->getWidth(), window->getHeight())};
    Ball* ball{
        new Ball{window->getWidth() / 2, window->getHeight() / 2, 25, 25, 3}};

    game->addEntity(ball);
	game->addEntity(net);
    ball->setDirection(45);

    while (game->isRunning()) {
        SDL_Event event;
        game->gameLoop(event);

        ball->movePos(window->getWidth(), window->getHeight());
		ball->setVel(5);

        renderer->renderBackGround();
        game->renderEntities();
        renderer->render();
    }

    delete ball;
    delete game;
    return 0;
}
