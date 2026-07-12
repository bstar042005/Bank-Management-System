#ifndef SAVINGSACCOUNT_H
#define SAVINGSACCOUNT_H

#include "Account.h"

class SavingsAccount : public Account
{
private:
    double interestRate;

public:
    // Constructors
    SavingsAccount();
    SavingsAccount(int accountNumber, double balance, double interestRate);

    // Functions
    void withdraw(double amount) override;

    void display() const override;

    void calculateInterest();

    // Destructor
    ~SavingsAccount();
};

#endif