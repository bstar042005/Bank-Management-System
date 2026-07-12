#include "Customer.h"

Customer::Customer() : Person()
{
    customerID = 0;
    password = "";
}

Customer::Customer(int customerID,
                   string name,
                   int age,
                   string phoneNumber,
                   string password)
    : Person(name, age, phoneNumber)
{
    this->customerID = customerID;
    this->password = password;
}

void Customer::setCustomerID(int customerID)
{
    this->customerID = customerID;
}

void Customer::setPassword(string password)
{
    this->password = password;
}

int Customer::getCustomerID() const
{
    return customerID;
}

string Customer::getPassword() const
{
    return password;
}

bool Customer::login(int id, string pass) const
{
    return (customerID == id && password == pass);
}

void Customer::display() const
{
    Person::display();

    cout << "Customer ID : " << customerID << endl;
}

Customer::~Customer()
{
}