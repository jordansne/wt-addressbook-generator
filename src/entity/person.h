/**
 * person.h - Person Class
 * Jordan Mathewson - 250868197
 * CS3307A - Assignment #1
 */

#ifndef PERSON_H
#define PERSON_H

#include <string>
#include "address.h"
#include "name.h"

class Person {

public:
    Person(Name *n, std::string num, Address* a);

    Name *getName();
    std::string getNumber();
    Address* getAddress();
    std::string toJSONmin(int id);
    std::string toJSON(int id);

private:
    Name *name;
    std::string phoneNumber;
    Address* address;

};

#endif
