#include <iostream>
#include <string>
#include <SDL3/SDL.h>
#include "hpp/TextInput.hpp"
#include "hpp/TextHandler.hpp"

using namespace std;

TextInput::TextInput(SDL_Renderer* r): renderer(r), textHandler(r){
    x = 0;
    y = 0;
}

void TextInput::update(){

}

void TextInput::setPosition(float x, float y){
    this->x = x;
    this->y = y;
}

void TextInput::draw(){
    textHandler.drawInstant(text, x, y);
}

void TextInput::handleInput(SDL_Event& event){
    if (event.type == SDL_EVENT_TEXT_INPUT && text.size() < maxLength){
        text += event.text.text;
    }
    
    if (event.type == SDL_EVENT_KEY_DOWN){
        if (event.key.key == SDLK_BACKSPACE){
            if (!text.empty()){
                text.pop_back();
            }
        }
    }
}

void TextInput::reset(){
    text = "";
}

string TextInput::getText(){
    return text;
}