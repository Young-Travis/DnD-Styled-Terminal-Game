#ifndef TEXT_HANDLER_HPP
#define TEXT_HANDLER_HPP

#include <SDL3/SDL.h>
#include <SDL3_ttf/SDL_ttf.h>
#include <string>

using namespace std;

class TextHandler {

private:

    SDL_Renderer* renderer;
    TTF_Font* font;

    string current_text;

    float x;
    float y;

    int characters_to_show;

    Uint64 last_character_time;

    int character_delay;

    void drawLine(
        const string& text,
        float x,
        float y
    );

public:

    TextHandler(SDL_Renderer* renderer);

    ~TextHandler();

    int getTextWidth(const string& text);

    void setText(const string& text);

    void setPosition(float x, float y);

    void draw();

    void drawInstant(const string& text, float x, float y);

    void update();

};

#endif