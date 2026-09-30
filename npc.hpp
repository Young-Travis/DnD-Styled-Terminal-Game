#ifndef NPC_HPP
#define NPC_HPP
#include <string>
#include <iostream>

using namespace std;

class Character;

class npc{
public:
    int max_hp = 100;
    int current_hp = max_hp;
    string npc_name;

    void onTakeDamage(int damage){
        current_hp -= damage;
        if (current_hp <= 0){
            current_hp = 0;
            onDead();
        }
        else{
            cout << npc_name << " Took " << damage << " damage!" << endl;
            printHealth();
        }
    }

    void onDealDamage(Character target, int damage);

    void printHealth(){
        cout << npc_name << " Health: " << current_hp << "/" << max_hp << endl;
    }

    void onDead(){
        cout << npc_name << " has died!" << endl;
    }

};

class Goblin : public npc{
public:
    Goblin(){
        npc_name = "Goblin";
    }
};

#endif