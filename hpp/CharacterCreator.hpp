#ifndef CHARACTER_CREATOR_HPP
#define CHARACTER_CREATOR_HPP

#include <SDL3/SDL.h>
#include "GameState.hpp"
#include "Character.hpp"
#include "ChoiceMenu.hpp"
#include "TextHandler.hpp"
#include "TextInput.hpp"

enum class CreatorStep{
    Name,
    VerifyName,
    ChooseClass,
    VerifyClass,
    Finished
};

class CharacterCreator{
public:
    CreatorStep currentStep = CreatorStep::Name;
    ChoiceMenu choices;
    TextHandler text;
    TextInput textInput;

    //character stuff
    string name;
    CharacterClass playerClass;

    GameState requestedState;

    CharacterCreator(SDL_Renderer* r);

    void handleInput(SDL_Event& event);

    void update();

    void draw();

    void chooseName();

    void verifyName();

    void chooseClass();

    void verifyClass();

private:
    SDL_Renderer* renderer;
};

#endif