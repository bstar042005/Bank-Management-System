#include "Account.h"

Account::Account()
    : accountNumber(0), customerID(0), balance(0.0), accountType("")
{
}

Account::Account(int accountNumber,
                 int customerID,
                 double balance,
                 string accountType)
    : accountNumber(accountNumber),
      customerID(customerID),
      balance(balance),
      accountType(accountType)
{
}

int Account::getAccountNumber() const
{
    return accountNumber;
}

int Account::getCustomerID() const
{
    return customerID;
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
    if (amount <= 0)
    {
        cout << "Invalid Amount" << endl;
        return;
    }

    balance += amount;
}

Account::~Account()
{
}