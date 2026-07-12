#ifndef ACCOUNT_H
#define ACCOUNT_H

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

class Account
{
protected:
    int accountNumber;
    int customerID;
    double balance;
    string accountType;

public:
    // Constructors
    Account();

    Account(int accountNumber,
            int customerID,
            double balance,
            string accountType);

    // Getters
    int getAccountNumber() const;
    int getCustomerID() const;
    double getBalance() const;
    string getAccountType() const;

    // Deposit
    void deposit(double amount);

    // Pure Virtual Functions
    virtual bool withdraw(double amount) = 0;
    virtual void display() const = 0;
    virtual void save(ofstream &out) const = 0;

    // Virtual Destructor
    virtual ~Account();
};

#endif