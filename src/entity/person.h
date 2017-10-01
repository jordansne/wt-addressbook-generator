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
#include "phone_number.h"

class Person {

public:
    Person(Name *n, Number *num, Address *a);

    Name *getName();
    Address* getAddress();
    Number *getNumber();
    std::string toJSONmin(int id);
    std::string toJSON(int id);

private:
    Name *name;
    Address* address;
    Number *phoneNumber;

};

#endif
