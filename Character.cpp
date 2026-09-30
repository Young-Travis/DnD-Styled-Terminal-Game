#include "Character.hpp"
#include "npc.hpp"
#include "Character_class.hpp"

using namespace std;

void Character::onDealDamage(npc target, int damage){
    target.onTakeDamage(damage);
}

void Character::assignClass(Character_class c_class){
    char_class = c_class;
    cout << char_name << " has become a " << char_class.class_name << endl;

    stats = char_class.base_stats;
    printStats();
}