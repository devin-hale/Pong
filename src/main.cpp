#include "main.h"

#include <SDL.h>
#include <SDL_render.h>
#include <SDL_video.h>

#include "Game/Game.h"
#include "version.h"

constexpr int windowHeight{720};
constexpr int windowWidth{1280};

int main(int argc, char* argv[]) {
    std::cout << "Pong v" << Pong_VERSION_MAJOR << "." << Pong_VERSION_MINOR
              << "\n";

    if (SDL_Init(SDL_INIT_EVERYTHING) < 0) {
        std::cout << "Failed to initialize SDL2\n";
        return -1;
    }

    SDL_Window* window =
        SDL_CreateWindow("Pong", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,
                         windowWidth, windowHeight, 0);

    SDL_Renderer* renderer = SDL_CreateRenderer(window, -1, 0);

    Game game{};

	SDL_Event event;
    while (game.getRunning()) {
        game.gameLoop(event);

        SDL_SetRenderDrawColor(renderer, 0, 0, 0, 0);
        SDL_RenderClear(renderer);

        SDL_RenderPresent(renderer);
    }

    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();

    return 0;
}
