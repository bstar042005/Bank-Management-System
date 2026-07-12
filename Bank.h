#ifndef BANK_H
#define BANK_H

#include <vector>
#include <fstream>

#include "Customer.h"
#include "SavingsAccount.h"
#include "CurrentAccount.h"

using namespace std;

class Bank
{
private:
    vector<Customer> customers;
    vector<Account*> accounts;

public:
    Bank();

    // Customer Functions
    void addCustomer(const Customer& customer);

    Customer* findCustomer(int customerID);

    void displayCustomer(int customerID);

    void displayAllCustomers();

    void displayCustomerAccounts(int customerID);

    // Account Functions
    void createSavingsAccount(int accountNumber,
                              int customerID,
                              double balance,
                              double interestRate);

    void createCurrentAccount(int accountNumber,
                              int customerID,
                              double balance,
                              double overdraftLimit);

    Account* findAccount(int accountNumber);

    void displayAccount(int accountNumber);

    void displayAllAccounts();

    // Transactions
    void deposit(int accountNumber,
                 double amount);

    void withdraw(int accountNumber,
                  double amount);

    void transfer(int sender,
                  int receiver,
                  double amount);

    // File Handling
    void saveCustomers();

    void loadCustomers();

    void saveAccounts();

    void loadAccounts();

    ~Bank();
};

#endif