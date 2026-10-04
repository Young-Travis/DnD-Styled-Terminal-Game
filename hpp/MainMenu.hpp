#ifndef MAIN_MENU_HPP
#define MAIN_MENU_HPP

#include <SDL3/SDL.h>
#include "TextHandler.hpp"
#include "ChoiceMenu.hpp"

class MainMenu{
public:
    int selected = 0;
    bool quit = false;
    TextHandler text;
    ChoiceMenu choices;

    MainMenu(SDL_Renderer* r);

    void handleInput(SDL_Event& event);

    void update();

    void draw();

private:
    SDL_Renderer* renderer;
};

#endif