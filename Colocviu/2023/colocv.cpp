#include <iostream>
#include <vector>
#include <exception>
using namespace std;

class MyException : public exception
{
public:
    virtual const char *what() const throw()
    {
        return "Valoare invalida";
    }
} ex1;

class Drum
{
protected:
    string nume;
    float lungime;
    int tronsoane;

public:
    Drum();
    Drum(string nume_, float lungime_, int tronsoane_);
    Drum(const Drum &drum);
    ~Drum() = default;
};

Drum::Drum()
{
    this->nume = "predefinit";
    this->lungime = 0.0f;
    this->tronsoane = 0;
}

Drum::Drum(string nume_, float lungime_, int tronsoane_)
{
    this->nume = nume_;
    this->lungime = lungime_;
    this->tronsoane = tronsoane_;
}

Drum::Drum(const Drum &drum)
{
    this->nume = drum.nume;
    this->lungime = drum.lungime;
    this->tronsoane = drum.tronsoane;
}

class DrumNational : public Drum
{
private:
    int nrJudete;

public:
    DrumNational(string nume_, float lungime_, int tronsoane_, int nrJudete_);
};

DrumNational::DrumNational(string nume_, float lungime_, int tronsoane_, int nrJudete_) : Drum(nume_, lungime_, tronsoane_)
{
    this->nrJudete = nrJudete_;
}

class DrumEuropean : virtual public Drum
{
private:
    int nrTari;

public:
    DrumEuropean(string nume_, float lungime_, int tronsoane_, int nrTari_);
};

DrumEuropean::DrumEuropean(string nume_, float lungime_, int tronsoane_, int nrTari_) : Drum(nume_, lungime_, tronsoane_)
{
    this->nrTari = nrTari_;
}

class Autostrada : virtual public Drum
{
private:
    int nrBenzi;

public:
    Autostrada(string nume_, float lungime_, int tronsoane_, int nrBenzi_);
};

Autostrada::Autostrada(string nume_, float lungime_, int tronsoane_, int nrBenzi_) : Drum(nume_, lungime_, tronsoane_)
{
    this->nrBenzi = nrBenzi_;
}

class AutostradaEU : public DrumEuropean, public Autostrada
{
private:
    int nrBenzi;

public:
    AutostradaEU(string nume_, float lungime_, int tronsoane_, int nrTari_, int nrBenzi_);
};

AutostradaEU::AutostradaEU(string nume_, float lungime_, int tronsoane_, int nrTari_, int nrBenzi_) : DrumEuropean(nume_, lungime_, tronsoane_, nrTari_), Autostrada(nume_, lungime_, tronsoane_, nrBenzi_) {}

class Contract
{
private:
    const int id;
    static int idCnt;
    string nume;
    string cif;
    float cost;
    Drum *drum;

public:
    Contract(string nume_, string cif_, float cost_, Drum *drum_);
    ~Contract();
};

int Contract::idCnt = 0;
Contract::Contract(string nume_, string cif_, float cost_, Drum *drum_) : id(++idCnt)
{
    this->nume = nume_;
    this->cif = cif_;
    this->cost = cost_;
    this->drum = drum_;
}

Contract::~Contract()
{
    if (this->drum != nullptr)
        delete drum;
    drum = nullptr;
}

class Meniu
{
private:
    vector<Contract> contracte;
    vector<Drum *> drumuri;

public:
    Meniu() = default;
    void start();
    void afisareDrum() {}
    void lungimeTotala() {}
    void reziliere() {}
    void costTotal() {}
};

void Meniu::start()
{
    int optiune;
    while (true)
    {
        cout << "1. Afisare Drum\n";
        cout << "2. Lungime totala\n";
        cout << "3. Reziliere\n";
        cout << "4. Cost total\n";
        cout << "0. Exit\n";
        cin >> optiune;
        try
        {
            switch (optiune)
            {
            case 1:
                afisareDrum();
                break;
            case 2:
                lungimeTotala();
                break;
            case 3:
                reziliere();
                break;
            case 4:
                costTotal();
                break;
            case 0:
                return;
            default:
                throw ex1;
            }
        }
        catch (exception &ex)
        {
            cout << ex.what();
        }
    }
}

int main()
{
    std::cout << "Hello, world!" << std::endl;

    Meniu meniu;
    meniu.start();
    return 0;
}
