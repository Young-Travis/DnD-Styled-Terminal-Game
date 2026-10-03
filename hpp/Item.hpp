#ifndef ITEM_HPP
#define ITEM_HPP

#include <string>

using namespace std;

class Item{
public:
    string item_name;
    float item_weight;
    int buy_price;
    int sell_price;
    bool equippable = false;

    virtual ~Item() = default;

    void onSell();
};

class Gold : public Item{
public:
    Gold(){
        item_name = "Gold";
        item_weight = 0.02f;
    }
};

#endif