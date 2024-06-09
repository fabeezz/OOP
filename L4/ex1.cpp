#include <iostream>
#include <vector>
#include <list>

class Student
{
private:
    int numarMatricol;
    std::string nume;
    int nota;

public:
    Student(int numarMatricol = -1, std::string nume = "", int nota = -1)
    {
        this->numarMatricol = numarMatricol;
        this->nume = nume;
        this->nota = nota;
    }

    // constr. de copiere
    Student(const Student &other)
    {
        this->numarMatricol = other.numarMatricol;
        this->nume = other.nume;
        this->nota = other.nota;
    }

    Student &operator=(const Student &other)
    {
        if (this == &other)
            return *this;

        this->numarMatricol = other.numarMatricol;
        this->nume = nume;
        this->nota = nota;
        return *this;
    }

    int getNota(void) const;

    friend std::ostream &operator<<(std::ostream &os, const Student &student);
    friend std::istream &operator>>(std::istream &is, Student &student);

    // destructor
    ~Student()
    {
        std::cout << "~Student()\n";
    }

private:
    // metode private
};

int Student::getNota(void) const
{
    return nota;
}

std::ostream &operator<<(std::ostream &os, const Student &student)
{

    os << "Student: "
       << "nrMat = " << student.numarMatricol << "\t"
       << "nume= " << student.nume << "\t"
       << "nota= " << student.nota;
    return os;
}
std::istream &operator>>(std::istream &is, Student &student)
{
    is >> student.numarMatricol;
    is >> student.nume;
    is >> student.nota;
}
/*=====================================================*/

class Curs
{
private:
    std::list<Student> studenti;
    std::string numeCurs;

public:
    Curs(std::list<Student> studenti, std::string numeCurs)
    {
        this->studenti = studenti;
        this->numeCurs = numeCurs;
    }
    Curs(const Curs &other)
    {
        this->studenti = other.studenti;
        this->numeCurs = other.numeCurs;
    }

    Curs &operator=(const Curs &other)
    {
        if (this == &other)
            return *this;

        this->studenti = studenti;
        this->numeCurs = numeCurs;
        return *this;
    }

    std::string getNumeCurs() const
    {
        return numeCurs;
    }

    void InscrieStudent(const Student &student)
    {
        studenti.push_back(student);
    }

    std::vector<Student> GetStudentiPromovati(void)
    {
        std::vector<Student> studentiPromovati;
        for (auto student : studenti)
        {
            if (student.getNota() >= 5)
                studentiPromovati.push_back(student);
        }
        return studentiPromovati;
    }

    friend std::ostream &operator<<(std::ostream &os, const Curs &curs);
};
std::ostream &operator<<(std::ostream &os, const Curs &curs)
{
    int cnt = 0;
    os << "Afisam studentii la cursul " << curs.numeCurs << ":" << std::endl;
    for (auto it = curs.studenti.begin(); it != curs.studenti.end(); it++)
    {
        const Student &student = *it;
        os << student;
        os << "\n";
    }
    std::cout << "---\n";
    return os;
}

int main()
{
    std::list<Curs> cursuri;
    std::list<Student> stundetiPoo;
    int nrStudentiPoo;
    std::cin >> nrStudentiPoo;
    for (int i = 0; i <= nrStudentiPoo; i++)
    {
        Student student;
        std::cin >> student;
        stundetiPoo.push_back(student);
    }

    Curs poo = Curs(stundetiPoo, "Programare Orientata pe Obiecte");
    cursuri.push_back(poo);

    for (auto curs : cursuri)
    {
        std::cout << curs;
    }

    for (auto curs : cursuri)
    {
        std::cout << "Studenti trecuti la cursul" << curs.getNumeCurs() << ":\n";
        std::vector<Student> studentiPromovati = curs.GetStudentiPromovati();

        for (auto student : studentiPromovati)
            std::cout << student;
    }
    return 0;
}