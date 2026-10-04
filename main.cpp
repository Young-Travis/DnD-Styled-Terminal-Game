#include <SDL3/SDL.h>
#include <iostream>

#include "hpp/Game.hpp"

using namespace std;

int main(){
    if (!SDL_Init(SDL_INIT_VIDEO)){
        cout << "SDL_Init failed: " << SDL_GetError() << endl;
        return 1;
    }

    SDL_Window* window = SDL_CreateWindow(
        "Travis' Game",
        800,
        600,
        0
    );

    if (window == nullptr){
        cout << "SDL_CreateWindow failed: " << SDL_GetError() << endl;
        SDL_Quit();
        return 1;
    }

    SDL_Renderer* renderer = SDL_CreateRenderer(window, nullptr);

    SDL_SetRenderLogicalPresentation(renderer, 160, 144, SDL_LOGICAL_PRESENTATION_INTEGER_SCALE);

    if (renderer == nullptr){
        cout << "SDL_CreateRenderer failed: " << SDL_GetError() << endl;
        SDL_DestroyWindow(window);
        SDL_Quit();

        return 1;
    }

    Game game(window, renderer);

    game.run();

    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);

    SDL_Quit();

    return 0;
}