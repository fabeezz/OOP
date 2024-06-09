#include <iostream>
#include <vector>
using namespace std;

class Bilet
{
private:
    string stPlecare, stSosire, data, timp;
    string codTren;
    int durata;
    float distanta;

public:
    Bilet(string stPlecare_ = "", string stSosire_ = "", string data_ = "0/0/0", string timp_ = "0:0", string codTren_ = "0", int durata_ = -1, float distanta_ = -1);
    
};

Bilet::Bilet(string stPlecare_, string stSosire_, string data_, string timp_, string codTren_, int durata_, float distanta_) : stPlecare{stPlecare_}
{
}

int main()
{

    return 0;
}