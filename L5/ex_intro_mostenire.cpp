#include <iostream>

class Person
{
protected:
    std::string name;
    int age;

public:
    Person(std::string name_ = "", int age_ = -1) : name{name_}, age{age_} {}
    friend std::ostream &operator<<(std::ostream &os, const Person &person);

private:
    /// private methods
};

std::ostream &operator<<(std::ostream &os, const Person &person)
{
    os << "Person: ";
    os << "Name: " << person.name << "\t"
       << "Age: " << person.age << "\n";
    return os;
}

class Employee : public Person
{
private:
    float wage;

public:
    Employee(std::string name_ = "", int age_ = -1, float wage_ = 0.0f) : Person(name_, age_), wage{wage_} {}
    friend std::ostream &operator<<(std::ostream &os, const Employee &employee);
};

std::ostream &operator<<(std::ostream &os, const Employee &employee)
{
    os << static_cast<Person>(employee); //
    os << "Employee: " << employee.name;
    return os;
}

class Student : public Person
{
private:
    double medie; // precizie mai buna pt acelasi cost pe CPU

public:
    Student(std::string name_ = "", int age_ = -1, float medie_ = 0.0f) : Person(name_, age_), medie{medie_} {}
    friend std::ostream &operator<<(std::ostream &os, const Student &student);
};

std::ostream &operator<<(std::ostream &os, const Student &student)
{
    os << static_cast<Person>(student); //
    os << "Medie: " << student.medie;
    return os;
}

class Parent : public Person
{
private:
    int numChildren; // precizie mai buna pt acelasi cost pe CPU

public:
    Parent(std::string name_ = "", int age_ = -1, int numChildren_ = -1) : Person(name_, age_), numChildren{numChildren_} {}
    friend std::ostream &operator<<(std::ostream &os, const Parent &parent);
};

std::ostream &operator<<(std::ostream &os, const Parent &parent)
{
    os << static_cast<Person>(parent); //
    os << "Nr. copii: " << parent.numChildren;
    return os;
}

int main()
{
    Employee employee = Employee("EmployeeName1", 27, 5000.0f);
    Student student = Student("StudentName1", 19, 9.7);
    Parent parent = Parent("ParentName1", 30, 2);

    // ex _upcasting_ - E/S/P salvat drept Person
    Person employee2 = Employee("EmployeeName2", 27, 5000.0f);
    Person student2 = Student("StudentName2", 19, 9.7);
    Person parent2 = Parent("ParentName2", 30, 2);

    // ex _downcasting_ - obiecte tip Person -> E/S/P
    Employee *castedEmployee = static_cast<Employee *>(&employee2);
    Student *castedStudent = static_cast<Student *>(&student2);
    Parent &castedParent = static_cast<Parent &>(parent2);

    std::cout << static_cast<Employee *>(&employee) << std::endl; // exemplu downcasting
    std::cout << "----------------------------------------" << std::endl;
    std::cout << employee << std::endl;
    std::cout << "----------------------------------------" << std::endl;
    std::cout << student << std::endl;
    std::cout << "----------------------------------------" << std::endl;
    std::cout << parent << std::endl;
    std::cout << "----------------------------------------" << std::endl;
    return 0;
}