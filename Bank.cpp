#include "Bank.h"

Bank::Bank()
{
    loadCustomers();
    loadAccounts();
}

// =========================
// Customer Functions
// =========================

void Bank::addCustomer(const Customer &customer)
{
    if (findCustomer(customer.getCustomerID()) != nullptr)
    {
        cout << "Customer ID already exists!" << endl;
        return;
    }

    customers.push_back(customer);
    cout << "Customer added successfully!" << endl;
}

Customer* Bank::findCustomer(int customerID)
{
    for (auto &customer : customers)
    {
        if (customer.getCustomerID() == customerID)
        {
            return &customer;
        }
    }

    return nullptr;
}

void Bank::displayCustomer(int customerID)
{
    Customer* customer = findCustomer(customerID);

    if (customer == nullptr)
    {
        cout << "Customer not found!" << endl;
        return;
    }

    customer->display();
}

void Bank::displayAllCustomers()
{
    if (customers.empty())
    {
        cout << "No customers found!" << endl;
        return;
    }

    for (const auto &customer : customers)
    {
        customer.display();
        cout << "-----------------------------" << endl;
    }
}

void Bank::displayCustomerAccounts(int customerID)
{
    Customer* customer = findCustomer(customerID);

    if (customer == nullptr)
    {
        cout << "Customer not found!" << endl;
        return;
    }

    bool found = false;

    for (const auto &account : accounts)
    {
        if (account->getCustomerID() == customerID)
        {
            account->display();
            cout << endl;
            found = true;
        }
    }

    if (!found)
    {
        cout << "No Account Found for this Customer!" << endl;
    }
}

// =========================
// Account Functions
// =========================

void Bank::createSavingsAccount(int accountNumber,
                                int customerID,
                                double balance,
                                double interestRate)
{
    if (findAccount(accountNumber) != nullptr)
    {
        cout << "Account Number already exists!" << endl;
        return;
    }

    Customer* customer = findCustomer(customerID);

    if (customer == nullptr)
    {
        cout << "Customer not found!" << endl;
        return;
    }

    SavingsAccount* account = new SavingsAccount(
        accountNumber,
        customerID,
        balance,
        interestRate
    );

    accounts.push_back(account);

    customer->setAccount(account);

    cout << "Savings Account created successfully!" << endl;
}

void Bank::createCurrentAccount(int accountNumber,
                                int customerID,
                                double balance,
                                double overdraftLimit)
{
    if (findAccount(accountNumber) != nullptr)
    {
        cout << "Account Number already exists!" << endl;
        return;
    }

    Customer* customer = findCustomer(customerID);

    if (customer == nullptr)
    {
        cout << "Customer not found!" << endl;
        return;
    }

    CurrentAccount* account = new CurrentAccount(
        accountNumber,
        customerID,
        balance,
        overdraftLimit
    );

    accounts.push_back(account);

    customer->setAccount(account);

    cout << "Current Account created successfully!" << endl;
}

Account* Bank::findAccount(int accountNumber)
{
    for (auto account : accounts)
    {
        if (account->getAccountNumber() == accountNumber)
        {
            return account;
        }
    }

    return nullptr;
}

// =========================
// Transactions
// =========================

void Bank::deposit(int accountNumber, double amount)
{
    Account* account = findAccount(accountNumber);

    if (account == nullptr)
    {
        cout << "Account not found!" << endl;
        return;
    }

    account->deposit(amount);

    cout << "Deposit Successful!" << endl;
}

void Bank::withdraw(int accountNumber, double amount)
{
    Account* account = findAccount(accountNumber);

    if (account == nullptr)
    {
        cout << "Account not found!" << endl;
        return;
    }

    if (account->withdraw(amount))
    {
        cout << "Withdrawal Successful!" << endl;
    }
    else
    {
        cout << "Withdrawal Failed!" << endl;
    }
}

void Bank::transfer(int sender, int receiver, double amount)
{
    Account* senderAccount = findAccount(sender);
    Account* receiverAccount = findAccount(receiver);

    if (senderAccount == nullptr)
    {
        cout << "Sender Account not found!" << endl;
        return;
    }

    if (receiverAccount == nullptr)
    {
        cout << "Receiver Account not found!" << endl;
        return;
    }

    if (senderAccount->withdraw(amount))
    {
        receiverAccount->deposit(amount);

        cout << "Transfer Successful!" << endl;
    }
    else
    {
        cout << "Transfer Failed!" << endl;
    }
}

// =========================
// Display Accounts
// =========================

void Bank::displayAccount(int accountNumber)
{
    Account* account = findAccount(accountNumber);

    if (account == nullptr)
    {
        cout << "Account not found!" << endl;
        return;
    }

    account->display();
}

void Bank::displayAllAccounts()
{
    if (accounts.empty())
    {
        cout << "No Accounts Found!" << endl;
        return;
    }

    for (const auto& account : accounts)
    {
        account->display();
        cout << "------------------------------------" << endl;
    }
}

// =========================
// File Handling
// =========================

void Bank::saveCustomers()
{
    ofstream out("customers.txt");

    if (!out)
        return;

    out << customers.size() << endl;

    for (const auto& customer : customers)
    {
        out << customer.getCustomerID() << endl;
        out << customer.getName() << endl;
        out << customer.getAge() << endl;
        out << customer.getPhoneNumber() << endl;
        out << customer.getPassword() << endl;
    }

    out.close();
}

void Bank::loadCustomers()
{
    ifstream in("customers.txt");

    if (!in)
        return;

    int n;
    in >> n;
    in.ignore();

    for (int i = 0; i < n; i++)
    {
        int id;
        int age;
        string name;
        string phone;
        string password;

        in >> id;
        in.ignore();

        getline(in, name);

        in >> age;
        in.ignore();

        getline(in, phone);
        getline(in, password);

        Customer customer(id, name, age, phone, password);

        customers.push_back(customer);
    }

    in.close();
}

void Bank::saveAccounts()
{
    ofstream out("accounts.txt");

    if (!out)
        return;

    out << accounts.size() << endl;

    for (auto account : accounts)
    {
        account->save(out);
    }

    out.close();
}

void Bank::loadAccounts()
{
    ifstream in("accounts.txt");

    if (!in)
        return;

    int n;
    in >> n;

    for (int i = 0; i < n; i++)
    {
        string type;

        in >> type;

        if (type == "Savings")
        {
            int accNo;
            int customerID;
            double balance;
            double rate;

            in >> accNo;
            in >> customerID;
            in >> balance;
            in >> rate;

            SavingsAccount* account =
                new SavingsAccount(accNo,
                                   customerID,
                                   balance,
                                   rate);

            accounts.push_back(account);

            Customer* customer = findCustomer(customerID);

            if (customer != nullptr)
            {
                customer->setAccount(account);
            }
        }
        else if (type == "Current")
        {
            int accNo;
            int customerID;
            double balance;
            double overdraft;

            in >> accNo;
            in >> customerID;
            in >> balance;
            in >> overdraft;

            CurrentAccount* account =
                new CurrentAccount(accNo,
                                   customerID,
                                   balance,
                                   overdraft);

            accounts.push_back(account);

            Customer* customer = findCustomer(customerID);

            if (customer != nullptr)
            {
                customer->setAccount(account);
            }
        }
    }

    in.close();
}

// =========================
// Destructor
// =========================

Bank::~Bank()
{
    saveCustomers();
    saveAccounts();

    for (auto account : accounts)
    {
        delete account;
    }

    accounts.clear();
}