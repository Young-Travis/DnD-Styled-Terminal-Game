#include <iostream>
#include "hpp/Game.hpp"
#include "hpp/MainMenu.hpp"
#include "hpp/CharacterCreator.hpp"


using namespace std;

Game::Game(SDL_Renderer* r) : mainMenu(r), characterCreator(r){
    renderer = r;
    currentState = GameState::MainMenu;
}

void Game::run()
{
    running = true;

    while (running)
    {
        SDL_Event event;

        while (SDL_PollEvent(&event))
        {
            if (event.type == SDL_EVENT_QUIT)
            {
                running = false;
            }

            handleInput(event);
        }

        SDL_SetRenderDrawColor(renderer, 25, 25, 25, 255);
        SDL_RenderClear(renderer);
        SDL_RenderPresent(renderer);
    }
}

void Game::handleInput(SDL_Event& event)
{
    switch (currentState){
        case GameState::MainMenu:
            mainMenu.handleInput(event);
            break;

        case GameState::CharacterCreator:
            characterCreator.handleInput(event);
            break;

        /*
            case GameState::Battle:
            battle.handleInput(event);
            break;
        */
    }
}