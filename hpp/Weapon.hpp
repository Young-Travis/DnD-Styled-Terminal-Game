#ifndef WEAPON_HPP
#define WEAPON_HPP

#include <string>
#include "Item.hpp"

class Weapon : public Item{
public:
    string weaponType;
    int numOfRolls;
    int maxOfEachDice;

    Weapon(){
        equippable = true;
    }

    void printStats();
};

class Battleaxe : public Weapon{
public:
    Battleaxe(){
        itemName = "Battleaxe";
        weaponType = "martial";
        itemWeight = 4.0f;
        buyPrice = 10;

        numOfRolls = 1;
        maxOfEachDice = 8;
    }
};

#endif