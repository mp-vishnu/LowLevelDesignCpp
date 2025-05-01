#include <iostream>
#include <string>
using namespace std;

// Prototype Interface
class Prototype
{
public:
    virtual Prototype *clone() const = 0;
    virtual void show() const = 0;
    virtual ~Prototype() {}
};

// ConcretePrototype
class Employee : public Prototype
{
private:
    string name;
    int age;

public:
    Employee(string name, int age) : name(name), age(age) {}

    // Implement clone()
    Prototype *clone() const override
    {
        return new Employee(*this); // Copy constructor
    }

    void show() const override
    {
        cout << "Employee: " << name << ", Age: " << age << endl;
    }
};

// Client Code
int main()
{
    // Original object
    Employee *original = new Employee("Alice", 30);
    original->show();

    // Clone object
    Prototype *copy = original->clone();
    copy->show();

    delete original;
    delete copy;

    return 0;
}
