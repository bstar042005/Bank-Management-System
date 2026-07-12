#include "CurrentAccount.h"

CurrentAccount::CurrentAccount()
    : Account()
{
    overdraftLimit = 0;
}

CurrentAccount::CurrentAccount(int accountNumber,
                               double balance,
                               double overdraftLimit)
    : Account(accountNumber, balance, "Current")
{
    this->overdraftLimit = overdraftLimit;
}

void CurrentAccount::withdraw(double amount)
{
    if(amount <= 0)
    {
        cout << "Invalid Amount!" << endl;
        return;
    }

    if(amount > balance + overdraftLimit)
    {
        cout << "Withdrawal exceeds overdraft limit!" << endl;
        return;
    }

    balance -= amount;

    cout << "Withdrawal Successful!" << endl;
}

void CurrentAccount::display() const
{
    cout << "----------- Current Account -----------" << endl;

    cout << "Account Number : " << accountNumber << endl;

    cout << "Account Type   : " << accountType << endl;

    cout << "Balance        : " << balance << endl;

    cout << "Overdraft      : " << overdraftLimit << endl;
}

CurrentAccount::~CurrentAccount()
{
}