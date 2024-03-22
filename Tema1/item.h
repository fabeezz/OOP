#ifndef ITEM_H
#define ITEM_H

#include <iostream>
#include <string>

class Item
{
private:
    std::string itemName;
    float itemPrice;
    std::string itemRarity;

public:
    Item(const std::string &name, float price, std::string rarity);

    std::string getRarity() const;
    std::string getItemName() const;
    float getItemPrice() const;

    friend std::ostream &operator<<(std::ostream &out, const Item &item);
};

#endif // ITEM_H
