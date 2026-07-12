#ifndef CUSTOMER_H
#define CUSTOMER_H

#include "Person.h"
#include "Account.h"

class Customer : public Person
{
private:
    int customerID;
    string password;
    Account* account;

public:
    // Constructors
    Customer();

    Customer(int customerID,
             string name,
             int age,
             string phoneNumber,
             string password);

    // Setters
    void setCustomerID(int customerID);
    void setPassword(string password);
    void setAccount(Account* account);

    // Getters
    int getCustomerID() const;
    string getPassword() const;
    Account* getAccount() const;

    // Login
    bool login(int id, string pass) const;

    // Display
    void display() const override;

    // Destructor
    ~Customer() override;
};

#endif