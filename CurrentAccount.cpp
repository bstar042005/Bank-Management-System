#include "CurrentAccount.h"

CurrentAccount::CurrentAccount()
    : Account(), overdraftLimit(0.0)
{
}

CurrentAccount::CurrentAccount(int accountNumber,
                               int customerID,
                               double balance,
                               double overdraftLimit)
    : Account(accountNumber, customerID, balance, "Current"),
      overdraftLimit(overdraftLimit)
{
}

bool CurrentAccount::withdraw(double amount)
{
    if (amount <= 0)
    {
        cout << "Invalid Amount!" << endl;
        return false;
    }

    if (amount > balance + overdraftLimit)
    {
        cout << "Withdrawal exceeds overdraft limit!" << endl;
        return false;
    }

    balance -= amount;

    cout << "Withdrawal Successful!" << endl;

    return true;
}

void CurrentAccount::display() const
{
    cout << "----------- Current Account -----------" << endl;
    cout << "Account Number : " << accountNumber << endl;
    cout << "Customer ID    : " << customerID << endl;
    cout << "Account Type   : " << accountType << endl;
    cout << "Balance        : " << balance << endl;
    cout << "Overdraft Limit: " << overdraftLimit << endl;
}

void CurrentAccount::save(ofstream &out) const
{
    out << accountType << endl;
    out << accountNumber << endl;
    out << customerID << endl;
    out << balance << endl;
    out << overdraftLimit << endl;
}

CurrentAccount::~CurrentAccount()
{
}