#include <iostream>
#include <optional>
#include <SDL3/SDL.h>
#include "hpp/GameState.hpp"
#include "hpp/MainMenu.hpp"
#include "hpp/TextHandler.hpp"
#include "hpp/ChoiceMenu.hpp"

using namespace std;

MainMenu::MainMenu(SDL_Renderer* r) : text(r), choices(r, &text, 50, 50){
    renderer = r;
    text.setText("Welcome to the game!", 0, 0);
    choices.setChoices(
        {"New Game",
        "Load Game",
        "Settings",
        "Quit"}
    );
}

void MainMenu::handleInput(SDL_Event& event){
    choices.handleInput(event);
    if (event.type == SDL_EVENT_KEY_DOWN)
    {
        if (event.key.key == SDLK_RETURN)
        {
            cout << "Enter pressed" << endl;
            switch (choices.getSelected()){
                case 0:
                    cout << "New Game Selected" << endl;
                    requestedState = GameState::CharacterCreator;
                    break;
                case 1:
                    cout << "Load Game Selected" << endl;
                    break;
                case 2:
                    cout << "Settings Selected" << endl;
                    requestedState = GameState::Settings;
                    break;
                case 3:
                    cout << "Quit Selected" << endl;
                    requestedState = GameState::Quit;
                    break;
            }
        }
    }
}

void MainMenu::update(){
    text.update();
    //cout << "Test Update" << endl;
}

void MainMenu::draw(){
    //text.draw(string, x, y)
    text.draw();
    choices.draw();
}

std::optional<GameState> MainMenu::getRequestedState()
{
    std::optional<GameState> requested = requestedState;

    requestedState.reset();

    return requested;
}