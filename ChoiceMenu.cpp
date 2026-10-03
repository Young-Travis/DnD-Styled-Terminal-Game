#include "hpp/ChoiceMenu.hpp"
#include "hpp/TextHandler.hpp"

ChoiceMenu::ChoiceMenu(SDL_Renderer* renderer, TextHandler* text, float x, float y){
    this->renderer = renderer;
    this->text = text;

    this->x = x;
    this->y = y;

    selected = 0;
}

void ChoiceMenu::setChoices(const std::vector<std::string>& choices){
    this->choices = choices;

    selected = 0;
}

void ChoiceMenu::handleInput(const SDL_Event& event){
    if (event.type != SDL_EVENT_KEY_DOWN){
        return;
    }

    if (event.key.key == SDLK_UP){

        selected--;

        if (selected < 0){
            selected = choices.size() - 1;
        }
    }

    if (event.key.key == SDLK_DOWN){

        selected++;

        if (selected >= choices.size()){
            selected = 0;
        }
    }
}

void ChoiceMenu::draw()
{
    SDL_SetRenderDrawColor(
        renderer,
        255,
        255,
        255,
        255
    );

    float box_height = 40 + (choices.size() * 40);

    SDL_FRect box = {
        x,
        y,
        200,
        box_height
    };

    SDL_RenderRect(
        renderer,
        &box
    );

    for (int i = 0; i < choices.size(); i++){
        std::string prefix;
        if (i == selected){
            prefix = ": ";
        }
        else {
            prefix = "  ";
        }

        text->drawInstant(
            prefix + choices[i],
            x + 20,
            y + 20 + (i * 40)
        );
    }
}

int ChoiceMenu::getSelected()
{
    return selected;
}