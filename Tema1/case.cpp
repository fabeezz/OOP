#include "case.h"
#include <cstdlib>
#include <time.h>
#include <random>

Case::Case(const std::string &caseName_, float casePrice_)
    : caseName(caseName_), casePrice(casePrice_) {}

float Case::getCasePrice() const
{
    return casePrice;
}

std::string Case::getCaseName() const
{
    return caseName;
}

std::vector<Item> Case::getItems() const
{
    return items;
}

void Case::addItem(const Item &newItem)
{
    items.push_back(newItem);
    std::string color = newItem.getRarity();
    if (color == "blue")
        blues.push_back(newItem);
    else if (color == "purple")
        purples.push_back(newItem);
    else if (color == "pink")
        pinks.push_back(newItem);
    else if (color == "red")
        reds.push_back(newItem);
    else if (color == "gold")
        golds.push_back(newItem);
}

Item Case::openCase() const
{
    int index = (rand() % 3910) + 1;
    int itemPick = rand();

    // std::cout << "Selected index: " << index << std::endl;

    // if (index == 1)
    //     std::cout << "You got a ST Knife\n";
    // else if (index <= 4)
    //     std::cout << "You got a ST Convert\n";
    if (index <= 10)
    {
        // std::cout << "You got a Knife!\n";
        itemPick = itemPick % 13;
        return golds[itemPick];
    }
    // else if (index <= 25)
    //     std::cout << "You got a ST Classified\n";
    else if (index <= 35)
    {
        // std::cout << "You got a Convert\n";
        itemPick = itemPick % 2;
        return reds[itemPick];
    }
    // else if (index <= 110)
    //     std::cout << "You got a ST Restricted\n";
    else if (index <= 161)
    {
        // std::cout << "You got a Classified\n";
        itemPick = itemPick % 3;
        return pinks[itemPick];
    }
    // else if (index <= 536)
    //     std::cout << "You got a ST Mil-spec\n";
    else if (index <= 813)
    {
        // std::cout << "You got a Restricted\n";
        itemPick = itemPick % 5;
        return purples[itemPick];
    }
    else if (index <= 3910)
    {
        // std::cout << "You got a Mil-spec\n";
        itemPick = itemPick % 7;
        return blues[itemPick];
    }
}

std::ostream &operator<<(std::ostream &os, const Case &case_)
{
    os << "Case Name: " << case_.getCaseName() << ", Price: " << case_.getCasePrice() << std::endl;
    os << "Items in the case:" << std::endl;
    for (const auto &item : case_.getItems())
    {
        os << item << std::endl;
    }
    return os;
}
