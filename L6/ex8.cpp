#include <iostream>
#include <utility>
#include <vector>

constexpr PI = 3.14159256;

struct Pixel
{
    uint8_t r;
    uint8_t g;
    uint8_t b;
    uint8_t a;
};

class Shape
{
private:
    std::string culoare;
    std::pair<int, int> pozitie;

public:
    Shape(std::string culoare_ = "", int posX = -1, int posY = -1) : culoare{culoare_}, pozitie{std::make_pair(posX, posY)} {}
    virtual double GetArea(void) = 0;
    virtual double GetParimeter(void) = 0;
};

class Circle : public Shape
{
private:
    double radius;

public:
    Circle(std::string culoare_ = "", int posX = -1, int posY = -1, double radius_ = -1) : Shape(culoare_, posX, posY), radius{radius_} {}
    double GetArea(void) override
    {
        return PI * radius * radius;
    }
    double GetParimeter(void) override
    {
        return 2 * PI * radius;
    }
};

class Rectangle : public Shape
{
};

int main()
{
    std::vector<Shape *> shapes;
    shapes.push_back(new Circle("verde", 100, 200, 10));

    for (auto *shape : shapes)
    {
        std::cout << "Area: " << shape->GetArea() << "\t";
        std::cout << "Perimeter: " << shape->GetParimeter();
        std::cout << "---\n";
        delete shape;
    }
    return 0;
}