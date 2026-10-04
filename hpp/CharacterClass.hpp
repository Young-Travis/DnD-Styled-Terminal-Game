#ifndef CHARACTER_CLASS_HPP
#define CHARACTER_CLASS_HPP

#include <string>
#include <vector>
using namespace std;

class CharacterClass{
public:
    string className;
    vector<int> baseStats = {1,1,1,1,1,1};
};

class Barbarian : public CharacterClass{
public:
    Barbarian(){
        className = "Barbarian";
        baseStats = {15,13,14,8,12,10};
    }
};

class Wizard : public CharacterClass{
public:
    Wizard(){
        className = "Wizard";
        baseStats = {8,13,14,15,12,10};
    }
};

class Cleric : public CharacterClass{
public:
    Cleric(){
        className = "Cleric";
        baseStats = {12,13,14,8,15,10};
    }
};

class Fighter : public CharacterClass{
public:
    Fighter(){
        className = "Fighter";
        baseStats = {15,13,14,8,12,10};
    }
};

class Rogue : public CharacterClass{
public:
    Rogue(){
        className = "Rogue";
        baseStats = {8,14,15,13,12,10};
    }
};

#endif