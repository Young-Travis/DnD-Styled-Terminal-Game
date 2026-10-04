#include <iostream>
#include <SDL3/SDL.h>
#include "hpp/MainMenu.hpp"
#include "hpp/TextHandler.hpp"
#include "hpp/ChoiceMenu.hpp"

using namespace std;

MainMenu::MainMenu(SDL_Renderer* r) : text(r), choices(r, &text, 50, 50){
    renderer = r;
    cout << "Main Menu Called" << endl;
}

void MainMenu::handleInput(SDL_Event& event){
    choices.handleInput(event);
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

void MainMenu::update(){
    cout << "Test Update" << endl;
}

void MainMenu::draw(){
    //text.draw(string, x, y)
    text.drawInstant("Welcome to the game!", 0, 0);
    choices.setChoices(
        {"New Game",
        "Load Game",
        "Settings",
        "Quit"}
    );
    choices.draw();
}