#include <iostream>
#include <cstring>
using namespace std; // incepand cu laboratorul urmator, nu o sa mai folosim

class Student
{
private:
    char *nume;

public:
    // aici vom adauga functiile (metodele) din clasa
    // si ulterior vom imparti in fisiere .h si .cpp

    // Constructor
    Student(const char *nume)
    {
        this->nume = new char[strlen(nume) + 1];
        strcpy(this->nume, nume);
    }
    // Constructor de Copiere
    Student(const Student &other)
    {
        this->nume = new char[strlen(other.nume) + 1];
        strcpy(this->nume, other.nume);
    }
    Student &operator=(const Student &other)
    {
        if (this != &other)
        {
            delete[] this->nume;
            this->nume = new char[strlen(other.nume) + 1];
            strcpy(this->nume, other.nume);
        }
        return *this;
    }

    // Getteri si Setteri
    char *getNume()
    {
        return this->nume;
    }

    void setNume(const char *nume)
    {
        delete[] this->nume;
        this->nume = new char[strlen(nume) + 1];
        strcpy(this->nume, nume);
    }

    // Destructor
    ~Student()
    {
        delete[] this->nume;
    }
};

int main()
{
    // aici vom testa functionalitatea clasei Student
    char numeStudent[] = "Fabi";
    Student student = Student(numeStudent);
    cout << student.getNume() << endl;

    student.setNume("Gigel");
    cout << student.getNume() << endl;

    Student s2 = Student(student);
    s2.setNume("Mihai");
    cout << s2.getNume() << endl;

    s2 = student;
    cout << student.getNume() << endl;
    return 0;
}