#include <iostream>
#include "hpp/main_menu.hpp"
#include "hpp/Character_creator.hpp"
#include "hpp/general_utility.hpp"

using namespace std;

void generateMainMenu(){
    int response;
    while (true){
        cout << "Welcome to the game." << endl;
        cout << "1. New Game\n2. Load Game\n3. Settings\n4. Quit" << endl;
        int response = getInt();
        switch (response){
            case 1:
                onNewGame();
                break;
            case 2:
                onLoadGame();
                break;
            case 3:
                onSettings();
                break;
            case 4:
                onQuit();
                break;
            default:
                cout << "Invalid choice. Please enter a number in the list: " << endl;
                clearTerminal(1000);
                continue;
        }
        break;
    }
}

void onNewGame(){
    clearTerminal(500);
    askForName();
}

void onLoadGame(){
    clearTerminal(500);
    cout << "Not yet implemented...";
}

void onSettings(){
    clearTerminal(500);
    cout << "Not yet implemented....";
}

void onQuit(){
    clearTerminal(500);
    cout << "Quitting..." << endl;
}