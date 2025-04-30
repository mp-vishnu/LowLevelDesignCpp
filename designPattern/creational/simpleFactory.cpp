#include <iostream>
#include <string>
using namespace std;

// Product Interface
class Product
{
public:
    virtual void use() = 0;
    virtual ~Product() {}
};

// ConcreteProductA
class ConcreteProductA : public Product
{
public:
    void use() override
    {
        cout << "Using Product A" << endl;
    }
};

// ConcreteProductB
class ConcreteProductB : public Product
{
public:
    void use() override
    {
        cout << "Using Product B" << endl;
    }
};

// Simple Factory
class SimpleFactory
{
public:
    static Product *createProduct(const string &type)
    {
        if (type == "A")
            return new ConcreteProductA();
        else if (type == "B")
            return new ConcreteProductB();
        else
            return nullptr;
    }
};

// Client
int main()
{
    Product *p1 = SimpleFactory::createProduct("A");
    if (p1)
    {
        p1->use();
        delete p1;
    }

    Product *p2 = SimpleFactory::createProduct("B");
    if (p2)
    {
        p2->use();
        delete p2;
    }

    Product *p3 = SimpleFactory::createProduct("C"); // Unknown type
    if (!p3)
    {
        cout << "Invalid product type!" << endl;
    }

    return 0;
}
