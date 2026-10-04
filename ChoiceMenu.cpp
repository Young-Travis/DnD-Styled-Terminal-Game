#include "hpp/ChoiceMenu.hpp"
#include "hpp/TextHandler.hpp"

ChoiceMenu::ChoiceMenu(SDL_Renderer* renderer, TextHandler* text)
{
    this->renderer = renderer;
    this->text = text;

    selected = 0;
    x = 0;
    y = 0;
}

void ChoiceMenu::setChoices(const std::vector<std::string>& choices){
    this->choices = choices;

    selected = 0;
}

void ChoiceMenu::setPosition(float x, float y){
    this->x = x;
    this->y = y;
}

void ChoiceMenu::handleInput(const SDL_Event& event)
{
    if (event.type != SDL_EVENT_KEY_DOWN)
    {
        return;
    }

    if (event.key.key == SDLK_UP)
    {
        selected--;

        if (selected < 0)
        {
            selected = choices.size() - 1;
        }
    }

    if (event.key.key == SDLK_DOWN)
    {
        selected++;

        if (selected >= choices.size())
        {
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

    float padding = 4;

    float box_width = 0;

    // Find the width of the longest option
    for (int i = 0; i < choices.size(); i++)
    {
        int width = text->getTextWidth(": " + choices[i]);

        if (width > box_width)
        {
            box_width = width;
        }
    }

    // Add equal padding to both sides
    box_width += padding * 2;

    float box_height = 8 + (choices.size() * 12);

    SDL_FRect box = {
        x,
        y,
        box_width,
        box_height
    };

    SDL_RenderRect(
        renderer,
        &box
    );

    for (int i = 0; i < choices.size(); i++)
    {
        std::string prefix;

        if (i == selected)
        {
            prefix = "> ";
        }
        else
        {
            prefix = "  ";
        }

        text->drawInstant(
            prefix + choices[i],
            x + padding,
            y + 4 + (i * 12)
        );
    }
}

int ChoiceMenu::getSelected()
{
    return selected;
}