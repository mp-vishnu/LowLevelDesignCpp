#include <iostream>
using namespace std;

// Subsystem class 1: Inventory
class Inventory
{
public:
    void updateStock()
    {
        cout << "Inventory: Stock updated." << endl;
    }
};

// Subsystem class 2: Payment
class Payment
{
public:
    void processPayment()
    {
        cout << "Payment: Payment processed successfully." << endl;
    }
};

// Subsystem class 3: Shipping
class Shipping
{
public:
    void arrangeShipping()
    {
        cout << "Shipping: Shipping arranged." << endl;
    }
};

// Facade class: OrderFacade
class OrderFacade
{
    Inventory inventory;
    Payment payment;
    Shipping shipping;

public:
    void placeOrder()
    {
        cout << "--- Placing Order ---" << endl;
        inventory.updateStock();
        payment.processPayment();
        shipping.arrangeShipping();
        cout << "--- Order Completed ---" << endl;
    }
};

// Client code
int main()
{
    OrderFacade order;
    order.placeOrder();
    return 0;
}
