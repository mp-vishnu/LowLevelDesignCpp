#include <iostream>
using namespace std;

// Target Interface
class USBCport
{
public:
    virtual void connectWithUSBC() = 0;
    virtual ~USBCport() = default;
};

// Adaptee - Existing Micro USB charger
class microUSBcharger
{
public:
    void connectWithMicroUSB()
    {
        cout << "Micro USB charger connected and charging..." << endl;
    }
};

// Adapter - Converts Micro USB to USB-C
class USBAdapter : public USBCport
{
private:
    microUSBcharger *microUSB;

public:
    USBAdapter(microUSBcharger *charger) : microUSB(charger) {}

    void connectWithUSBC() override
    {
        cout << "Adapter converting USB-C to Micro USB..." << endl;
        microUSB->connectWithMicroUSB();
    }
};

int main()
{
    // Existing Micro USB charger (Adaptee)
    microUSBcharger *oldCharger = new microUSBcharger();

    // Adapter to convert Micro USB to USB-C
    USBCport *adapter = new USBAdapter(oldCharger);

    // Client directly using the adapter
    cout << "Client connecting using USB-C port:\n";
    adapter->connectWithUSBC();

    // Cleanup
    delete adapter;
    delete oldCharger;

    return 0;
}
