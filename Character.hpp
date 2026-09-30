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
    int max_hp = 100;
    int current_hp = max_hp;
    Character_class char_class;
    vector<int> stats = {0,0,0,0,0,0};
    vector<int> modifiers = {0,0,0,0,0,0};
    vector<string> stat_names = {"Constitution", "Dexterity", "Strength", "Intelligence", "Wisdom", "Charisma"};

    Character(string name){
        char_name = name;
        //createStats();
        //printStats();
    }

    void printName(){
        cout << char_name << endl;
    }

    void printStats(){
        for (int i = 0; i < stats.size(); i++){
            cout << char_name << "'s " << stat_names[i] << ": " << stats[i] << endl;
        }
    }

    void assignClass(Character_class c_class);

    void createStats(){
        for (int i = 0; i < stats.size(); i++){
            cout << "Enter a value for " << char_name << "'s " << stat_names[i] << ": ";
            cin >> stats[i];
        }
    }

    void onTakeDamage(int damage){
        current_hp -= damage;
        if (current_hp <= 0){
            current_hp = 0;
            onDead();
        }
        else{
            cout << char_name << " took " << damage << " damage" << endl;
        }
    }

    void onDealDamage(npc target, int damage);

    void printHealth(){
        cout << char_name << " Health: " << current_hp << "/" << max_hp << endl;
    }

    void onDead(){
        cout << char_name << " has died!";
    }

};

#endif