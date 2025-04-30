#include <iostream>
using namespace std;

// Product interface
class Product
{
public:
    virtual void operation() = 0;
    virtual ~Product() {}
};

// ConcreteProduct
class ConcreteProductA : public Product
{
public:
    void operation() override
    {
        cout << "ConcreteProductA operation\n";
    }
};

class ConcreteProductB : public Product
{
public:
    void operation() override
    {
        cout << "ConcreteProductB operation\n";
    }
};

// Creator (factoryMethod returns Product*)
class Creator
{
public:
    virtual Product *factoryMethod() = 0;

    void someOperation()
    {
        Product *product = factoryMethod(); // uses-a
        product->operation();
        delete product;
    }

    virtual ~Creator() {}
};

// ConcreteCreatorA
class ConcreteCreatorA : public Creator
{
public:
    Product *factoryMethod() override
    {
        return new ConcreteProductA();
    }
};

// ConcreteCreatorB
class ConcreteCreatorB : public Creator
{
public:
    Product *factoryMethod() override
    {
        return new ConcreteProductB();
    }
};

// Client
int main()
{
    Creator *creatorA = new ConcreteCreatorA();
    creatorA->someOperation();

    Creator *creatorB = new ConcreteCreatorB();
    creatorB->someOperation();

    delete creatorA;
    delete creatorB;

    return 0;
}
