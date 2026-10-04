#include "hpp/Item.hpp"
#include <iostream>

using namespace std;

void Item::onSell(){
    cout << "Sold " << itemName << endl;
}