#ifndef ARMOR_HPP
#define ARMOR_HPP

#include <string>
#include "Item.hpp"

using namespace std;

class Armor : public Item{
public:
    int base_ac = 0;
    string armor_type = "";
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
        item_name = "Leather Armor";
        armor_type = "Light";
        base_ac = 11;
        buy_price = 10;
        item_weight = 10;
    }
};

class PaddedArmor : public Armor{
public:
    PaddedArmor(){
        item_name = "Padded Armor";
        armor_type = "Light";
        base_ac = 11;
        buy_price = 5;
        item_weight = 8;
    }
};

class StuddedLeatherArmor : public Armor{
public:
    StuddedLeatherArmor(){
        item_name = "Studded Leather Armor";
        armor_type = "Light";
        base_ac = 12;
        buy_price = 45;
        item_weight = 13;
    }
};

class HideArmor : public Armor{
public:
    HideArmor(){
        item_name = "Hide Armor";
        armor_type = "Medium";
        base_ac = 12;
        buy_price = 10;
        item_weight = 12;
    }
};

class ChainShirtArmor : public Armor{
public:
    ChainShirtArmor(){
        item_name = "Chain Shirt Armor";
        armor_type = "Medium";
        base_ac = 13;
        buy_price = 50;
        item_weight = 20;
    }
};

#endif