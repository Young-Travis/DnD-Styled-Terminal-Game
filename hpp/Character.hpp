#ifndef CHARACTER_HPP
#define CHARACTER_HPP

#include <iostream>
#include <string>
#include <vector>
#include "CharacterClass.hpp"
#include "Weapon.hpp"
#include "Armor.hpp"

using namespace std;

class npc;

class Character{
public:
    string charName;
    CharacterClass charClass;
    Armor* equipArmor = nullptr;
    Weapon* equipWeapon = nullptr;
    int armorClass;
    int maxHp = 100;
    int currentHp = maxHp;
    vector<int> stats = {0,0,0,0,0,0};
    vector<int> modifiers = {0,0,0,0,0,0};
    vector<string> statNames = {"Constitution", "Dexterity", "Strength", "Intelligence", "Wisdom", "Charisma"};

    Character(string name);

    void printName();

    void printStats();

    void printModifiers();

    void printEquipped();

    void addStat(int stat, int amount);

    void createStats();

    void calculateModifiers();

    void onTakeDamage(int damage);

    void printHealth();

    void onDead();

    void calculateArmorClass();

    //prototypes that require other classes go here
    void assignClass(CharacterClass cClass);
    void onDealDamage(npc target, int damage);
    void equipItem(Item& item);

};

#endif