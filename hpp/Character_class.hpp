#ifndef CHARACTER_CLASS_HPP
#define CHARACTER_CLASS_HPP

#include <string>
#include <vector>
using namespace std;

class Character_class{
public:
    string class_name;
    vector<int> base_stats = {1,1,1,1,1,1};
};

class Barbarian : public Character_class{
public:
    Barbarian(){
        class_name = "Barbarian";
        base_stats = {15,13,14,8,12,10};
    }
};

class Wizard : public Character_class{
public:
    Wizard(){
        class_name = "Wizard";
        base_stats = {8,13,14,15,12,10};
    }
};

class Cleric : public Character_class{
public:
    Cleric(){
        class_name = "Cleric";
        base_stats = {12,13,14,8,15,10};
    }
};

class Fighter : public Character_class{
public:
    Fighter(){
        class_name = "Fighter";
        base_stats = {15,13,14,8,12,10};
    }
};

class Rogue : public Character_class{
public:
    Rogue(){
        class_name = "Rogue";
        base_stats = {8,14,15,13,12,10};
    }
};

#endif