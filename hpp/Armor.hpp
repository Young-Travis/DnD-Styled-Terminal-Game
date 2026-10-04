#ifndef ARMOR_HPP
#define ARMOR_HPP

#include <string>
#include "Item.hpp"

using namespace std;

class Armor : public Item{
public:
    int baseAc = 0;
    string armorType = "";
    bool equipped = false;

    Armor(){
        equippable = true;
    }

    void onEquipped();

    void onUnequipped();
};

class LeatherArmor : public Armor{
public:
    LeatherArmor(){
        itemName = "Leather Armor";
        armorType = "Light";
        baseAc = 11;
        buyPrice = 10;
        itemWeight = 10;
    }
};

class PaddedArmor : public Armor{
public:
    PaddedArmor(){
        itemName = "Padded Armor";
        armorType = "Light";
        baseAc = 11;
        buyPrice = 5;
        itemWeight = 8;
    }
};

class StuddedLeatherArmor : public Armor{
public:
    StuddedLeatherArmor(){
        itemName = "Studded Leather Armor";
        armorType = "Light";
        baseAc = 12;
        buyPrice = 45;
        itemWeight = 13;
    }
};

class HideArmor : public Armor{
public:
    HideArmor(){
        itemName = "Hide Armor";
        armorType = "Medium";
        baseAc = 12;
        buyPrice = 10;
        itemWeight = 12;
    }
};

class ChainShirtArmor : public Armor{
public:
    ChainShirtArmor(){
        itemName = "Chain Shirt Armor";
        armorType = "Medium";
        baseAc = 13;
        buyPrice = 50;
        itemWeight = 20;
    }
};

#endif