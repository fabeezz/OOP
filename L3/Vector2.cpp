#include "Vector2.h"

// Constructor cu parametri impliciti implementat cu liste de initializare
Vector2::Vector2(float x, float y) : x(x), y(y) {}

// Implementare Getters
float Vector2::getX() const { return x; }
float Vector2::getY() const { return y; }

// Implementare Setters
void Vector2::setX(float x) { this->x = x; }
void Vector2::setY(float y) { this->y = y; }

// Adaugati pe parcurs operatorii din indrumar

// Supraincarcarea operatorului << pentru scriere Vector2
std::ostream &operator<<(std::ostream &os, const Vector2 &v)
{
    os << '(' << v.x << ", " << v.y << ')';
    return os;
}

// Supraincarcarea operatorului >> pentru citire Vector2
std::istream &operator>>(std::istream &is, Vector2 &v)
{
    std::cout << "x: ";
    is >> v.x;
    std::cout << "y: ";
    is >> v.y;
    return is;
}

// Supraîncărcarea operator+ pentru Vector2
Vector2 Vector2::operator+(const Vector2 &other) const
{
    return Vector2(this->x + other.x, this->y + other.y);
}

// Supraîncărcarea operator+= pentru Vector2
Vector2 &Vector2::operator+=(const Vector2 &other)
{
    this->x += other.x;
    this->y += other.y;
    return *this;
}

Vector2 Vector2::operator-(const Vector2 &other) const
{
    return Vector2(this->x - other.x, this->y - other.y);
}

Vector2 Vector2::operator*(const int &other) const
{
    return Vector2(this->x * other, this->y * other);
}

bool Vector2::operator==(const Vector2 &other) const
{
    return ((this->x == other.x) && (this->y == other.y));
}

bool Vector2::operator!=(const Vector2 &other) const
{
    return !(*this == other);
}

// Supraîncărcarea operator- unar pentru Vector2
// Vector2 &Vector2::operator-(const Vector2 &other)
// {
//     this->x = -this->x;
//     this->y = -this->y;
//     return *this;
// }

// Restul metodelor si operatorilor sugerati