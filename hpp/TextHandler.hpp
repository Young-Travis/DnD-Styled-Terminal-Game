#ifndef TEXT_HANDLER_HPP
#define TEXT_HANDLER_HPP

#include <SDL3/SDL.h>
#include <SDL3_ttf/SDL_ttf.h>
#include <string>

class TextHandler {

private:

    SDL_Renderer* renderer;
    TTF_Font* font;

    std::string current_text;

    float text_x;
    float text_y;

    int characters_to_show;

    Uint64 last_character_time;

    int character_delay;

    void drawLine(
        const std::string& text,
        float x,
        float y
    );

public:

    TextHandler(SDL_Renderer* renderer);

    ~TextHandler();

    void setText(const std::string& text, float x, float y);

    void draw();

    void drawInstant(const std::string& text, float x, float y);

    void update();

};

#endif