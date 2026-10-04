#include <iostream>
#include "hpp/Weapon.hpp"

using namespace std;

void Weapon::printStats(){
    cout << "Weapon Name: " << itemName << endl;
    cout << "Weapon Type: " << weaponType << endl;
    cout << "Weapon Damage: " << numOfRolls << "d" << maxOfEachDice << endl;
}