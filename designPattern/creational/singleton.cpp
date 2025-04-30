#include <iostream>
#include <mutex>

using namespace std;

class PaymentGateway
{
private:
    static PaymentGateway *instance;
    static mutex mtx;

    // Private Constructor
    PaymentGateway()
    {
        cout << "PaymentGateway Initialized." << endl;
    }

    // Delete Copy Constructor
    PaymentGateway(const PaymentGateway &) = delete;

    // Delete Assignment Operator
    PaymentGateway &operator=(const PaymentGateway &) = delete;

public:
    // Static method to get the instance (Thread-safe)
    static PaymentGateway *getInstance()
    {
        lock_guard<mutex> lock(mtx); // Ensures thread safety
        if (instance == nullptr)
        {
            instance = new PaymentGateway();
        }
        return instance;
    }

    void processPayment(double amount)
    {
        cout << "Processing payment of ₹" << amount << endl;
    }
};

// Initialize static members
PaymentGateway *PaymentGateway::instance = nullptr;
mutex PaymentGateway::mtx;

int main()
{
    PaymentGateway *pg1 = PaymentGateway::getInstance();
    pg1->processPayment(1500.00);

    PaymentGateway *pg2 = PaymentGateway::getInstance();
    pg2->processPayment(3000.00);

    // Verifying both instances are the same
    if (pg1 == pg2)
    {
        cout << "Both instances are the same. Singleton works!" << endl;
    }
    else
    {
        cout << "Instances are different. Singleton failed!" << endl;
    }

    return 0;
}
