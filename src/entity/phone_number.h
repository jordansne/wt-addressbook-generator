/**
 * phone_number.h - Phone number class.
 * Jordan Mathewson - 250868197
 * CS3307A - Assignment #1
 */

#ifndef PHONE_NUMBER_H
#define PHONE_NUMBER_H

#include <string>

class Number {

public:
    Number(std::string s1, std::string s2, std::string s3);

    std::string getFullNumber();
    std::string getSeg1();
    std::string getSeg2();
    std::string getSeg3();
    void setSeg1(std::string);
    void setSeg2(std::string);
    void setSeg3(std::string);

private:
    std::string segment1;
    std::string segment2;
    std::string segment3;

};

#endif
