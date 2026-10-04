#ifndef CHOICE_MENU_HPP
#define CHOICE_MENU_HPP

#include <SDL3/SDL.h>
#include <string>
#include <vector>

class TextHandler;

class ChoiceMenu {

private:
    SDL_Renderer* renderer;
    TextHandler* text;

    std::vector<std::string> choices;

    int selected;

    float x;
    float y;

public:

    ChoiceMenu(SDL_Renderer* renderer, TextHandler* text);

    void setChoices(const std::vector<std::string>& choices, float x, float y);

    void handleInput(const SDL_Event& event);

    void draw();

    int getSelected();

};

#endif