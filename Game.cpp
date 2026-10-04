#include <iostream>
#include "hpp/Game.hpp"
#include "hpp/MainMenu.hpp"
#include "hpp/CharacterCreator.hpp"

using namespace std;

Game::Game(SDL_Window* w, SDL_Renderer* r) : window(w), mainMenu(r), settings(r), characterCreator(r){
    renderer = r;
    currentState = GameState::MainMenu;
    SDL_StartTextInput(window);
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

        switch (currentState){
            case GameState::MainMenu:
                mainMenu.update();
                if (auto requestedState = mainMenu.getRequestedState()){
                    currentState = *requestedState;
                }
                break;

            case GameState::Settings:
                settings.update();
                if (auto requestedState = settings.getRequestedState()){
                    currentState = *requestedState;
                }
                break;

            case GameState::CharacterCreator:
                characterCreator.update();
                break;

            case GameState::Quit:
                running = false;
                break;
        }

        switch (currentState){
            case GameState::MainMenu:
                mainMenu.draw();
                break;

            case GameState::Settings:
                settings.draw();
                break;
            
            case GameState::CharacterCreator:
                characterCreator.draw();
                break;
        }
        SDL_RenderPresent(renderer);
    }
}

void Game::handleInput(SDL_Event& event)
{
    switch (currentState){
        case GameState::MainMenu:
            mainMenu.handleInput(event);
            break;

        case GameState::Settings:
            settings.handleInput(event);
            break;

        case GameState::CharacterCreator:
            characterCreator.handleInput(event);
            break;

        /* Example of Future implementation
            case GameState::Battle:
            battle.handleInput(event);
            break;
        */
    }
}