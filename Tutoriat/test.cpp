#include <iostream>
#include <cstring>
using namespace std;

class Concert
{
public:
    int nrBilete;
    char *nume;

public:
    Concert()
    {
        this->nrBilete = 0;
        this->nume = nullptr;
    }

    Concert(int nrBilete, char *nume)
    {
        this->nrBilete = nrBilete;
        this->nume = new char[strlen(nume) + 1];
        strcpy(this->nume, nume);
    }

    Concert(const Concert &obj)
    {
        this->nrBilete = obj.nrBilete;
        this->nume = new char[strlen(nume) + 1];
        strcpy(this->nume, nume);
    }

    ~Concert()
    {
        if (this->nume != nullptr)
        {
            delete[] this->nume;
            this->nume = nullptr;
        }
    }
};

int main()
{
    Concert a(0, "Ian");
    cout << a.nrBilete << endl;
    Concert b(a);
    cout << a.nrBilete;
    return 0;
}