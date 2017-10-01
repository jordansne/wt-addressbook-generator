/**
 * generator.h - Generator Class
 * Jordan Mathewson - 250868197
 * CS3307A - Assignment #1
 */

#ifndef GENERATOR_H
#define GENERATOR_H

#include <string>
#include <vector>
#include "entity/address.h"
#include "entity/person.h"

class Generator {

public:
    Generator();

    std::vector<Person*> getCurrentBook();
    void generateNewBook(int size);

private:
    std::vector<Person*> addressBook;

    static const int OPTIONS = 15;
    static const std::string firstNames[OPTIONS];
    static const std::string lastNames[OPTIONS];
    static const std::string streetNames[OPTIONS];
    static const std::string cityNames[OPTIONS];
    static const std::string provinceNames[10];

    std::string randFirstName();
    std::string randLastName();
    std::string randNumber();
    Address* randAddress();
    int genRand(int min, int max);

};

#endif
