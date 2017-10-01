/**
 * name.h - Name Class, represents a person's name.
 * Jordan Mathewson - 250868197
 * CS3307A - Assignment #1
 */

#ifndef NAME_H
#define NAME_H

#include <string>

class Name {

public:
    Name(std::string f, std::string l);

    std::string getFirstName();
    std::string getLastName();
    std::string getFullName();
    void setFirstName(std::string f);
    void setLastName(std::string l);

private:
    std::string firstName;
    std::string lastName;

};

#endif
