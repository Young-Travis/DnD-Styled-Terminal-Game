#include <iostream>
#include <string>
#include "hpp/CharacterCreator.hpp"
#include "hpp/CharacterClass.hpp"
#include "hpp/general_utility.hpp"

using namespace std;

CharacterCreator::CharacterCreator(SDL_Renderer* r) : renderer(r), text(r), choices(r, &text), textInput(r, 200, 200){
    text.setText("Welcome to the world!\nThis is where you start your adventure.\nNow tell me,\nwhat is your name?", 0, 0);
}

void CharacterCreator::handleInput(SDL_Event& event){
    switch (currentStep){
        case CreatorStep::Name:
            textInput.handleInput(event);
            if (event.type == SDL_EVENT_KEY_DOWN)
            {
                if (event.key.key == SDLK_RETURN)
                {
                    currentStep = CreatorStep::VerifyName;
                    name = textInput.getText();
                    verifyName();
                }
            }
            break;
        case CreatorStep::VerifyName:
            choices.handleInput(event);
            if (event.type == SDL_EVENT_KEY_DOWN && event.key.key == SDLK_RETURN){
                if (choices.getSelected() == 0){
                    currentStep = CreatorStep::ChooseClass;
                    chooseClass();
                }
                if (choices.getSelected() == 1){
                    currentStep = CreatorStep::Name;
                    textInput.reset();
                    choosingName();
                }
            }
            break;

        case CreatorStep::ChooseClass:
            choices.handleInput(event);
            if (event.type == SDL_EVENT_KEY_DOWN && event.key.key == SDLK_RETURN){
                //class selected
            }
            break;
    }
}

void CharacterCreator::choosingName(){
    text.setText("What is your name?", 0, 0);
}

void CharacterCreator::verifyName(){
    text.setText("So your name is " + name + "?", 0, 0);
    choices.setChoices({"Yes", "No"}, 200, 200);
}

void CharacterCreator::chooseClass(){
    text.setText("What class is " + name + "?", 0, 0);
    choices.setChoices({"Barbarian", "Wizard", "Cleric", "Fighter", "Rogue"}, 200, 200);
}

void CharacterCreator::update(){
    switch (currentStep){
        case CreatorStep::Name:
            text.update();
            textInput.update();
            break;
        case CreatorStep::VerifyName:
            text.update();
            break;
        case CreatorStep::ChooseClass:
            text.update();
            break;
    }

}

void CharacterCreator::draw(){
    switch (currentStep){
        case CreatorStep::Name:
            text.draw();
            textInput.draw();
            break;
        case CreatorStep::VerifyName:
            choices.draw();
            text.draw();
            break;
        case CreatorStep::ChooseClass:
            choices.draw();
            text.draw();
            break;
    }
}

