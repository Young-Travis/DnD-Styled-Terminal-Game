#include "hpp/npc.hpp"
#include "hpp/Character.hpp"

void npc::onTakeDamage(int damage){
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

void npc::printHealth(){
    cout << npc_name << " Health: " << current_hp << "/" << max_hp << endl;
}

void npc::onDead(){
    cout << npc_name << " has died!" << endl;
}

void npc::onDealDamage(Character target, int damage){
    target.onTakeDamage(damage);
}