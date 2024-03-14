#include "Vector2.h"
// teoretic, nu trebuie sa includem iostream, ca Vector2.h il include dar
// include guards (#ifndef #define #endif), ne fac sa nu fie inclus multiplu
#include <iostream>
// fara using namespace std;

int main()
{
    // ilustrare functionalitati existente + implementate de voi

    int scalar = 10;

    Vector2 v = Vector2(10, 20);
    Vector2 vx = Vector2(30, 50);
    std::cout << v.getX() << std::endl;

    Vector2 v2 = v + v;
    std::cout << v2 << std::endl;

    Vector2 v3 = vx - v;
    std::cout << v3 << std::endl;

    Vector2 v4 = v * scalar;
    std::cout << v4 << std::endl;

    std::cout << (v == vx) << std::endl;
    return 0;
}