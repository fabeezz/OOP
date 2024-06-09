#include <iostream>
#include <vector>
using namespace std;

enum MetodaInfectare
{
    UNKNOWN
};

enum class MalwareTypes
{
    ROOTKIT,
    KEYLOGGER,
    KERNEL_KEYLOGGER,
    RANSOMWARE,
    NUM_MALWARES,
    UNKNOWN_MALWARE
};

class IMalware
{
public:
    virtual void Display(std::ostream &os) const = 0;
    virtual float CalculateImpact(void) = 0;
};

class AbstractMalware : protected IMalware
{
protected:
    struct Date
    {
        int day, month, year;
    };

protected:
    Date dataInfectare;
    string nume;
    vector<string> registriiModificati;
    vector<MetodaInfectare> metodaInfectare;
    MetodaInfectare metodaInfectare;
    float impactRating;

public:
    AbstractMalware(Date dataInfectare_, string nume_, const vector<string> &registriiModificati_, const MetodaInfectare metodaInfectare_ = MetodaInfectare::UNKNOWN);
    void Display(std::ostream &os) const override;
    friend ostream &operator<<(ostream &os, const AbstractMalware &malware);
    virtual ~AbstractMalware() = default;
};

AbstractMalware::AbstractMalware(Date dataInfectare_, string nume_, const vector<string> &registriiModificati_, const MetodaInfectare metodaInfectare_) : dataInfectare{dataInfectare_}, nume{nume_}, registriiModificati{registriiModificati_}, metodaInfectare{metodaInfectare_} {}

ostream &operator<<(ostream &os, const AbstractMalware &malware)
{
    os << "Malware:\n";
    os << "Date:" << malware.dataInfectare.day << " / " << malware.dataInfectare.month << " / " << malware.dataInfectare.year << endl;
    os << "Nume: " << malware.nume << endl;
    os << "Data infectare" return os;
}

int main()
{

    return 0;
}