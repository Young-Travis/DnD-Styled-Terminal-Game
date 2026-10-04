#include <iostream>
#include <SDL3/SDL.h>
#include <SDL3_image/SDL_image.h>

#include "hpp/Sprite.hpp"

using namespace std;

Sprite::Sprite(SDL_Renderer* renderer)
{
    this->renderer = renderer;

    texture = nullptr;

    x = 0;
    y = 0;
}

Sprite::~Sprite()
{
    if (texture != nullptr)
    {
        SDL_DestroyTexture(texture);
    }
}

bool Sprite::load(const string& path)
{
    SDL_Surface* surface = IMG_Load(path.c_str());
    if (surface == nullptr)
    {
        cout << "Failed to load sprite: "
             << SDL_GetError() << endl;

        return false;
    }
    texture = SDL_CreateTextureFromSurface(renderer, surface);

    if (texture == nullptr)
    {
        SDL_DestroySurface(surface);

        cout << "Failed to create sprite texture: "
            << SDL_GetError()
            << endl;

        return false;
    }

    SDL_SetTextureScaleMode(
        texture,
        SDL_SCALEMODE_NEAREST
    );

    SDL_DestroySurface(surface);
    
    return true;
}

void Sprite::setPosition(float x, float y)
{
    this->x = x;
    this->y = y;
}

void Sprite::setSize(float width, float height){
    this->width = width;
    this->height = height;
}

void Sprite::draw()
{
    if (texture == nullptr)
    {
        return;
    }
    SDL_FRect destination = {x, y, width, height};
    SDL_RenderTexture(renderer, texture, nullptr, &destination);
}