#include "Account.h"

Account::Account()
{
    accountNumber = 0;
    balance = 0;
    accountType = "";
}

Account::Account(int accountNumber, double balance, string accountType)
{
    this->accountNumber = accountNumber;
    this->balance = balance;
    this->accountType = accountType;
}

int Account::getAccountNumber() const
{
    return accountNumber;
}

double Account::getBalance() const
{
    return balance;
}

string Account::getAccountType() const
{
    return accountType;
}

void Account::deposit(double amount)
{
    if(amount > 0)
    {
        balance += amount;
        cout << "Deposit Successful!" << endl;
    }
    else
    {
        cout << "Invalid Amount!" << endl;
    }
}

Account::~Account()
{
}