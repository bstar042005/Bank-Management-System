#ifndef CURRENTACCOUNT_H
#define CURRENTACCOUNT_H

#include "Account.h"

class CurrentAccount : public Account
{
private:
    double overdraftLimit;

public:
    // Constructors
    CurrentAccount();
    CurrentAccount(int accountNumber,
                   double balance,
                   double overdraftLimit);

    // Override functions
    void withdraw(double amount) override;

    void display() const override;

    // Destructor
    ~CurrentAccount();
};

#endif