#include "hpp/Character.hpp"
#include "hpp/npc.hpp"
#include "hpp/CharacterClass.hpp"
#include "hpp/Item.hpp"

using namespace std;

Character::Character(string name){
    charName = name;
    //createStats();
    //printStats();
}

void Character::printName(){
    cout << charName << endl;
}

void Character::printStats(){
    for (int i = 0; i < stats.size(); i++){
        cout << charName << "'s " << statNames[i] << ": " << stats[i] << endl;
    }
    cout << "Armor Class: " << armorClass << endl;
}

void Character::printModifiers(){
    for (int i = 0; i < stats.size(); i++){
        cout << charName << "'s " << statNames[i] << " modifier: " << modifiers[i] << endl;
    }
}

void Character::printEquipped(){
    if (equipArmor == nullptr){
        cout << charName << " has no armor equipped." << endl;
    }
    else{
        cout << charName << " has " << equipArmor->itemName << " equipped." << endl;
    }
    if (equipWeapon == nullptr){
        cout << charName << " has no weapon equipped." << endl;
    }
    else{
        cout << charName << " has " << equipWeapon->itemName << " equipped." << endl;
    }
}

void Character::addStat(int stat, int amount){
    stats[stat] += amount;
}

void Character::createStats(){
    for (int i = 0; i < stats.size(); i++){
        cout << "Enter a value for " << charName << "'s " << statNames[i] << ": ";
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
    currentHp -= damage;
    if (currentHp <= 0){
        currentHp = 0;
        onDead();
    }
    else{
        cout << charName << " took " << damage << " damage" << endl;
    }
}

void Character::printHealth(){
    cout << charName << " Health: " << currentHp << "/" << maxHp << endl;
}

void Character::onDead(){
    cout << charName << " has died!";
}

void Character::calculateArmorClass(){
    if (equipArmor == nullptr){
        //cout << char_name << " has no armor equipped." << endl;
        armorClass = 10 + (modifiers[1]);
    }
    else{
        int tempMod = modifiers[1];
        //cout << char_name << " has " << equip_armor->item_name << " equipped." << endl;
        if (equipArmor->armorType == "Light"){
            armorClass = equipArmor->baseAc + tempMod;
        }
        else if (equipArmor->armorType == "Medium"){
            if (tempMod > 2){
                tempMod = 2;
            }
            armorClass = equipArmor->baseAc + tempMod;
        }
        else{
            armorClass = equipArmor->baseAc;
        }
    }
}

void Character::onDealDamage(npc target, int damage){
    target.onTakeDamage(damage);
}

void Character::assignClass(CharacterClass cClass){
    charClass = cClass;
    cout << charName << " has become a " << charClass.className << endl;

    stats = charClass.baseStats;
    printStats();
}

void Character::equipItem(Item& item){
    if (!item.equippable){
        cout << "Item is not equippable. Try another item." << endl;
    }
    else{
        if (Armor* armor = dynamic_cast<Armor*>(&item)) {
            equipArmor = armor;
            calculateArmorClass();
        }
        else if (Weapon* weapon = dynamic_cast<Weapon*>(&item)) {
            equipWeapon = weapon;
        }
        cout << charName << " has equipped their " << item.itemName << "." << endl;
    }
}