#include <iostream>
using namespace std;

// Abstract Products
class ProductA
{
public:
    virtual void info() = 0;
    virtual ~ProductA() {}
};

class ProductB
{
public:
    virtual void info() = 0;
    virtual ~ProductB() {}
};

// Concrete Products - Family 1
class ProductA1 : public ProductA
{
public:
    void info() override
    {
        cout << "ProductA1\n";
    }
};

class ProductB1 : public ProductB
{
public:
    void info() override
    {
        cout << "ProductB1\n";
    }
};

// Concrete Products - Family 2
class ProductA2 : public ProductA
{
public:
    void info() override
    {
        cout << "ProductA2\n";
    }
};

class ProductB2 : public ProductB
{
public:
    void info() override
    {
        cout << "ProductB2\n";
    }
};

// Abstract Factory
class AbstractFactory
{
public:
    virtual ProductA *createProductA() = 0;
    virtual ProductB *createProductB() = 0;
    virtual ~AbstractFactory() {}
};

// ConcreteFactory1 creates ProductA1 and ProductB1
class ConcreteFactory1 : public AbstractFactory
{
public:
    ProductA *createProductA() override
    {
        return new ProductA1();
    }

    ProductB *createProductB() override
    {
        return new ProductB1();
    }
};

// ConcreteFactory2 creates ProductA2 and ProductB2
class ConcreteFactory2 : public AbstractFactory
{
public:
    ProductA *createProductA() override
    {
        return new ProductA2();
    }

    ProductB *createProductB() override
    {
        return new ProductB2();
    }
};

// Client code
void clientCode(AbstractFactory *factory)
{
    ProductA *pa = factory->createProductA();
    ProductB *pb = factory->createProductB();

    pa->info();
    pb->info();

    delete pa;
    delete pb;
}

int main()
{
    cout << "Using Factory1:\n";
    AbstractFactory *factory1 = new ConcreteFactory1();
    clientCode(factory1);
    delete factory1;

    cout << "\nUsing Factory2:\n";
    AbstractFactory *factory2 = new ConcreteFactory2();
    clientCode(factory2);
    delete factory2;

    return 0;
}
