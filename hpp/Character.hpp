#ifndef CHARACTER_HPP
#define CHARACTER_HPP

#include "Character_class.hpp"
#include <iostream>
#include <string>
#include <vector>

using namespace std;

class npc;

class Character{
public:
    string char_name;
    Character_class char_class;
    int armor_class;
    int max_hp = 100;
    int current_hp = max_hp;
    vector<int> stats = {0,0,0,0,0,0};
    vector<int> modifiers = {0,0,0,0,0,0};
    vector<string> stat_names = {"Constitution", "Dexterity", "Strength", "Intelligence", "Wisdom", "Charisma"};

    Character(string name);

    void printName();

    void printStats();

    void addStat(int stat, int amount);

    void createStats();

    void onTakeDamage(int damage);

    void printHealth();

    void onDead();

    void calculateArmorClass();

    //prototypes that require other classes go here
    void assignClass(Character_class c_class);
    void onDealDamage(npc target, int damage);

};

#endif