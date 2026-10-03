#include "hpp/Character.hpp"
#include "hpp/npc.hpp"
#include "hpp/CharacterClass.hpp"
#include "hpp/Item.hpp"

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
    cout << "Armor Class: " << armor_class << endl;
}

void Character::printModifiers(){
    for (int i = 0; i < stats.size(); i++){
        cout << char_name << "'s " << stat_names[i] << " modifier: " << modifiers[i] << endl;
    }
}

void Character::printEquipped(){
    if (equip_armor == nullptr){
        cout << char_name << " has no armor equipped." << endl;
    }
    else{
        cout << char_name << " has " << equip_armor->item_name << " equipped." << endl;
    }
    if (equip_weapon == nullptr){
        cout << char_name << " has no weapon equipped." << endl;
    }
    else{
        cout << char_name << " has " << equip_weapon->item_name << " equipped." << endl;
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
    calculateModifiers();
    calculateArmorClass();
}

void Character::calculateModifiers(){
    for (int i = 0; i < stats.size(); i++){
        modifiers[i] = (stats[i] - 10) / 2;
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

void Character::calculateArmorClass(){
    if (equip_armor == nullptr){
        //cout << char_name << " has no armor equipped." << endl;
        armor_class = 10 + (modifiers[1]);
    }
    else{
        int temp_mod = modifiers[1];
        //cout << char_name << " has " << equip_armor->item_name << " equipped." << endl;
        if (equip_armor->armor_type == "Light"){
            armor_class = equip_armor->base_ac + temp_mod;
        }
        else if (equip_armor->armor_type == "Medium"){
            if (temp_mod > 2){
                temp_mod = 2;
            }
            armor_class = equip_armor->base_ac + temp_mod;
        }
        else{
            armor_class = equip_armor->base_ac;
        }
    }
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

void Character::equipItem(Item& item){
    if (!item.equippable){
        cout << "Item is not equippable. Try another item." << endl;
    }
    else{
        if (Armor* armor = dynamic_cast<Armor*>(&item)) {
            equip_armor = armor;
            calculateArmorClass();
        }
        else if (Weapon* weapon = dynamic_cast<Weapon*>(&item)) {
            equip_weapon = weapon;
        }
        cout << char_name << " has equipped their " << item.item_name << "." << endl;
    }
}