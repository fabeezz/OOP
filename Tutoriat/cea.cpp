#include <iostream>
using namespace std;

class Vehicul
{
private:
    const int id;
    static int counter;
    string producator;
    int numarUsi;

public:
    Vehicul(string producator_, int numarUsi_);
};

Vehicul::Vehicul(string producator_ = "Nu stiu", int numarUsi_ = 0) : id(counter++), producator{producator_}, numarUsi{numarUsi_} {}

int main()
{

    return 0;
}
