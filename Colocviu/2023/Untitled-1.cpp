#include <iostream>
#include <vector>
#include <memory>
#include <ctime>

class Timp
{
public:
    static std::tm get_timp()
    {
        auto timp1 = std::time(nullptr);
        return *std::localtime(&timp1);
    }
};

class Bilet
{
    bool validat = false;
    float pret;

public:
    virtual ~Bilet() = default;
    void valideaza() { validat = true; }
    bool e_validat() const { return validat; }
    float get_pret() const { return pret; }
    explicit Bilet(float pret_) : pret(pret_) {}
};
class BiletSupraf : public virtual Bilet
{
public:
    BiletSupraf() : Bilet(2) {}
};
class BiletMetrou : public virtual Bilet
{
public:
    BiletMetrou() : Bilet(2.5) {}
};
class BiletTranzit : public BiletSupraf, public BiletMetrou
{
public:
    BiletTranzit() : Bilet(3) {}
};

class Card
{
    virtual void valideaza_impl() = 0;
    virtual void afis(std::ostream &os) const = 0;

protected:
    std::vector<std::shared_ptr<Bilet>> bilete;
    int nr_validari = 0;
    std::tm timp_validare;

public:
    Card() = default;
    Card(const Card &) = delete;
    Card &operator=(const Card &) = delete;
    virtual ~Card() = default;
    void valideaza();
    void adauga(std::shared_ptr<Bilet> bilet)
    {
        bilete.push_back(bilet); //->clone());
    }
    friend std::ostream &operator<<(std::ostream &os, const Card &card)
    {
        float suma = 0;
        for (const auto &bilet : card.bilete)
            if (!bilet->e_validat())
                suma += bilet->get_pret();
        std::cout << "tip bilet " << "tba\n"
                  << "moment validare: " << card.timp_validare.tm_hour
                  << ":" << card.timp_validare.tm_min << "\n"
                  << "suma ramasa: " << suma << "\n";
        card.afis(os);
        return os;
    }
    /*
    void adauga(const Bilet& bilet) {
        bilete.push_back(bilet->clone());
    }*/
};

void Card::valideaza()
{
    timp_validare = Timp::get_timp();
    bilete.back()->valideaza();
    valideaza_impl();
}

class CardSupraf : public virtual Card
{
    void valideaza_impl() override
    {
        nr_validari++;
        if (nr_validari % 8 == 0)
            bilete.push_back(std::make_shared<BiletSupraf>());
    }
    void afis(std::ostream &os) const override
    {
    }
};
class CardMetrou : public virtual Card
{
    void valideaza_impl() override
    {

        nr_validari++;
        if (nr_validari % 8 == 0)
            bilete.push_back(std::make_shared<BiletMetrou>());
    }
    void afis(std::ostream &os) const override
    {
    }
};
class CardTranzit : public CardSupraf, public CardMetrou
{
    void valideaza_impl() override
    {
        nr_validari++;
        if (nr_validari % 8 == 0)
            bilete.push_back(std::make_shared<BiletTranzit>());
    }
    void afis(std::ostream &os) const override
    {
        auto timp_curent = Timp::get_timp();
        if (timp_curent.tm_hour * 60 + timp_curent.tm_min -
                (timp_curent.tm_hour * 60 + timp_curent.tm_min) <
            90)
            os << "bilet valid\n";
    }
};

class Aparat
{
};

int main()
{
    // creare card
    int tip_card = 1;
    CardSupraf card1;

    // adăugarea unui bilet la un card
    if (tip_card == 1) // supraf
        card1.adauga(std::make_shared<BiletSupraf>());
    else if (tip_card == 2) // metrou
        card1.adauga(std::make_shared<BiletMetrou>());
}