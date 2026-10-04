#include <iostream>
#include <string>
#include "hpp/CharacterCreator.hpp"
#include "hpp/CharacterClass.hpp"
#include "hpp/general_utility.hpp"

using namespace std;

CharacterCreator::CharacterCreator(SDL_Renderer* r) : renderer(r), text(r), choices(r, &text, 50, 50), textInput(r, 200, 200){
    text.setText("Welcome to the world!\nThis is where you start your adventure.\nNow tell me,\nwhat is your name?", 0, 0);
}

void CharacterCreator::handleInput(SDL_Event& event){
    textInput.handleInput(event);
    if (event.type == SDL_EVENT_KEY_DOWN)
    {
        if (event.key.key == SDLK_RETURN)
        {
            cout << "Enter pressed" << endl;
        }
    }
}

void CharacterCreator::update(){
    text.update();
    textInput.update();
}

void CharacterCreator::draw(){
    text.draw();
    textInput.draw();
}