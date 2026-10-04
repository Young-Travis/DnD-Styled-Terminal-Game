#include "hpp/TextHandler.hpp"
#include <iostream>

using namespace std;

TextHandler::TextHandler(SDL_Renderer* renderer){
    this->renderer = renderer;

    if (!TTF_Init()){
        cout << "TTF_Init failed: "
                  << SDL_GetError()
                  << endl;

        font = nullptr;
        return;
    }

    cout << "SDL_ttf initialized successfully." << endl;

    font = TTF_OpenFont("font.ttf", 8);

    if (font == nullptr){
        cout << "TTF_OpenFont failed: " << SDL_GetError() << endl;
    }
    else {
        cout << "Font loaded successfully." << endl;
    }

    current_text = "";

    x = 0;
    y = 0;

    characters_to_show = 0;

    last_character_time = SDL_GetTicks();

    character_delay = 50;
}

TextHandler::~TextHandler(){
    if (font != nullptr){
        TTF_CloseFont(font);
    }

    TTF_Quit();
}

int TextHandler::getTextWidth(const string& text)
{
    if (font == nullptr){
        return 0;
    }

    int width = 0;
    int height = 0;

    if (!TTF_GetStringSize(font, text.c_str(), text.length(), &width, &height)){
        return 0;
    }

    return width;
}

void TextHandler::setText(const string& text){
    if (font == nullptr){
        return;
    }

    current_text = text;

    characters_to_show = 0;

    last_character_time = SDL_GetTicks();
}

void TextHandler::setPosition(float x, float y){
    this->x = x;
    this->y = y;
}

void TextHandler::update(){
    if (font == nullptr){
        return;
    }

    Uint64 current_time = SDL_GetTicks();

    if (characters_to_show < current_text.length() && current_time - last_character_time >= character_delay){
        characters_to_show++;
        last_character_time = current_time;
    }
}

void TextHandler::drawLine(const string& text, float x, float y){
    if (text.empty()){
        return;
    }

    SDL_Color white = {
        255,
        255,
        255,
        255
    };

    SDL_Surface* surface =
        TTF_RenderText_Solid(
            font,
            text.c_str(),
            text.length(),
            white
        );

    if (surface == nullptr){
        return;
    }

    SDL_Texture* texture =
        SDL_CreateTextureFromSurface(
            renderer,
            surface
        );

    if (texture == nullptr){

        SDL_DestroySurface(surface);

        return;
    }

    SDL_SetTextureScaleMode(texture, SDL_SCALEMODE_NEAREST);

    SDL_FRect destination = {
        x,
        y,
        static_cast<float>(surface->w),
        static_cast<float>(surface->h)
    };

    SDL_RenderTexture(
        renderer,
        texture,
        nullptr,
        &destination
    );

    SDL_DestroyTexture(texture);
    SDL_DestroySurface(surface);
}

void TextHandler::drawInstant(const string& text, float x, float y){
    if (font == nullptr){
        return;
    }

    drawLine(text, x, y);
}

void TextHandler::draw(){
    if (font == nullptr){
        return;
    }

    string visible_text =
        current_text.substr(
            0,
            characters_to_show
        );

    float current_y = y;

    string current_line;

    for (char character : visible_text){

        if (character == '\n'){

            drawLine(
                current_line,
                x,
                current_y
            );

            current_line = "";

            current_y += 10;
        }
        else {

            current_line += character;
        }
    }

    drawLine(
        current_line,
        x,
        current_y
    );
}