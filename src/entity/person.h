/**
 * person.h - Person Class
 * Jordan Mathewson - 250868197
 * CS3307A - Assignment #1
 */

#ifndef PERSON_H
#define PERSON_H

#include <string>
#include "address.h"

class Person {

public:
    Person(std::string f, std::string l, std::string n, Address* a);

    std::string getFirstName();
    std::string getLastName();
    std::string getName();
    std::string getNumber();
    Address* getAddress();
    std::string toJSONmin(int id);
    std::string toJSON(int id);

private:
    std::string firstName;
    std::string lastName;
    std::string phoneNumber;
    Address* address;

};

#endif
