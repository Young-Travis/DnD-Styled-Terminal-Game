#include <iostream>
#include "hpp/Weapon.hpp"

using namespace std;


void Weapon::printStats(){
    cout << "Weapon Name: " << item_name << endl;
    cout << "Weapon Type: " << weapon_type << endl;
    cout << "Weapon Damage: " << num_of_rolls << "d" << max_of_each_dice << endl;
}