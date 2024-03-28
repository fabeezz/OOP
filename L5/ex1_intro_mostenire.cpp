#include <iostream>
#include <vector>
#include <typeinfo>

// folosim double in loc de float pentru precizie mai buna la acelasi cost de timp procesor
class Person {
protected:
    std::string name;
    int age;
public:
    Person(std::string name_ = "", int age_ = -1) : name{name_}, age{age_} {}
    friend std::ostream& operator<<(std::ostream& os, const Person& person);
private:
    // private methods
};

std::ostream& operator<<(std::ostream& os, const Person& person)
{
    os << "Person: ";
    os << "name: " << person.name << "\t" << person.age << "\n";
    return os;
}

class Employee : public Person {
private:
    float wage;
public:
    Employee(std::string name_ = "", int age_ = -1, float wage_ = 0.0f) : Person(name_, age_), wage{wage_} {}
    friend std::ostream& operator<<(std::ostream& os, const Employee& employee);
};

std::ostream& operator<<(std::ostream& os, const Employee& employee)
{
    os << static_cast<Person>(employee); // de ilustrat esuare
    os << "Employee: " << employee.wage;
    return os;
}

class Student : public Person {
private:
    float medie;
public:
    Student(std::string name_ = "", int age_ = -1, float medie_ = 0.0f) : Person(name_, age_), medie{medie_} {}
    friend std::ostream& operator<<(std::ostream& os, const Student& student);
};

std::ostream& operator<<(std::ostream& os, const Student& student)
{
    os << static_cast<Person>(student); // de ilustrat esuare
    os << "Student: medie: " << student.medie;
    return os;
}

class Parent : public Person {
private:
    int numChildren;
public:
    Parent(std::string name_ = "", int age_ = -1, int numChildren_ = -1) : Person(name_, age_), numChildren{numChildren_} {}
    friend std::ostream& operator<<(std::ostream& os, const Parent& parent);
};

std::ostream& operator<<(std::ostream& os, const Parent& parent)
{
    os << static_cast<Person>(parent); // de ilustrat esuare
    os << "Parent: numChildren: " << parent.numChildren;
    return os;
}


int main(void)
{
    // exemple upcasting - Employee/Student/Parent salvat drept Person
    Person *employee   = new Employee("EmployeeName1", 27, 5000.0f);
    Person *student    = new Student("StudentName1", 19, 9.56f);
    Person *parent     = new Parent("ParentName1", 30, 2);

    Employee employee2  = Employee("EmployeeName1", 27, 5000.0f);
    Student student2    = Student("StudentName1", 19, 9.56f);
    Parent parent2      = Parent("ParentName1", 30, 2);

    // exemple downcasting - obiecte tip Person transformate in Employee/Student/Parent
    Employee *castedEmployee = static_cast<Employee*>(employee); // transformare in pointer
    Student  *castedStudent  = static_cast<Student*>(student);   // transformare in pointer
    Parent&   castedParent   = static_cast<Parent&>(*parent);    // transformare in referinta

    std::cout << *castedEmployee << std::endl; // exemplu downcasting
    std::cout << "---\n";
    std::cout << *castedStudent << std::endl;
    std::cout << "---\n";
    std::cout << castedParent << std::endl;
    
    // std::vector<Person*> persoane;
    // persoane.push_back(employee);
    // persoane.push_back(student);
    // persoane.push_back(parent);
    // std::cout << "Afisari vector de persoane:\n";
    // for(auto pers : persoane)
    // {
    //     // Student *dummyStudent;
    //     // Employee *dummyEmployee;
    //     // Parent *dummyParent;

    //     if(dynamic_cast<Student*>(pers) != nullptr)
    //     {
    //         std::cout << *static_cast<Student*>(pers);
    //     }
    //     if(typeid(pers) == typeid(Employee*))
    //     {
    //         std::cout << *static_cast<Employee*>(pers);
    //     }
    //     if(typeid(pers) == typeid(Parent*))
    //     {
    //         std::cout << *static_cast<Parent*>(pers);
    //     }
    //     printf("---\n");
    // }

    delete employee;
    delete student;
    delete parent;

    return 0;
}