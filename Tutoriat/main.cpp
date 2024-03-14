#include <iostream>
#include <string>
#include <cstring>
using namespace std;

class Computer
{
private:
    string nume;
    const int id;
    static int counter;
    int *memorie;
    int sizeMemorie;
    char *mProcesor;
    int pret;

public:
    Computer();
    Computer(string nume, int *memorie, int sizeMemorie, char *mProcesor, int pret);
};

Computer::Computer() : id(counter++)
{
    this->nume = "";
    this->sizeMemorie = 0;
    this->memorie = nullptr;
    this->mProcesor = nullptr;
    this->pret = 0;
}

Computer::Computer(string nume, int *memorie, int sizeMemorie, char *mProcesor, int pret) : id(counter++)
{
    this->nume = nume;
    this->sizeMemorie = sizeMemorie;
    this->memorie = new int[this->sizeMemorie];
    for (int i = 0; i < sizeMemorie; i++)
    {
        this->memorie[i] = memorie[i];
    }

    if (mProcesor != nullptr)
    {
        this->mProcesor = new char[strlen(mProcesor) + 1];
        strcpy(this->mProcesor, mProcesor);
    }
    this->pret = pret;
}

int Computer::counter = 1;

int main()
{
    // int a = 10;
    // int *aPtr = &a;
    // cout << *aPtr << endl;
    // cout << &a << endl;
    // cout << aPtr << endl;

    Computer comp1, comp2;
    Computer *compPtr = &comp1;
    return 0;
}