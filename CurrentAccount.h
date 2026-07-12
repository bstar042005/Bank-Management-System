#ifndef CURRENTACCOUNT_H
#define CURRENTACCOUNT_H

#include "Account.h"

class CurrentAccount : public Account
{
private:
    double overdraftLimit;

public:
    CurrentAccount();

    CurrentAccount(int accountNumber,
                   int customerID,
                   double balance,
                   double overdraftLimit);

    bool withdraw(double amount) override;

    void display() const override;

    void save(ofstream &out) const override;   // <-- ADD THIS

    ~CurrentAccount() override;
};

#endif