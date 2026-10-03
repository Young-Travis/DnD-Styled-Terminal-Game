#ifndef CHARACTER_CREATOR_HPP
#define CHARACTER_CREATOR_HPP

#include <SDL3/SDL.h>
#include "Character.hpp"

class CharacterCreator{
public:
    int selected = 0;

    CharacterCreator(SDL_Renderer* r);

    void handleInput(SDL_Event& event);

    void askForName();

    void addToStats(Character& player, int amount);

    void assignClass(string name);

private:
    SDL_Renderer* renderer;
};

#endif