#ifndef MAIN_MENU_HPP
#define MAIN_MENU_HPP

#include <SDL3/SDL.h>

class MainMenu{
public:
    int selected = 0;

    MainMenu(SDL_Renderer* r);

    void handleInput(SDL_Event& event);

    void update();

    void draw();

private:
    SDL_Renderer* renderer;
};

#endif