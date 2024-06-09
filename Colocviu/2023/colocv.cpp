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

    friend istream &operator>>(istream &in, Drum &drum);
    friend ostream &operator<<(ostream &out, const Drum &drum);
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

istream &operator>>(istream &in, Drum &drum)
{
    cout << "nume: ";
    in >> drum.nume;
    cout << "lungime: ";
    in >> drum.lungime;
    cout << "tronsoane: ";
    in >> drum.tronsoane;

    return in;
}

ostream &operator<<(ostream &out, const Drum &drum)
{
    out << "nume: ";
    out << drum.nume;
    out << "\nlungime: ";
    out << drum.lungime;
    out << "\ntronsoane: ";
    out << drum.tronsoane << endl;

    return out;
}

class DrumNational : public Drum
{
private:
    int nrJudete;

public:
    DrumNational(string nume_, float lungime_, int tronsoane_, int nrJudete_);

    friend istream &operator>>(istream &in, DrumNational &drum);
    friend ostream &operator<<(ostream &out, DrumNational &drum);
};

DrumNational::DrumNational(string nume_ = "n/a", float lungime_ = 0.0f, int tronsoane_ = 0, int nrJudete_ = 0) : Drum(nume_, lungime_, tronsoane_)
{
    this->nrJudete = nrJudete_;
}

istream &operator>>(istream &in, DrumNational &drum)
{
    in >> (Drum &)drum;
    cout << "Nr. judete: ";
    in >> drum.nrJudete;

    return in;
}

ostream &operator<<(ostream &out, DrumNational &drum)
{
    out << (Drum &)drum;
    out << "Nr. judete: ";
    out << drum.nrJudete << endl;
}

class DrumEuropean : virtual public Drum
{
protected:
    int nrTari;

public:
    DrumEuropean(string nume_, float lungime_, int tronsoane_, int nrTari_);

    friend istream &operator>>(istream &in, DrumEuropean &drum);
    friend ostream &operator<<(ostream &out, DrumEuropean &drum);
};

DrumEuropean::DrumEuropean(string nume_ = "n/a", float lungime_ = 0.0f, int tronsoane_ = 0, int nrTari_ = 0) : Drum(nume_, lungime_, tronsoane_)
{
    this->nrTari = nrTari_;
}

istream &operator>>(istream &in, DrumEuropean &drum)
{
    in >> (Drum &)drum;
    cout << "Nr. tari: ";
    in >> drum.nrTari;
    return in;
}

ostream &operator<<(ostream &out, DrumEuropean &drum)
{
    out << (Drum &)drum;
    out << "Nr. tari: ";
    out << drum.nrTari << endl;

    return out;
}

class Autostrada : virtual public Drum
{
private:
    int nrBenzi;

public:
    Autostrada(string nume_, float lungime_, int tronsoane_, int nrBenzi_);

    friend istream &operator>>(istream &in, Autostrada &drum);
    friend ostream &operator<<(ostream &out, const Autostrada &drum);
};

istream &operator>>(istream &in, Autostrada &drum)
{
    in >> (Drum &)drum;
    cout << "Nr. benzi: ";
    in >> drum.nrBenzi;

    return in;
}

ostream &operator<<(ostream &out, const Autostrada &drum)
{
    out << (Drum &)drum;
    out << "Nr. benzi: ";
    out << drum.nrBenzi << endl;

    return out;
}

Autostrada::Autostrada(string nume_ = "autos", float lungime_ = 0.0f, int tronsoane_ = 0, int nrBenzi_ = 0) : Drum(nume_, lungime_, tronsoane_)
{
    this->nrBenzi = nrBenzi_;
}

class AutostradaEU : public DrumEuropean, public Autostrada
{
private:
    int nrBenzi;

public:
    AutostradaEU(string nume_, float lungime_, int tronsoane_, int nrTari_, int nrBenzi_);

    friend istream &operator>>(istream &in, AutostradaEU &drum);
    friend ostream &operator<<(ostream &out, const AutostradaEU &drum);
};

istream &operator>>(istream &in, AutostradaEU &drum)
{
    in >> (Drum &)drum;
    cout << "Nr. benzi: ";
    in >> drum.nrBenzi;
    cout << "nr tari: ";
    in >> drum.nrTari;

    return in;
}

ostream &operator<<(ostream &out, const AutostradaEU &drum)
{
    out << (Drum &)drum;
    out << "Nr. benzi: ";
    out << drum.nrBenzi << endl;
    out << "nr tari: ";
    out << drum.nrTari << endl;

    return out;
}

AutostradaEU::AutostradaEU(string nume_ = "autoeu", float lungime_ = 0.0f, int tronsoane_ = 0, int nrTari_ = 0, int nrBenzi_ = 0) : DrumEuropean(nume_, lungime_, tronsoane_, nrTari_), Autostrada(nume_, lungime_, tronsoane_, nrBenzi_) {}

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
    static Meniu *instance;
    vector<Contract> contracte;
    vector<Drum *> drumuri;
    Meniu() = default;
    ~Meniu() = default;

public:
    static Meniu *getInstance()
    {
        if (instance == nullptr)
            instance = new Meniu();
        return instance;
    }
    void start();
    void afisareDrum();
    void lungimeTotala() {}
    void reziliere() {}
    void costTotal() {}
    void citireDrum();
};

void Meniu::afisareDrum()
{
    for (int i = 0; i < drumuri.size(); i++)
        cout << *drumuri[i];
}

void Meniu::citireDrum()
{
    cout << "Alege tipul de drum: " << endl;
    cout << "1. DN" << endl;
    cout << "2. DE" << endl;
    cout << "3. A" << endl;
    cout << "4. AE" << endl;
    int option;
    cin >> option;
    try
    {
        switch (option)
        {
        case 1:
            drumuri.push_back(new DrumNational());
            cin >> *drumuri.back();
            break;
        case 2:
            drumuri.push_back(new DrumEuropean());
            cin >> *drumuri.back();
            break;
        case 3:
            drumuri.push_back(new Autostrada());
            cin >> *drumuri.back();
            break;
        case 4:
            drumuri.push_back(new AutostradaEU());
            cin >> *drumuri.back();
            break;

        default:
            break;
        }
    }
    catch (const std::exception &ex)
    {
        std::cerr << ex.what() << '\n';
    }
}

void Meniu::start()
{
    int optiune;
    while (true)
    {
        cout << "1. Afisare Drum\n";
        cout << "2. Lungime totala\n";
        cout << "3. Reziliere\n";
        cout << "4. Cost total\n";
        cout << "5. Citire drum\n";
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
            case 5:
                citireDrum();
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

    Meniu *meniu = Meniu::getInstance();
    meniu->start();
    return 0;
}
