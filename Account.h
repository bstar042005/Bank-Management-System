#ifndef ACCOUNT_H
#define ACCOUNT_H

#include <iostream>
#include <string>

using namespace std;

class Account
{
protected:
    int accountNumber;
    double balance;
    string accountType;

public:
    // Constructors
    Account();
    Account(int accountNumber, double balance, string accountType);

    // Getters
    int getAccountNumber() const;
    double getBalance() const;
    string getAccountType() const;

    // Deposit (same for all account types)
    virtual void deposit(double amount);

    // Different for each account type
    virtual void withdraw(double amount) = 0;

    virtual void display() const = 0;

    virtual ~Account();
};

#endif