#ifndef CASE_H
#define CASE_H

#include <string>
#include <vector>
#include "item.h"

class Case
{
private:
    std::string caseName;
    float casePrice;
    std::vector<Item> items;
    std::vector<Item> blues;
    std::vector<Item> purples;
    std::vector<Item> pinks;
    std::vector<Item> reds;
    std::vector<Item> golds;

public:
    Case(const std::string &caseName_, float casePrice_);

    float getCasePrice() const;
    std::string getCaseName() const;
    std::vector<Item> getItems() const;

    void addItem(const Item &newItem);
    Item openCase() const;

    friend std::ostream &operator<<(std::ostream &os, const Case &case_);
};

#endif // CASE_H
