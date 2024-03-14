#include <string>
#include <iostream>

class Student
{
    std::string nume;
    int an;

public:
    Student(const std::string &nume_, int an_) : nume{nume_}, an{an_}
    {
        std::cout << "Constr de initializare Student\n";
    }

    Student(const Student &other) : nume{other.nume}, an{other.an}
    {
        std::cout << "Constr de copiere Student\n";
    }

    ~Student()
    {
        std::cout << "Destr Student\n";
    }
};

class Facultate
{
    std::string nume;
    Student stud;

public:
    Facultate(const std::string &nume_, const Student &stud_) : nume{nume_}, stud{stud_}
    {
        std::cout << "Constr de initializare Facultate\n";
    }
};

int main()
{
    Facultate f1{"fmi", Student{"s1", 1}};
}