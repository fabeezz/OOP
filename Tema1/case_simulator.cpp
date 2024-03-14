#include <iostream>
#include <string>
#include <vector>

class Item
{
    string itemName;
    float itemPrice;

public:
    Item(const string &name, float price) : itemName(name), itemPrice(price) {}

    // Getter function to output all information about the item
    void printItem() const
    {
        cout << "Item Name: " << itemName << ", Price: " << itemPrice << endl;
    }
};

class Case
{
private:
    string caseName;
    float casePrice;
    std::vector<Item> items;

public:
    Case(const string &caseName_, float casePrice_) : caseName(caseName_), casePrice(casePrice_)
    {
        cout << "Constr. de init. Case" << endl;
    }

    Case(const Case &other) : caseName(other.caseName), casePrice(other.casePrice), items(other.items)
    {
        cout << "Constr. de copiere Case" << endl;
    }

    ~Case()
    {
        cout << "Destr. Case" << endl;
    }

    void addItem(const Item &newItem)
    {
        items.push_back(newItem);
    }

    // Getter function to output all information about the case, including its items
    void printCase() const
    {
        cout << "Case Name: " << caseName << ", Price: " << casePrice << endl;
        cout << "Items in the case:" << endl;
        for (const auto &item : items)
        {
            item.printItem();
        }
    }
};

int main()
{
    Item item1("AK-47 | Inheritance", 100);
    Item item2("AWP | Chrome Cannon", 115);

    Case kwCase("Kilowatt Case", 2.54);
    kwCase.addItem(item1);
    kwCase.addItem(item2);

    // Output information about  the case
    kwCase.printCase();

    return 0;
}
