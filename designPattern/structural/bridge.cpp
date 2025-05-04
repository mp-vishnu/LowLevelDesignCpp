#include <iostream>
using namespace std;

// Implementor
class DrawingAPI
{
public:
    virtual void drawCircle(double x, double y, double radius) = 0;
    virtual ~DrawingAPI() = default;
};

// ConcreteImplementors
class OpenGLAPI : public DrawingAPI
{
public:
    void drawCircle(double x, double y, double radius) override
    {
        cout << "OpenGLAPI: Drawing circle at (" << x << ", " << y << ") with radius " << radius << endl;
    }
};

class DirectXAPI : public DrawingAPI
{
public:
    void drawCircle(double x, double y, double radius) override
    {
        cout << "DirectXAPI: Drawing circle at (" << x << ", " << y << ") with radius " << radius << endl;
    }
};

// Abstraction
class Shape
{
protected:
    DrawingAPI *api;

public:
    Shape(DrawingAPI *drawingAPI) : api(drawingAPI) {}
    virtual void draw() = 0;
    virtual ~Shape() = default;
};

// Refined Abstraction
class Circle : public Shape
{
    double x, y, radius;

public:
    Circle(double x, double y, double r, DrawingAPI *api) : Shape(api), x(x), y(y), radius(r) {}
    void draw() override
    {
        api->drawCircle(x, y, radius);
    }
};

// Client
int main()
{
    DrawingAPI *opengl = new OpenGLAPI();
    DrawingAPI *directx = new DirectXAPI();

    Shape *circle1 = new Circle(10, 20, 5, opengl);
    Shape *circle2 = new Circle(15, 25, 7, directx);

    circle1->draw(); // Uses OpenGL
    circle2->draw(); // Uses DirectX

    delete opengl;
    delete directx;
    delete circle1;
    delete circle2;

    return 0;
}
