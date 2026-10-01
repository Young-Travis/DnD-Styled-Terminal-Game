#include <iostream>
#include <string>
#include "Character_creator.hpp"
#include "Character_class.hpp"
#include "general_utility.hpp"

using namespace std;

void askForName(){
    string response;
    while (true){
        cout << "What is your name?" << endl;
        cin >> response;
        cout << "Ah, so your name is " << response << "?" << endl;
        if (getYesNo()){
            break;
        }
    }
    assignClass(response);
}

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
    addToStats(player, 2);
    addToStats(player, 1);
    player.printStats();
    waitForEnter();
    clearTerminal(1000);
}

void addToStats(Character& player, int amount){
    int response;
    cout << "Choose a stat to increase by " << amount << endl;
    for (int i = 0; i < player.stat_names.size(); i++){
        cout << i+1 << ") " << player.stat_names[i] << endl;
    }
        do{
        response = getInt();
        switch (response){
            case 1:
                player.addStat(0, amount);
                break;
            case 2:
                player.addStat(1, amount);
                break;
            case 3:
                player.addStat(2, amount);
                break;
            case 4:
                player.addStat(3, amount);
                break;
            case 5:
                player.addStat(4, amount);
                break;
            case 6:
                player.addStat(5, amount);
                break;
            case 7:
                player.addStat(6, amount);
                break;
            default:
                cout << "Invalid choice. Please enter a number in the list: ";
                continue;
        }
        break;
    }
    while (true);
}