#include "../include/item.h"

Item::Item(const std::string &name, float price, std::string rarity)
    : itemName(name), itemPrice(price), itemRarity(rarity) {}

std::string Item::getRarity() const
{
    return itemRarity;
}

std::string Item::getItemName() const
{
    return itemName;
}

float Item::getItemPrice() const
{
    return itemPrice;
}

std::ostream &operator<<(std::ostream &out, const Item &item)
{
    out << "Item Name: " << item.getItemName() << " // Price: " << item.getItemPrice() << "$"
        << " // Rarity: " << item.getRarity();
    return out;
}
