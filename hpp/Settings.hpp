#ifndef SETTINGS_HPP
#define SETTINGS_HPP

#include <optional>
#include "GameState.hpp"
#include "TextHandler.hpp"
#include "ChoiceMenu.hpp"


using namespace std;

class Settings{
public:
    TextHandler text;
    ChoiceMenu choices;
    optional<GameState> requestedState;

    Settings(SDL_Renderer* r);

    void handleInput(SDL_Event& event);
    void update();
    void draw();
    optional<GameState> getRequestedState();

private:
    SDL_Renderer* renderer;
};

#endif