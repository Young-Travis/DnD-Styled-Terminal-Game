#ifndef WEAPON_HPP
#define WEAPON_HPP

#include <string>
#include "Item.hpp"

class Weapon : public Item{
public:
    string weapon_type;
    int num_of_rolls;
    int max_of_each_dice;

    Weapon(){
        equippable = true;
    }

    void printStats();
};

class Battleaxe : public Weapon{
public:
    Battleaxe(){
        item_name = "Battleaxe";
        weapon_type = "martial";
        item_weight = 4.0f;
        buy_price = 10;

        num_of_rolls = 1;
        max_of_each_dice = 8;
    }
};

#endif