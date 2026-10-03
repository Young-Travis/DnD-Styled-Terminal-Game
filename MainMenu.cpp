#include <iostream>
#include <SDL3/SDL.h>
#include "hpp/MainMenu.hpp"
#include "hpp/CharacterCreator.hpp"
#include "hpp/general_utility.hpp"

using namespace std;

MainMenu::MainMenu(SDL_Renderer* r){
    renderer = r;
    cout << "Main Menu Called" << endl;
}

void MainMenu::handleInput(SDL_Event& event){
    if (event.type == SDL_EVENT_KEY_DOWN)
    {
        if (event.key.key == SDLK_UP)
        {
            selected--;
        }

        if (event.key.key == SDLK_DOWN)
        {
            selected++;
        }

        if (event.key.key == SDLK_RETURN)
        {
            cout << "Enter pressed" << endl;
        }
    }
}