#include <iostream>
#include <vector>
#include <string>
#include "Character.hpp"
#include "npc.hpp"
#include "Character_class.hpp"
#include "Character_creator.hpp"

using namespace std;

int main(void){
    string response;
    cout << "What is your name? ";
    cin >> response;

    assignClass(response);

    //Goblin enemy;
    //p1.onDealDamage(enemy, 50);
}