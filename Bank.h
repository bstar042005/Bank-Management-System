#ifndef BANK_H
#define BANK_H

#include <vector>
#include "Customer.h"

using namespace std;

class Bank
{
private:

    vector<Customer> customers;

public:

    void createCustomer(Customer customer);

    Customer* login(int id,string password);

    Customer* searchCustomer(int id);

    void displayCustomers() const;

    void deposit(int customerID,double amount);

    void withdraw(int customerID,double amount);

    void checkBalance(int customerID);

};

#endif