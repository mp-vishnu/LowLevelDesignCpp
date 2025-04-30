#include <iostream>
#include <string>

using namespace std;

// Product Class
class Car
{
public:
    string engine;
    string body;
    string wheels;

    void showSpecifications()
    {
        cout << "Car Specifications:\n";
        cout << " Engine: " << engine << endl;
        cout << " Body: " << body << endl;
        cout << " Wheels: " << wheels << endl;
    }
};

// Builder Interface
class CarBuilder
{
public:
    virtual ~CarBuilder() {}
    virtual void buildEngine() = 0;
    virtual void buildBody() = 0;
    virtual void buildWheels() = 0;
    virtual Car *getCar() = 0;
};

// Concrete Builder: Sports Car
class SportsCarBuilder : public CarBuilder
{
private:
    Car *car;

public:
    SportsCarBuilder()
    {
        car = new Car();
    }

    void buildEngine() override
    {
        car->engine = "V8 Twin Turbo";
    }

    void buildBody() override
    {
        car->body = "Aerodynamic Carbon Fiber";
    }

    void buildWheels() override
    {
        car->wheels = "Low-profile Racing Tires";
    }

    Car *getCar() override
    {
        return car;
    }
};

// Concrete Builder: SUV
class SUVCarBuilder : public CarBuilder
{
private:
    Car *car;

public:
    SUVCarBuilder()
    {
        car = new Car();
    }

    void buildEngine() override
    {
        car->engine = "V6 Diesel";
    }

    void buildBody() override
    {
        car->body = "Sturdy Steel Frame";
    }

    void buildWheels() override
    {
        car->wheels = "All-Terrain Tires";
    }

    Car *getCar() override
    {
        return car;
    }
};

// Director Class
class CarDirector
{
private:
    CarBuilder *builder;

public:
    CarDirector(CarBuilder *builder)
    {
        this->builder = builder;
    }

    void constructCar()
    {
        builder->buildEngine();
        builder->buildBody();
        builder->buildWheels();
    }
};

int main()
{
    // --- Using Director ---
    cout << "--- Building Sports Car using Director ---\n";
    SportsCarBuilder sportsBuilder;
    CarDirector director(&sportsBuilder);
    director.constructCar();
    Car *sportsCar = sportsBuilder.getCar();
    sportsCar->showSpecifications();
    delete sportsCar;

    // --- Without using Director ---
    cout << "\n--- Building SUV manually (without Director) ---\n";
    SUVCarBuilder suvBuilder;
    suvBuilder.buildEngine();
    suvBuilder.buildBody();
    suvBuilder.buildWheels();
    Car *suv = suvBuilder.getCar();
    suv->showSpecifications();
    delete suv;

    return 0;
}
