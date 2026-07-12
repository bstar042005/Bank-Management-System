#include "Bank.h"

void Bank::createCustomer(Customer customer)
{
    customers.push_back(customer);
}

Customer* Bank::searchCustomer(int id)
{
    for(auto &customer : customers)
    {
        if(customer.getCustomerID()==id)
            return &customer;
    }

    return nullptr;
}

Customer* Bank::login(int id,string password)
{
    for(auto &customer : customers)
    {
        if(customer.login(id,password))
            return &customer;
    }

    return nullptr;
}

void Bank::displayCustomers() const
{
    for(const auto &customer : customers)
    {
        customer.display();
        cout<<endl;
    }
}

void Bank::deposit(int customerID,double amount)
{
    Customer* customer=searchCustomer(customerID);

    if(customer==nullptr)
    {
        cout<<"Customer Not Found"<<endl;
        return;
    }

    customer->getAccount()->deposit(amount);
}

void Bank::withdraw(int customerID,double amount)
{
    Customer* customer=searchCustomer(customerID);

    if(customer==nullptr)
    {
        cout<<"Customer Not Found"<<endl;
        return;
    }

    customer->getAccount()->withdraw(amount);
}

void Bank::checkBalance(int customerID)
{
    Customer* customer=searchCustomer(customerID);

    if(customer==nullptr)
    {
        cout<<"Customer Not Found"<<endl;
        return;
    }

    cout<<"Current Balance : "<<customer->getAccount()->getBalance()<<endl;
}