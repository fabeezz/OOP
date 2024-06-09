#include <iostream>
#include <vector>
#include <stdexcept>
using namespace std;

/*
    JIGLAU FABRIZZIO
    GNU 13.1
    WAGNER DANIEL
*/

class Item
{
protected:
    int id;
    static int counter;

public:
    int getID();
    virtual ~Item() = default;
    Item() : id{counter++} {}
    friend ostream &operator<<(ostream &out, const Item &i);
    virtual float get_cost_upgrade(int &p) {}
};
int Item::counter = 1;
int Item::getID()
{
    return this->id;
}
ostream &operator<<(ostream &out, const Item &i)
{
    out << "Id: " << i.id;
    return out;
}

// ZID
class Zid : public Item
{
private:
    float inaltime;
    float lungime;
    float grosime;

public:
    Zid() = default;
    Zid(float inaltime_, float lungime_, float grosime_);
    friend ostream &operator<<(ostream &out, const Zid &i);
    float get_cost_upgrade(int &p) override;
};

float Zid::get_cost_upgrade(int &p)
{
    p -= 100 * lungime * inaltime * grosime;
    return 100 * lungime * inaltime * grosime;
}

ostream &operator<<(ostream &out, const Zid &i)
{
    out << (Item &)i;
    out << "\ninaltime: " << i.inaltime;
    out << "\nlungime: " << i.lungime;
    out << "\ngrosime: " << i.grosime;
    return out;
}

Zid::Zid(float inaltime_, float lungime_, float grosime_) : Item(), inaltime{inaltime_}, lungime{lungime_}, grosime{grosime_} {}

// TURN
class Turn : public Item
{
private:
    float putere_laser;

public:
    Turn() = default;
    Turn(float putere_laser_) : Item(), putere_laser{putere_laser_} {}
    friend ostream &operator<<(ostream &out, const Turn &i);
    float get_cost_upgrade(int &p) override;
};

float Turn::get_cost_upgrade(int &p)
{
    p -= 500 * putere_laser;
    return 500 * putere_laser;
}

ostream &operator<<(ostream &out, const Turn &i)
{
    out << (Item &)i;
    out << "\nputere laser: " << i.putere_laser;
    return out;
}

// ROBOT BAZA
class Robot : public Item
{
protected:
    float damage;
    int nivel;
    float viata;

public:
    Robot() = default;
    Robot(float damage_, int nivel_, float viata_) : Item(), damage{damage_}, nivel{nivel_}, viata{viata_} {}
    friend ostream &operator<<(ostream &out, const Robot &i);
};

ostream &operator<<(ostream &out, const Robot &i)
{
    out << (Item &)i;
    out << "\ndamage: " << i.damage;
    out << "\nnivel: " << i.nivel;
    out << "\nviata: " << i.viata;
    return out;
}

// ROBOT AERIAN
class RobotAerian : public Robot
{
protected:
    float autonomie_zbor;

public:
    RobotAerian() = default;
    RobotAerian(float damage_, int nivel_, float viata_, float autonomie_zbor_) : Robot(damage_, nivel_, viata_), autonomie_zbor{autonomie_zbor_} {}
    friend ostream &operator<<(ostream &out, const RobotAerian &i);
    float get_cost_upgrade(int &p) override;
};

float RobotAerian::get_cost_upgrade(int &p)
{
    p -= 50 * autonomie_zbor;
    return 50 * autonomie_zbor;
}

ostream &operator<<(ostream &out, const RobotAerian &i)
{
    out << (Robot &)i;
    out << "\nautonomie zbor: " << i.autonomie_zbor;
    return out;
}

// ROBOT TERESTRU
class RobotTerestru : public Robot
{
protected:
    int nr_gloante;
    bool scut;

public:
    RobotTerestru() = default;
    RobotTerestru(float damage_, int nivel_, float viata_, int nr_gloante_, bool scut_) : Robot(damage_, nivel_, viata_), nr_gloante{nr_gloante_}, scut{scut_} {}
    friend ostream &operator<<(ostream &out, const RobotTerestru &i);
    float get_cost_upgrade(int &p) override;
};

float RobotTerestru::get_cost_upgrade(int &p)
{
    p -= 10 * nr_gloante;
    return 10 * nr_gloante;
}

ostream &operator<<(ostream &out, const RobotTerestru &i)
{
    out << (Robot &)i;
    out << "\nnr gloante: " << i.nr_gloante;
    out << "\nscut: " << i.scut;
    return out;
}

class Jucator
{
private:
    int puncte;
    vector<Item *> iteme;

public:
    Jucator(int puncte_ = 50000) : puncte{puncte_} {}
    void start();
    void adauga_elemente();
    void upgrade();
    void afis_crescator();
    void afis_roboti();
    void sell(int id_vanzare);
};

void Jucator::afis_crescator()
{
    if (iteme.size() == 0)
        cout << "NU MAI AI ITEME\n";
    else
        for (Item *elem : iteme)
            cout << *elem << endl;
}

void Jucator::afis_roboti()
{
}

void Jucator::sell(int id_vanzare)
{
    for (Item *elem : iteme)
        if (elem->getID() == id_vanzare)
        {
            delete elem;
        }
    puncte += 500;
}

void Jucator::start()
{
    while (true)
    {
        int input;
        cout << "1. ADAUGA\n";
        cout << "2. UPGRADE\n";
        cout << "3. AFIS ITEME CRESCATOR\n";
        cout << "4. AFIS ROBOTI\n";
        cout << "5. SELL\n";
        cout << "0. ABORT\n";
        cin >> input;
        if (input == 0)
            break;
        else
        {
            switch (input)
            {
            case 1:
                adauga_elemente();
                break;
            case 2:
                upgrade();
                break;
            case 3:
                afis_crescator();
                break;
            case 4:
                afis_roboti();
                break;
            case 5:
                cout << "ID ITEM DE VANDUT: ";
                int id_vanzare;
                cin >> id_vanzare;
                sell(id_vanzare);
                break;

            default:
                cout << "Optiune invalida!" << endl;
                break;
            }
        }
    }
}

void Jucator::adauga_elemente()
{
    while (true)
    {
        int input;
        cout << "1. ZID\n";
        cout << "2. TURN\n";
        cout << "3. ROBOT AERIAN\n";
        cout << "4. ROBOT TERESTRU\n";
        cout << "0. ABORT\n";
        cin >> input;
        if (input == 0)
            break;
        else
        {
            switch (input)
            {
            case 1:
                iteme.push_back(new Zid(2, 1, 0.5));
                puncte -= 300;
                break;
            case 2:
                iteme.push_back(new Turn(1000));
                puncte -= 500;
                break;
            case 3:
                iteme.push_back(new RobotAerian(100, 1, 100, 10));
                puncte -= 100;
                break;
            case 4:
                iteme.push_back(new RobotTerestru(100, 1, 100, 500, 0));
                puncte -= 50;
                break;

            default:
                cout << "Optiune invalida!" << endl;
                break;
            }
        }
    }
}

void Jucator::upgrade()
{
}

int main()
{
    // Zid zid1 = Zid();
    // Zid zid2 = Zid();
    // Turn turn1 = Turn();
    // Zid *zid1 = new Zid();
    // cout << *zid1 << endl;

    // RobotAerian rt1 = RobotAerian();
    // cout << rt1;

    Jucator jucator = Jucator();
    jucator.start();
    return 0;
}