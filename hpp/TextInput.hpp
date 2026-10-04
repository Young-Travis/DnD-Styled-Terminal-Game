#ifndef TEXTINPUT_HPP
#define TEXTINPUT_HPP

#include <SDL3/SDL.h>
#include <string>
#include "TextHandler.hpp"

using namespace std;

class TextInput{
public:
    SDL_Renderer* renderer;
    TextHandler textHandler;
    
    string text;

    float x;
    float y;

    int maxLength = 16;

    TextInput(SDL_Renderer* r, float x, float y);

    void handleInput(SDL_Event& event);

    void update();

    void draw();

    string getText();
};

#endif