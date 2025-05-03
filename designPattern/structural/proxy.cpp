#include <iostream>
#include <string>
using namespace std;

// Interface (Target)
class EmployeeTable
{
public:
    virtual void create(string name) = 0;
    virtual void deleteEmployee(string name) = 0;
    virtual void get(string name) = 0;
    virtual ~EmployeeTable() = default;
};

// Real Subject
class Employee : public EmployeeTable
{
public:
    void create(string name) override
    {
        cout << "Employee '" << name << "' created." << endl;
    }

    void deleteEmployee(string name) override
    {
        cout << "Employee '" << name << "' deleted." << endl;
    }

    void get(string name) override
    {
        cout << "Fetching details of employee: " << name << endl;
    }
};

// Proxy
class EmployeeProxy : public EmployeeTable
{
private:
    Employee *employee;
    string role;

public:
    EmployeeProxy(Employee *emp, const string &userRole) : employee(emp), role(userRole) {}

    void create(string name) override
    {
        if (role == "admin")
        {
            employee->create(name);
        }
        else
        {
            cout << "Access Denied: Only admin can create employee." << endl;
        }
    }

    void deleteEmployee(string name) override
    {
        if (role == "admin")
        {
            employee->deleteEmployee(name);
        }
        else
        {
            cout << "Access Denied: Only admin can delete employee." << endl;
        }
    }

    void get(string name) override
    {
        employee->get(name);
    }
};

// Client Code
int main()
{
    Employee *realEmployee = new Employee();

    cout << "--- Admin Access ---" << endl;
    EmployeeTable *adminAccess = new EmployeeProxy(realEmployee, "admin");
    adminAccess->create("Alice");
    adminAccess->get("Alice");
    adminAccess->deleteEmployee("Alice");

    cout << "\n--- User Access ---" << endl;
    EmployeeTable *userAccess = new EmployeeProxy(realEmployee, "user");
    userAccess->create("Bob");
    userAccess->get("Bob");
    userAccess->deleteEmployee("Bob");

    // Cleanup
    delete adminAccess;
    delete userAccess;
    delete realEmployee;

    return 0;
}
