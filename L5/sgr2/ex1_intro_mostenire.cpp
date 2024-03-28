#include <iostream>
#include <vector>

class Person {
protected:
    std::string name;
    int age;
public:
    Person(std::string name_ = "", int age_ = -1) : name{name_}, age{age_} {}
    friend std::ostream& operator<<(std::ostream& os, const Person& person);
    // virtual void f() {}; // fortez clasa sa fie polimorfica - sa aiba VTABLE cu VPTR
};

std::ostream& operator<<(std::ostream& os, const Person& person)
{
    os << "Person: " << "name: " << person.name << "\t" << "age: " << person.age << std::endl;
    return os;
}

class Student : public Person {
private:
    double medie;
public:
    Student(std::string name_ = "", int age_ = -1, double medie_ = 0) 
        : Person(name_, age_), medie{medie_} {}
    friend std::ostream& operator<<(std::ostream& os, const Student& student);
};

std::ostream& operator<<(std::ostream& os, const Student& student)
{
    // os << (const Person&) student;
    os << static_cast<const Person&>(student);
    os << "Student: medie = " << student.medie;
    return os;
}

class Employee : public Person {
private:
    double salariu;
public:
    Employee(std::string name_ = "", int age_ = -1, double salariu_ = 0) 
        : Person(name_, age_), salariu{salariu_} {}
    friend std::ostream& operator<<(std::ostream& os, const Employee& employee);
};

std::ostream& operator<<(std::ostream& os, const Employee& employee)
{
    os << static_cast<const Person&>(employee);
    os << "Employee: salariu = " << employee.salariu;
    return os;
}

class Parent : public Person {
private:
    int nrCopii;
public:
    Parent(std::string name_ = "", int age_ = -1, int nrCopii_ = -1) 
        : Person(name_, age_), nrCopii{nrCopii_} {}
    friend std::ostream& operator<<(std::ostream& os, const Parent& parent);
};

std::ostream& operator<<(std::ostream& os, const Parent& parent)
{
    os << static_cast<const Person&>(parent);
    os << "Parent: nrCopii = " << parent.nrCopii;
    return os;
}


int main()
{
    // ex1 - doar mostenire fara upcast/downcast
    /*
    Student student = Student("StudentNume1", 19, 9.64);
    Employee employee = Employee("EmployeeNume1", 30, 6000);
    Parent parent = Parent("ParentNume1", 35, 2);

    std::cout << student << std::endl;
    printf("---\n");
    std::cout << employee << std::endl;
    printf("---\n");
    std::cout << parent << std::endl;
    */


    // upcasting - pastram in pointer Person ob deriv tip Student/Employee/Parent
    Person *student  = new Student("StudentNume1", 19, 9.64);
    Person *employee = new Employee("EmployeeNume1", 30, 6000);
    Person *parent   = new Parent("ParentNume1", 35, 2);

    // downcasting - am obiecte Person* , vreau sa le afisez; nu stiu de ce tip
    // derivat din Person sunt obiectele, insa compiatorul stie tipul obiectului
    // la runtime in functie de clasa instantiata cu new/adresa de memorie trimisa
    Student *castedStudent   = static_cast<Student*>(student);
    Employee *castedEmployee = static_cast<Employee*>(employee);
    Parent *castedParent     = static_cast<Parent*>(parent);
    std::cout << *castedStudent << std::endl;
    printf("---\n");
    std::cout << *castedEmployee << std::endl;
    printf("---\n");
    std::cout << *castedParent << std::endl;

    printf("====\n");

    Student& castedStudent2   = static_cast<Student&>(*student);
    Employee& castedEmployee2 = static_cast<Employee&>(*employee);
    Parent& castedParent2     = static_cast<Parent&>(*parent);

    std::cout << castedStudent2 << std::endl;
    printf("---\n");
    std::cout << castedEmployee2 << std::endl;
    printf("---\n");
    std::cout << castedParent2 << std::endl;
    // Person* -> tinem Student* Employee* Parent*

    printf("====\n");
    std::vector<Person*> people;
    people.push_back(student);
    people.push_back(employee);
    people.push_back(parent);

    printf("==== AFISARE VECTOR Person* pentru ob tip Student/Employee/Parent\n");
    // typeid
    // dynamic_cast
    for(int i = 0; i < people.size(); i++)
    {
        if(dynamic_cast<Student*>(people[i]) != nullptr)
            std::cout << *dynamic_cast<Student*>(people[i]) << std::endl;
        if(dynamic_cast<Employee*>(people[i]) != nullptr)
            std::cout << *dynamic_cast<Employee*>(people[i]) << std::endl;
        if(dynamic_cast<Parent*>(people[i]) != nullptr)
            std::cout << *dynamic_cast<Parent*>(people[i]) << std::endl;
        printf("---\n");
    }

    delete student;
    delete employee;
    delete parent;

    return 0;
}


// class Test
// {
// private:
//     int x;
// public:
//     int GetX() { return x; }
//     void SetX(int x_) { x = x_; }
// };