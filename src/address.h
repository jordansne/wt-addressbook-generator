/**
 * address.h - Address Class
 * Jordan Mathewson - 250868197
 * CS3307A - Assignment #1
 */

#ifndef ADDRESS_H
#define ADDRESS_H

#include <string>

class Address {

public:
    Address(std::string s, std::string c, std::string p);

    std::string getStreet();
    std::string getCity();
    std::string getProvince();
    std::string getCountry();
    std::string getFullAddress();

private:
    std::string street;
    std::string city;
    std::string province;
    std::string country;

};

#endif
