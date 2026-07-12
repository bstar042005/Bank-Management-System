#include "SavingsAccount.h"

SavingsAccount::SavingsAccount()
    : Account()
{
    interestRate = 0;
}

SavingsAccount::SavingsAccount(int accountNumber,
                               double balance,
                               double interestRate)
    : Account(accountNumber, balance, "Savings")
{
    this->interestRate = interestRate;
}

void SavingsAccount::withdraw(double amount)
{
    if(amount <= 0)
    {
        cout << "Invalid Amount!" << endl;
        return;
    }

    if(amount > balance)
    {
        cout << "Insufficient Balance!" << endl;
        return;
    }

    balance -= amount;

    cout << "Withdrawal Successful!" << endl;
}

void SavingsAccount::calculateInterest()
{
    double interest = balance * interestRate / 100;

    balance += interest;

    cout << "Interest Added Successfully!" << endl;
}

void SavingsAccount::display() const
{
    cout << "----------- Savings Account -----------" << endl;

    cout << "Account Number : " << accountNumber << endl;

    cout << "Account Type   : " << accountType << endl;

    cout << "Balance        : " << balance << endl;

    cout << "Interest Rate  : " << interestRate << "%" << endl;
}

SavingsAccount::~SavingsAccount()
{
}