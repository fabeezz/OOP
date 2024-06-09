#include <iostream>
#include <cmath>
#include <vector>
using namespace std;

class Masina
{
protected:
    unsigned int an_productie;
    string model;
    float viteza;
    float greutate;
    float autonomie;

public:
    Masina() = default;
    virtual ~Masina() = default;

    virtual float genAutonomie() = 0;
    float getAutonomie() { return autonomie; }
    Masina(unsigned int an_productie_, string model_, float viteza_, float greutate_);
    friend ostream &operator<<(ostream &out, const Masina &m);
    friend istream &operator>>(istream &in, Masina &m);
};

ostream &operator<<(ostream &out, const Masina &m)
{
    cout << "an prod: ";
    out << m.an_productie;
    cout << "\nmodel: ";
    out << m.model;
    cout << "\nviteza: ";
    out << m.viteza;
    cout << "\ngreutate: ";
    out << m.greutate;
    return out;
}
istream &operator>>(istream &in, Masina &m)
{
    cout << "an prod: ";
    in >> m.an_productie;
    cout << "\nmodel: ";
    in >> m.model;
    cout << "\nviteza: ";
    in >> m.viteza;
    cout << "\ngreutate: ";
    in >> m.greutate;
    return in;
}

Masina::Masina(unsigned int an_productie_, string model_, float viteza_, float greutate_) : an_productie{an_productie_}, model{model_}, viteza{viteza_}, greutate{greutate_} {}

class MasinaFosil : virtual public Masina
{
public:
    enum t_comb
    {
        BENZINA = 1,
        MOTORINA
    };

protected:
    t_comb combustibil;
    float c_rezervor;

public:
    MasinaFosil() = default;
    float genAutonomie() override;
    MasinaFosil(unsigned int an_productie_, string model_, float viteza_, float greutate_, float c_rezervor_, t_comb combustibil_) : Masina(an_productie_, model_, viteza_, greutate_), c_rezervor{c_rezervor_}, combustibil{combustibil_}
    {
        autonomie = genAutonomie();
    }

    friend ostream &operator<<(ostream &out, const MasinaFosil &m);
    friend istream &operator>>(istream &in, MasinaFosil &m);
};

ostream &operator<<(ostream &out, const MasinaFosil &m)
{
    out << (Masina &)m;
    out << "rezervor: " << m.c_rezervor;
    out << "\ntip combustibil: " << m.combustibil;
    out << "\nautonomie: " << m.autonomie;
}

istream &operator>>(istream &in, MasinaFosil &m)
{
    in >> static_cast<Masina &>(m);
    cout << "rezervor: ";
    in >> m.c_rezervor;
    std::string input;
    cout << "Combustibil (1 = MOTORINA, 2 = BENZINA): ";
    in >> input;

    if (input == "1" || input == "MOTORINA")
    {
        m.combustibil = MasinaFosil::MOTORINA;
    }
    else if (input == "2" || input == "BENZINA")
    {
        m.combustibil = MasinaFosil::BENZINA;
    }
    else
    {
        throw invalid_argument("Invalid input for Combustibil enum");
    }
}

float MasinaFosil::genAutonomie()
{
    return c_rezervor / sqrt(greutate);
}

class Tranzactie
{
    string nume;
    string data;
    vector<Masina *> masini;
};

int main()
{
    MasinaFosil mf(11, "plm", 200.f, 200.f, 200.f, MasinaFosil::t_comb::MOTORINA);
    cout << mf << endl;
    return 0;
}
