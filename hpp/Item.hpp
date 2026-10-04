#ifndef ITEM_HPP
#define ITEM_HPP

#include <string>

using namespace std;

class Item{
public:
    string itemName;
    float itemWeight;
    int buyPrice;
    int sellPrice;
    bool equippable = false;

    virtual ~Item() = default;

    void onSell();
};

class Gold : public Item{
public:
    Gold(){
        itemName = "Gold";
        itemWeight = 0.02f;
    }
};

#endif