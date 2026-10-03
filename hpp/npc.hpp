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

    void onTakeDamage(int damage);

    void onDealDamage(Character target, int damage);

    void printHealth();

    void onDead();

};

class Goblin : public npc{
public:
    Goblin(){
        npc_name = "Goblin";
    }
};

#endif