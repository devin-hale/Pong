#include "main.h"

#include <SDL.h>
#include <SDL_render.h>

#include "Engine/Game/Game.h"
#include "Engine/Renderer/Renderer.h"
#include "Engine/Vec2D/Vec2D.h"
#include "Engine/Window/Window.h"
#include "Pong/Ball/Ball.h"
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

    Vec2D* start{new Vec2D{window->getWidth() / 2, 0}};
    Vec2D* end{new Vec2D{window->getWidth() / 2, window->getHeight()}};

	Ball* ball{new Ball{window->getWidth()/2, window->getHeight()/2 , 25, 25, 2}};

	int (*drawLinePtr)(SDL_Renderer *renderer, int x1, int y1, int x2, int y2){SDL_RenderDrawLine};


    while (game->isRunning()) {
        SDL_Event event;
        game->gameLoop(event);

		ball->movePos();
		ball->setDirection(45);

        renderer->renderBackGround();
        renderer->drawLine(start, end);

		ball->render(drawLinePtr, renderer->getRenderer());
        renderer->render();
    }

	delete ball;
    delete start;
    delete end;
    delete game;
    return 0;
}
