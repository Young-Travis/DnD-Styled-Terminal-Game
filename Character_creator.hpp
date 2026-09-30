#ifndef CHARACTER_CREATOR_HPP
#define CHARACTER_CREATOR_HPP
#include <iostream>
#include "Character.hpp"
#include "Character_class.hpp"
#include "general_utility.hpp"
using namespace std;


void assignClass(string name){
    int response;
    Character player(name);
    Character_class player_class;
    cout << "What class will " << name << " be?" << endl;
    cout << "1: Barbarian\n2: Wizard\n3: Cleric\n4: Fighter\n5: Rogue" << endl;
    do{
                response = getInt();
        switch (response){
            case 1:
                player_class = Barbarian();
                break;
            case 2:
                player_class = Wizard();
                break;
            case 3:
                player_class = Cleric();
                break;
            case 4:
                player_class = Fighter();
                break;
            case 5:
                player_class = Rogue();
                break;
            default:
                cout << "Invalid choice. Please enter a number in the list: ";
                continue;
        }
        break;
    }
    while (true);
    player.assignClass(player_class);
    waitForEnter();
    clearTerminal(1000);
}


#endif