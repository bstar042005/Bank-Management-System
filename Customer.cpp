#include "Customer.h"

Customer::Customer()
    : Person(), customerID(0), password(""), account(nullptr)
{
}

Customer::Customer(int customerID,
                   string name,
                   int age,
                   string phoneNumber,
                   string password)
    : Person(name, age, phoneNumber),
      customerID(customerID),
      password(password),
      account(nullptr)
{
}

void Customer::setCustomerID(int customerID)
{
    this->customerID = customerID;
}

void Customer::setPassword(string password)
{
    this->password = password;
}

void Customer::setAccount(Account* account)
{
    this->account = account;
}

Account* Customer::getAccount() const
{
    return account;
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

    if (account != nullptr)
    {
        account->display();
    }
}

Customer::~Customer()
{
    // Do NOT delete account here.
    // Bank owns the Account objects and deletes them.
    account = nullptr;
}