#include "hpp/main_menu.hpp"

//includes for testing
#include "hpp/Armor.hpp"
#include "hpp/Character_class.hpp"
#include "hpp/Character.hpp"
#include "hpp/general_utility.hpp"
#include "hpp/Item.hpp"
#include "hpp/main_menu.hpp"
#include "hpp/npc.hpp"
#include "hpp/Weapon.hpp"

using namespace std;

void functionForTesting(){
    Character p1("Travis");
    LeatherArmor armor;

    p1.createStats();
    
    p1.printStats();
    
    p1.printModifiers();

    p1.equipItem(armor);

    p1.printStats();
}

int main(void){
    functionForTesting();
    //generateMainMenu();
}