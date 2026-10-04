#ifndef SPRITE_HPP
#define SPRITE_HPP

#include <SDL3/SDL.h>
#include <string>

using namespace std;

class Sprite{
public:
    SDL_Renderer* renderer;
    SDL_Texture* texture;

    float x;
    float y;

    float width = 16;
    float height = 16;

    Sprite(SDL_Renderer* renderer);
    ~Sprite();

    bool load(const string& path);

    void setPosition(float x, float y);

    void setSize(float width, float height);

    void draw();
};

#endif