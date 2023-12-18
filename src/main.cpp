#include "main.h"

#include <SDL.h>

#include "Game/Game.h"
#include "Window/Window.h"
#include "version.h"

int main(int argc, char* argv[]) {
    std::cout << "Pong v" << Pong_VERSION_MAJOR << "." << Pong_VERSION_MINOR
              << "\n";

    if (SDL_Init(SDL_INIT_EVERYTHING) < 0) {
        std::cout << "Failed to initialize SDL2\n";
        return -1;
    }

	Window window{};

    SDL_Renderer* renderer = SDL_CreateRenderer(window.getWindow(), -1, 0);

    Game game{};

    while (game.getRunning()) {
		SDL_Event event;
        game.gameLoop(event);

        SDL_SetRenderDrawColor(renderer, 0, 0, 0, 0);
        SDL_RenderClear(renderer);

        SDL_RenderPresent(renderer);
    }

    SDL_DestroyRenderer(renderer);
    SDL_Quit();

    return 0;
}
