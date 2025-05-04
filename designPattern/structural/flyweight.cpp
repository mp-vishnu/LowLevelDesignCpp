#include <iostream>
#include <unordered_map>

using namespace std;

// Flyweight Interface
class Font
{
public:
    virtual void display(const string &text, int x, int y) = 0;
    virtual ~Font() {}
};

// Concrete Flyweight
class ConcreteFont : public Font
{
private:
    string fontName; // <-- ✅ Intrinsic state (shared, internal)

public:
    ConcreteFont(const string &name) : fontName(name) {}

    void display(const string &text, int x, int y) override
    {
        // text, x, y are extrinsic state
        cout << "Displaying '" << text << "' using font '" << fontName
             << "' at position (" << x << ", " << y << ")" << endl;
    }
};

// Flyweight Factory
class FontFactory
{
private:
    unordered_map<string, Font *> fonts; // Flyweight pool

public:
    Font *getFont(const string &fontName)
    {
        if (fonts.find(fontName) == fonts.end())
        {
            fonts[fontName] = new ConcreteFont(fontName);
        }
        return fonts[fontName];
    }

    ~FontFactory()
    {
        for (auto &pair : fonts)
        {
            delete pair.second;
        }
    }
};

// Client
int main()
{
    FontFactory factory;

    Font *font1 = factory.getFont("Arial");
    Font *font2 = factory.getFont("Arial"); // Reuses the same object
    Font *font3 = factory.getFont("Times");

    font1->display("Hello", 10, 20);      // "Hello" + position = extrinsic
    font2->display("World", 30, 40);      // still uses the same "Arial" instance
    font3->display("Times Text", 50, 60); // uses different font

    return 0;
}
