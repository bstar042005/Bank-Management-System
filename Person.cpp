#include "Person.h"

Person::Person()
    : name(""), age(0), phoneNumber("")
{
}

Person::Person(string name, int age, string phoneNumber)
    : name(name), age(age), phoneNumber(phoneNumber)
{
}

void Person::setName(string name)
{
    this->name = name;
}

string Person::getName() const
{
    return name;
}

void Person::setAge(int age)
{
    this->age = age;
}

int Person::getAge() const
{
    return age;
}

void Person::setPhoneNumber(string phoneNumber)
{
    this->phoneNumber = phoneNumber;
}

string Person::getPhoneNumber() const
{
    return phoneNumber;
}

void Person::display() const
{
    cout << "Name         : " << name << endl;
    cout << "Age          : " << age << endl;
    cout << "Phone Number : " << phoneNumber << endl;
}

Person::~Person()
{
}