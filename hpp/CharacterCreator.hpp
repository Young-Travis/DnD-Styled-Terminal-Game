#ifndef CHARACTER_CREATOR_HPP
#define CHARACTER_CREATOR_HPP

#include <SDL3/SDL.h>
#include "GameState.hpp"
#include "Character.hpp"
#include "ChoiceMenu.hpp"
#include "TextHandler.hpp"
#include "TextInput.hpp"

class CharacterCreator{
public:
    int selected = 0;
    ChoiceMenu choices;
    TextHandler text;
    TextInput textInput;

    GameState requestedState;

    CharacterCreator(SDL_Renderer* r);

    void handleInput(SDL_Event& event);

    void update();

    void draw();

private:
    SDL_Renderer* renderer;
};

#endif