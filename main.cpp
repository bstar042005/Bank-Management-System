#include <iostream>
#include <limits>
#include "Bank.h"

using namespace std;

int main()
{
    Bank bank;
    int choice;

    do
    {
        cout << "\n=====================================\n";
        cout << "      BANK MANAGEMENT SYSTEM\n";
        cout << "=====================================\n";
        cout << "1. Add Customer\n";
        cout << "2. Create Savings Account\n";
        cout << "3. Create Current Account\n";
        cout << "4. Deposit Money\n";
        cout << "5. Withdraw Money\n";
        cout << "6. Transfer Money\n";
        cout << "7. Display Customer\n";
        cout << "8. Display All Customers\n";
        cout << "9. Display Account\n";
        cout << "10. Display All Accounts\n";
        cout << "11. Display Customer Accounts\n";
        cout << "0. Exit\n";

        cout << "\nEnter Choice : ";

        if (!(cin >> choice))
        {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "\nInvalid input! Please enter a number.\n";
            continue;
        }

        switch (choice)
        {
        case 1:
        {
            int id, age;
            string name, phone, password;

            cout << "\nCustomer ID : ";
            cin >> id;

            cin.ignore(numeric_limits<streamsize>::max(), '\n');

            cout << "Name : ";
            getline(cin, name);

            cout << "Age : ";
            cin >> age;

            cout << "Phone Number : ";
            cin >> phone;

            cout << "Password : ";
            cin >> password;

            Customer customer(id, name, age, phone, password);
            bank.addCustomer(customer);

            cout << "\nCustomer added successfully.\n";
            break;
        }

        case 2:
        {
            int accNo, customerID;
            double balance, rate;

            cout << "\nAccount Number : ";
            cin >> accNo;

            cout << "Customer ID : ";
            cin >> customerID;

            cout << "Initial Balance : ";
            cin >> balance;

            cout << "Interest Rate (%) : ";
            cin >> rate;

            bank.createSavingsAccount(accNo, customerID, balance, rate);

            break;
        }

        case 3:
        {
            int accNo, customerID;
            double balance, overdraft;

            cout << "\nAccount Number : ";
            cin >> accNo;

            cout << "Customer ID : ";
            cin >> customerID;

            cout << "Initial Balance : ";
            cin >> balance;

            cout << "Overdraft Limit : ";
            cin >> overdraft;

            bank.createCurrentAccount(accNo, customerID, balance, overdraft);

            break;
        }

        case 4:
        {
            int accNo;
            double amount;

            cout << "\nAccount Number : ";
            cin >> accNo;

            cout << "Deposit Amount : ";
            cin >> amount;

            bank.deposit(accNo, amount);

            break;
        }

        case 5:
        {
            int accNo;
            double amount;

            cout << "\nAccount Number : ";
            cin >> accNo;

            cout << "Withdrawal Amount : ";
            cin >> amount;

            bank.withdraw(accNo, amount);

            break;
        }

        case 6:
        {
            int sender, receiver;
            double amount;

            cout << "\nSender Account Number : ";
            cin >> sender;

            cout << "Receiver Account Number : ";
            cin >> receiver;

            cout << "Transfer Amount : ";
            cin >> amount;

            bank.transfer(sender, receiver, amount);

            break;
        }

        case 7:
        {
            int customerID;

            cout << "\nCustomer ID : ";
            cin >> customerID;

            bank.displayCustomer(customerID);

            break;
        }

        case 8:
        {
            bank.displayAllCustomers();
            break;
        }

        case 9:
        {
            int accNo;

            cout << "\nAccount Number : ";
            cin >> accNo;

            bank.displayAccount(accNo);

            break;
        }

        case 10:
        {
            bank.displayAllAccounts();
            break;
        }

        case 11:
        {
            int customerID;

            cout << "\nCustomer ID : ";
            cin >> customerID;

            bank.displayCustomerAccounts(customerID);

            break;
        }

        case 0:
        {
            cout << "\n=====================================\n";
            cout << "Thank You for using Bank Management System.\n";
            cout << "Have a Nice Day!\n";
            cout << "=====================================\n";
            break;
        }

        default:
        {
            cout << "\nInvalid Choice! Please try again.\n";
        }
        }

    } while (choice != 0);

    return 0;
}