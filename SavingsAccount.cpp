#include "SavingsAccount.h"

SavingsAccount::SavingsAccount()
    : Account(), interestRate(0.0)
{
}

SavingsAccount::SavingsAccount(int accountNumber,
                               int customerID,
                               double balance,
                               double interestRate)
    : Account(accountNumber, customerID, balance, "Savings"),
      interestRate(interestRate)
{
}

bool SavingsAccount::withdraw(double amount)
{
    if (amount <= 0)
    {
        cout << "Invalid Amount!" << endl;
        return false;
    }

    if (amount > balance)
    {
        cout << "Insufficient Balance!" << endl;
        return false;
    }

    balance -= amount;

    cout << "Withdrawal Successful!" << endl;

    return true;
}

void SavingsAccount::calculateInterest()
{
    double interest = balance * interestRate / 100.0;

    balance += interest;

    cout << "Interest Added Successfully!" << endl;
}

void SavingsAccount::display() const
{
    cout << "----------- Savings Account -----------" << endl;
    cout << "Account Number : " << accountNumber << endl;
    cout << "Customer ID    : " << customerID << endl;
    cout << "Account Type   : " << accountType << endl;
    cout << "Balance        : " << balance << endl;
    cout << "Interest Rate  : " << interestRate << "%" << endl;
}

void SavingsAccount::save(ofstream& out) const
{
    out << accountType << endl
        << accountNumber << endl
        << customerID << endl
        << balance << endl
        << interestRate << endl;
}

SavingsAccount::~SavingsAccount()
{
}