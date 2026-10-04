#include "hpp/TextHandler.hpp"
#include <iostream>

TextHandler::TextHandler(SDL_Renderer* renderer){
    this->renderer = renderer;

    if (!TTF_Init()){
        std::cout << "TTF_Init failed: "
                  << SDL_GetError()
                  << std::endl;

        font = nullptr;
        return;
    }

    std::cout << "SDL_ttf initialized successfully."
              << std::endl;

    font = TTF_OpenFont(
        "font.ttf",
        32
    );

    if (font == nullptr){
        std::cout << "TTF_OpenFont failed: "
                  << SDL_GetError()
                  << std::endl;
    }
    else {
        std::cout << "Font loaded successfully."
                  << std::endl;
    }

    current_text = "";

    text_x = 0;
    text_y = 0;

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

void TextHandler::setText(const std::string& text, float x, float y){
    if (font == nullptr){
        return;
    }

    current_text = text;

    text_x = x;
    text_y = y;

    characters_to_show = 0;

    last_character_time = SDL_GetTicks();
}

void TextHandler::update(){
    if (font == nullptr){
        return;
    }

    Uint64 current_time = SDL_GetTicks();

    if (
        characters_to_show < current_text.length()
        &&
        current_time - last_character_time >= character_delay
    ){
        characters_to_show++;

        last_character_time = current_time;
    }
}

void TextHandler::drawLine(const std::string& text, float x, float y){
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
        TTF_RenderText_Blended(
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

void TextHandler::drawInstant(const std::string& text, float x, float y){
    if (font == nullptr){
        return;
    }

    drawLine(text, x, y);
}

void TextHandler::draw(){
    if (font == nullptr){
        return;
    }

    std::string visible_text =
        current_text.substr(
            0,
            characters_to_show
        );

    float current_y = text_y;

    std::string current_line;

    for (char character : visible_text){

        if (character == '\n'){

            drawLine(
                current_line,
                text_x,
                current_y
            );

            current_line = "";

            current_y += 40;
        }
        else {

            current_line += character;
        }
    }

    drawLine(
        current_line,
        text_x,
        current_y
    );
}