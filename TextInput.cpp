#include <iostream>
#include <string>
#include <SDL3/SDL.h>
#include "hpp/TextInput.hpp"
#include "hpp/TextHandler.hpp"

using namespace std;

TextInput::TextInput(SDL_Renderer* r, float x_pos, float y_pos): renderer(r), textHandler(r){
    x = x_pos;
    y = y_pos;
}

void TextInput::update(){

}

void TextInput::draw(){
    textHandler.drawInstant(text, x, y);
}

void TextInput::handleInput(SDL_Event& event){
    cout << "Event Received: " << event.type << endl;
 
    if (event.type == SDL_EVENT_TEXT_INPUT && text.size() < maxLength){
        cout << "Text input: " << event.text.text << endl;
        text += event.text.text;
    }
    
    if (event.type == SDL_EVENT_KEY_DOWN){
        if (event.key.key == SDLK_BACKSPACE){
            if (!text.empty()){
                text.pop_back();
            }
        }
        if (event.key.key == SDLK_RETURN){
            cout << "Finished typing name" << endl;
        }
    }
}