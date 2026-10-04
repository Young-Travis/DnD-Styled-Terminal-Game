#ifndef GAME_HPP
#define GAME_HPP

#include <SDL3/SDL.h>
#include "MainMenu.hpp"
#include "Settings.hpp"
#include "CharacterCreator.hpp"
#include "GameState.hpp"

class Game{
public:
    bool running = false;
    SDL_Renderer* renderer;
    GameState currentState;

    MainMenu mainMenu;
    Settings settings;
    CharacterCreator characterCreator;

    Game(SDL_Renderer* r);

    void run();

    void handleInput(SDL_Event& event);
};


#endif