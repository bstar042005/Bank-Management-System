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
    // Constructors
    Person();
    Person(string name, int age, string phoneNumber);

    // Setters
    void setName(string name);
    void setAge(int age);
    void setPhoneNumber(string phoneNumber);

    // Getters
    string getName() const;
    int getAge() const;
    string getPhoneNumber() const;

    // Display
    virtual void display() const;

    // Destructor
    virtual ~Person();
};

#endif