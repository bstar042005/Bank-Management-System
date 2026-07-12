#ifndef PERSON_H
#define PERSON_H

#include <iostream>
#include <string>

using namespace std;

class Person
{
protected:
    string name;
    int age;
    string phoneNumber;

public:
    Person();
    Person(string name, int age, string phoneNumber);

    void setName(string name);
    string getName() const;

    void setAge(int age);
    int getAge() const;

    void setPhoneNumber(string phoneNumber);
    string getPhoneNumber() const;

    virtual void display() const;

    virtual ~Person();
};

#endif