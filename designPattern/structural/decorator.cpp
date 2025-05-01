#include <iostream>
#include <string>

using namespace std;

// Component
class Coffee
{
public:
    virtual string getDescription() const = 0;
    virtual double getCost() const = 0;
    virtual ~Coffee() = default;
};

// Concrete Component
class SimpleCoffee : public Coffee
{
public:
    string getDescription() const override
    {
        return "Simple Coffee";
    }

    double getCost() const override
    {
        return 5.0; // Base cost
    }
};

// Decorator
class CoffeeDecorator : public Coffee
{
protected:
    Coffee *coffee; // "has-a" relationship

public:
    CoffeeDecorator(Coffee *c) : coffee(c) {}
    virtual ~CoffeeDecorator()
    {
        delete coffee; // Clean up wrapped object
    }
};

// Concrete Decorator: Milk
class MilkDecorator : public CoffeeDecorator
{
public:
    MilkDecorator(Coffee *c) : CoffeeDecorator(c) {}

    string getDescription() const override
    {
        return coffee->getDescription() + ", Milk";
    }

    double getCost() const override
    {
        return coffee->getCost() + 1.5;
    }
};

// Concrete Decorator: Sugar
class SugarDecorator : public CoffeeDecorator
{
public:
    SugarDecorator(Coffee *c) : CoffeeDecorator(c) {}

    string getDescription() const override
    {
        return coffee->getDescription() + ", Sugar";
    }

    double getCost() const override
    {
        return coffee->getCost() + 0.5;
    }
};

int main()
{
    // Simple Coffee
    Coffee *myCoffee = new SimpleCoffee();

    // Add milk
    myCoffee = new MilkDecorator(myCoffee);

    // Add sugar
    myCoffee = new SugarDecorator(myCoffee);

    // Final output
    cout << "Order: " << myCoffee->getDescription() << endl;
    cout << "Total Cost: $" << myCoffee->getCost() << endl;

    delete myCoffee; // Cleanup

    return 0;
}
