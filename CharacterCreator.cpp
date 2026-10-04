#include <iostream>
#include <string>
#include "hpp/CharacterCreator.hpp"
#include "hpp/CharacterClass.hpp"
#include "hpp/general_utility.hpp"

using namespace std;

CharacterCreator::CharacterCreator(SDL_Renderer* r) : renderer(r), text(r), choices(r, &text), textInput(r), wizardImage(r){
    text.setText("Welcome to the world!\nThis is where you start your adventure.\nNow tell me,\nwhat is your name?");
    wizardImage.load("Assets/Francis_Wizard.png");
    textInput.setPosition(40, 40);
    wizardImage.setPosition(80, 40);
    wizardImage.setSize(64, 64);
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
                    chooseName();
                }
            }
            break;

        case CreatorStep::ChooseClass:
            choices.handleInput(event);
            if (event.type == SDL_EVENT_KEY_DOWN && event.key.key == SDLK_RETURN){
                //class selected
                switch (choices.getSelected())
                {
                    case 0:{
                        Barbarian c;
                        playerClass = c;
                        break;
                    }
                    case 1:{
                        Wizard c;
                        playerClass = c;
                        break;
                    }
                    case 2:{
                        Cleric c;
                        playerClass = c;
                        break;
                    }
                    case 3:{
                        Fighter c;
                        playerClass = c;
                        break;
                    }
                    case 4:{
                        Rogue c;
                        playerClass = c;
                        break;
                    }
                }
                currentStep = CreatorStep::VerifyClass;
                verifyClass();
            }
            break;
        
        case CreatorStep::VerifyClass:
            choices.handleInput(event);
            if (event.type == SDL_EVENT_KEY_DOWN && event.key.key == SDLK_RETURN){
                if (choices.getSelected() == 0){
                    currentStep = CreatorStep::Finished;
                    cout << "Finished" << endl;
                }
                if (choices.getSelected() == 1){
                    currentStep = CreatorStep::ChooseClass;
                    textInput.reset();
                    chooseClass();
                }
            }
            break;
    }
}

void CharacterCreator::chooseName(){
    text.setText("What is your name?");
}

void CharacterCreator::verifyName(){
    text.setText("So your name is " + name + "?");
    choices.setPosition(40, 55);
    choices.setChoices({"Yes", "No"});
}

void CharacterCreator::chooseClass(){
    text.setText("What class is " + name + "?");
    choices.setPosition(35,35);
    choices.setChoices({"Barbarian", "Wizard", "Cleric", "Fighter", "Rogue"});
}

void CharacterCreator::verifyClass(){
    text.setText("So " + name + " is a " + playerClass.className + "?");
    choices.setPosition(40,55);
    choices.setChoices({"Yes", "No"});
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
        case CreatorStep::VerifyClass:
            text.update();
    }
}

void CharacterCreator::draw(){
    wizardImage.draw();

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
        case CreatorStep::VerifyClass:
            choices.draw();
            text.draw();
    }
}

