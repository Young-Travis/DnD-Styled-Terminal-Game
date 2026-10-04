#include <iostream>
#include <optional>
#include "hpp/GameState.hpp"
#include "hpp/Settings.hpp"
#include "hpp/TextHandler.hpp"
#include "hpp/ChoiceMenu.hpp"

using namespace std;

Settings::Settings(SDL_Renderer* r) 
: renderer(r), text(r), choices(r, &text){
    text.setText("Welcome to the settings!", 0, 0);
    choices.setChoices({"Text Speed", "Difficulty", "EXIT"}, 50, 50);
}

void Settings::handleInput(SDL_Event& event){
    choices.handleInput(event);
    if (event.type == SDL_EVENT_KEY_DOWN)
    {
        if (event.key.key == SDLK_RETURN)
        {
            cout << "Enter pressed" << endl;
            switch (choices.getSelected()){
                case 0:
                    cout << "Text Speed Selected" << endl;
                    break;
                case 1:
                    cout << "Difficulty Selected" << endl;
                    break;
                case 2:
                    cout << "Back to Main Menu Selected" << endl;
                    requestedState = GameState::MainMenu;
                    break;
            }
        }
    }
}

void Settings::update(){
    text.update();
}

void Settings::draw(){
    text.draw();
    choices.draw();
}

std::optional<GameState> Settings::getRequestedState()
{
    std::optional<GameState> requested = requestedState;

    requestedState.reset();

    return requested;
}