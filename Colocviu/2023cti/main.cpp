#include <iostream>
#include <cmath>
#include <ctime>
#include <random>
using namespace std;

class Unealta
{
protected:
    unsigned int nrSerie;
    static unsigned int counter;
    string culoare;
    float suprCuratata;

public:
    Unealta(string culoare_ = "N/A", float suprCuratata_ = 0.0f);
    Unealta(const Unealta &u);
    virtual ~Unealta() = default;

    friend istream &operator>>(istream &in, Unealta &u);
    friend ostream &operator<<(ostream &out, const Unealta &u);
};
unsigned int Unealta::counter = 1;

Unealta::Unealta(string culoare_, float suprCuratata_) : nrSerie{counter++}, culoare{culoare_}, suprCuratata{suprCuratata_} {}

Unealta::Unealta(const Unealta &u) : nrSerie{u.nrSerie}, culoare{u.culoare}, suprCuratata{u.suprCuratata} {}

istream &operator>>(istream &in, Unealta &u)
{
    cout << "Introduceti culoarea: ";
    in >> u.culoare;
    cout << "Introduceti aria curatata: ";
    in >> u.suprCuratata;
    return in;
}

ostream &operator<<(ostream &out, const Unealta &u)
{
    out << "Nr. Serie: " << u.nrSerie << " ";
    out << "Culoare: " << u.culoare << " ";
    out << "Aria curatata: " << u.suprCuratata << " ";
    return out;
}
//-------------------------LOPATA ELECTRICA--------------------------------

class LopataElectrica : public Unealta
{
private:
    string serie = "LEx";
    float faras;
    float baterie;
    float timpLopata;
    float consLopata;

    float generate_timpLopata(float suprCuratata_, float faras_)
    {
        return suprCuratata_ / sqrt(faras_);
    }
    float generate_consLopata(float suprCuratata_, float baterie_)
    {
        return pow(suprCuratata_, 2) * baterie_;
    }

public:
    LopataElectrica() = default;
    LopataElectrica(string culoare_, float suprCuratata_, float faras_, float baterie_) : Unealta(culoare_, suprCuratata_), faras{faras_}, baterie{baterie_}, timpLopata{generate_timpLopata(suprCuratata_, faras_)}, consLopata{generate_timpLopata(suprCuratata_, baterie_)} {}

    friend istream &operator>>(istream &in, LopataElectrica &le);
    friend ostream &operator<<(ostream &out, const LopataElectrica &le);
};

istream &operator>>(istream &in, LopataElectrica &le)
{
    in >> (Unealta &)le;
    cout << "Suprafata faras: ";
    in >> le.faras;
    cout << "Capacitate baterie: ";
    in >> le.baterie;
    return in;
}

ostream &operator<<(ostream &out, const LopataElectrica &le)
{
    out << "Seria: " << le.serie << " ";
    out << (Unealta &)le;
    out << "Suprafata faras: " << le.faras << " Capacitate baterie: " << le.baterie << "Timp lopata_elec: " << le.timpLopata << " Consum en. lopata: " << le.consLopata << endl;
    return out;
}

//-------------------------DRONA--------------------------------

class Drona : public Unealta
{
private:
    string serie = "DRx";
    float altitudine;
    unsigned int nrMotoare;
    float timpDrona;
    float consDrona;
    bool turturi;

    float generate_timpDrona(float suprCuratata_, float altitudine_) { return log(suprCuratata_) * tanh(altitudine_); }
    float generate_consDrona(float suprCuratata_, unsigned int nrMotoare_) { return suprCuratata_ * pow(nrMotoare_, 3); }
    bool generate_turturi()
    {
        int prob = rand() % 100 + 1;
        if (prob >= 95)
            return false;
        else
            return true;
    }

public:
    Drona() = default;
    Drona(string culoare_, float suprCuratata_, float altitudine_, unsigned int nrMotoare_) : Unealta(culoare_, suprCuratata_), altitudine{altitudine_}, nrMotoare{nrMotoare_}, timpDrona{generate_timpDrona(suprCuratata_, altitudine_)}, consDrona{generate_consDrona(suprCuratata_, nrMotoare_)}, turturi{generate_turturi()} {}

    friend istream &operator>>(istream &in, Drona &d);
    friend ostream &operator<<(ostream &out, const Drona &d);
};

istream &operator>>(istream &in, Drona &d)
{
    in >> (Unealta &)d;
    cout << "Altitudine maxima: ";
    in >> d.altitudine;
    cout << "Nr. motoare: ";
    in >> d.nrMotoare;
    return in;
}

ostream &operator<<(ostream &out, const Drona &d)
{
    out << "Seria: " << d.serie << " ";
    out << (Unealta &)d;
    out << "Altitudine max: " << d.altitudine << " " << "Nr. motoare: " << d.nrMotoare << " Timp drona: " << d.timpDrona << " Consum en. drona: " << d.consDrona << " Turturi: " << d.turturi << endl;
    return out;
}

//-------------------------PROTOTIP-------------------------------

class Prototip : public Unealta
{
private:
    string serie = "UPx";
    float masa;
    float greutate;
    float impact;

    float get_greutate(float masa_) { return 9.81 * masa_; }
    float get_impact(float masa_) { return get_greutate(masa_) * 1.2; }

public:
    Prototip() = default;
    Prototip(string culoare_, float suprCuratata_, float masa_) : Unealta(culoare_, suprCuratata_), masa{masa_}, greutate{get_greutate(masa_)}, impact{get_impact(masa_)} {}

    friend istream &operator>>(istream &in, Prototip &p);
    friend ostream &operator<<(ostream &out, const Prototip &p);
};

istream &operator>>(istream &in, Prototip &p)
{
    in >> (Unealta &)p;
    cout << "Masa: ";
    in >> p.masa;
    return in;
}

ostream &operator<<(ostream &out, const Prototip &p)
{
    out << "Seria: " << p.serie << " ";
    out << (Unealta &)p;
    out << " Masa: " << p.masa << " Greutatea: " << p.greutate << " Impact: " << p.impact << endl;
    return out;
}

//--------------------Echipa--------------------------

class Echipa
{
private:
    enum Categorie
    {
        TIMP_MINIM = 1,
        CONSUM_MINIM
    };
    string nume;
    string motto;
    vector<Unealta *> unelte;
    Categorie ctg; // 0 -

public:
    Echipa() = default;
    ~Echipa() = default;
};

int main()
{
    srand((int)time(NULL));

    Unealta *u1 = new Unealta("Rosu", 25.5f);
    Unealta *u2 = new Unealta();
    // cin >> *u2;
    cout << *u1 << endl;
    // fiecare serie un static
    LopataElectrica *l2 = new LopataElectrica();
    LopataElectrica *l1 = new LopataElectrica("Alb", 51.2, 10, 1000);
    cout << *l1;

    Drona *d1 = new Drona("Verde", 43.2, 100, 3);
    cout << *d1 << endl;

    Prototip *p1 = new Prototip();
    cin >> *p1;
    cout << *p1 << endl;
    return 0;
}
