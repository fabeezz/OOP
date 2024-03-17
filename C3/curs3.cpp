#include <iostream>
using namespace std;

class Test
{
    int x;

public:
    /// void operator=(Test); // nu asa
    Test operator=(Test &);
    Test &operator+(int){};
    friend Test &operator+(int, Test &);

    void set_x(int a) { x = a; }
    void afis()
    {
        cout << x;
    }
    Test operator+(Test &);

    Test(const Test &); /// constr de copiere
    Test(int a = 0) : x(a) {}
};

Test::Test(const Test &ob)
{
    x = ob.x;
}

// void Test::operator=(Test Ob)
Test &Test::operator=(Test &Ob)
{
    return *this;
}

// Test &operator+(int a, Test &b)
// {
//     Test local;
//     /// obiectul local se modifica
//     return local;
// }

Test Test::operator+(Test &ob)
{
    return Test(this->x + ob.x);
}

int main()
{
    Test A;
    Test B;
    /*  B = A; // B.operator = (A) /// op de atribuire se supraincarca EXCLUSIV ca functie membra
        Test C;
        C = B = A;  // C.operator = (B.operator = (A))
        C + 10;     // C.operator + (10)
        B = C + 10; // B.operator=(C.operator+(10))
        Test D;
        D = 45 + C; // 45.operator+(C) ??????
    */
    A.set_x(10);
    A.afis();
    B.set_x(20);
    B.afis();
    Test D;
    D = A + B; // D.operator=(A.operator+(B))

    D.afis();

    return 0;
}