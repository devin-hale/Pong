#include "main.h"

#include <SDL.h>
#include <SDL_render.h>

#include "Engine/Game/Game.h"
#include "Engine/Renderer/Renderer.h"
#include "Engine/Window/Window.h"
#include "PongLib/Ball/Ball.h"
#include "PongLib/Net/Net.h"
#include "PongLib/Paddle/Paddle.h"
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
	Paddle* playerPaddle{new Paddle{true, window->getWidth(), window->getHeight()}};
	Paddle* cpuPaddle{new Paddle{false, window->getWidth(), window->getHeight()}};

	game->addPlayerEntity(playerPaddle);
	game->addCpuEntity(cpuPaddle);
	game->addEntity(playerPaddle);
	game->addEntity(cpuPaddle);
    game->addEntity(ball);
	game->addEntity(net);
    ball->setDirection(1);
	ball->setVel(5);

    while (game->isRunning()) {
        SDL_Event event;
        game->gameLoop(event);

        ball->movePos(window->getWidth(), window->getHeight(), playerPaddle, cpuPaddle, *game);

        renderer->renderBackGround();
        game->renderEntities();
		game->renderScores();
        renderer->render();
    }

    delete game;
    return 0;
}
