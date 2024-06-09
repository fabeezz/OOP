#include <iostream>
#include <vector>
using namespace std;

class Bilet{
protected:
    float pret;
    bool validat = false;
public:
    Bilet() = default;
    virtual ~Bilet() = default;

    Bilet(float pret_) : pret(pret_) {}

};

class BiletSuprafata : virtual public Bilet{
public:
    BiletSuprafata() : Bilet(2.0f) {}
};

class BiletMetrou : virtual public Bilet{
public:
    BiletMetrou() : Bilet(2.5f) {}
};

class BiletTranzit : public BiletSuprafata, public BiletMetrou {
public:
    BiletTranzit() : Bilet(3.0f) {}
};

class Card{
protected:
    vector<Bilet*> bilete;
public:
    virtual void autogen(vector<Bilet*>& bilete) = 0;
    virtual void adaugare_bilet() = 0;
    Card() = default;
    virtual ~Card() {
        for(auto &bilet : bilete)
            delete bilet;
    }
};

class CardSuprafata : virtual public Card{
public:
    void autogen(vector<Bilet*>& bilete) override;
    void adaugare_bilet() override;

    CardSuprafata() {}
};

void CardSuprafata::autogen(vector<Bilet *> &bilete) {

}

void CardSuprafata::adaugare_bilet() {
    this->bilete.push_back(new BiletSuprafata());
}


class CardSubteran : virtual public Card{
public:
    void autogen(vector<Bilet*>& bilete) override;
    void adaugare_bilet() override;

    CardSubteran() {}
};

void CardSubteran::autogen(vector<Bilet *> &bilete) {
}

void CardSubteran::adaugare_bilet() {

}

class CardTranzit : public CardSuprafata, public CardSubteran{
public:
    void autogen(vector<Bilet*>& bilete) override;
    void adaugare_bilet() override;

    CardTranzit() {}
};

int main() {

    CardSuprafata cardSup1 = CardSuprafata();
    cardSup1.adaugare_bilet(bilete);


    return 0;
}
