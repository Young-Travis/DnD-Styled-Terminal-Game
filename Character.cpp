#include "hpp/Character.hpp"
#include "hpp/npc.hpp"
#include "hpp/Character_class.hpp"

using namespace std;

Character::Character(string name){
    char_name = name;
    //createStats();
    //printStats();
}


void Character::printName(){
    cout << char_name << endl;
}

void Character::printStats(){
    for (int i = 0; i < stats.size(); i++){
        cout << char_name << "'s " << stat_names[i] << ": " << stats[i] << endl;
    }
}

void Character::addStat(int stat, int amount){
    stats[stat] += amount;
}

void Character::createStats(){
    for (int i = 0; i < stats.size(); i++){
        cout << "Enter a value for " << char_name << "'s " << stat_names[i] << ": ";
        cin >> stats[i];
    }
}

void Character::onTakeDamage(int damage){
    current_hp -= damage;
    if (current_hp <= 0){
        current_hp = 0;
        onDead();
    }
    else{
        cout << char_name << " took " << damage << " damage" << endl;
    }
}

void Character::printHealth(){
    cout << char_name << " Health: " << current_hp << "/" << max_hp << endl;
}

void Character::onDead(){
    cout << char_name << " has died!";
}

void Character::onDealDamage(npc target, int damage){
    target.onTakeDamage(damage);
}

void Character::assignClass(Character_class c_class){
    char_class = c_class;
    cout << char_name << " has become a " << char_class.class_name << endl;

    stats = char_class.base_stats;
    printStats();
}