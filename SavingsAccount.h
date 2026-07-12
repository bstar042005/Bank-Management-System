#ifndef SAVINGSACCOUNT_H
#define SAVINGSACCOUNT_H

#include "Account.h"

class SavingsAccount : public Account
{
private:
    double interestRate;

public:
    SavingsAccount();

    SavingsAccount(int accountNumber,
                   int customerID,
                   double balance,
                   double interestRate);

    double getInterestRate() const;

    bool withdraw(double amount) override;

    void display() const override;

    void save(ofstream& out) const override;

    void calculateInterest();

    ~SavingsAccount() override;
};

#endif