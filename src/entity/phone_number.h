/**
 * phone_number.h - Phone number class.
 * Copyright (C) 2017  Jordan Sne (Mathewson)
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License along
 * with this program; if not, write to the Free Software Foundation, Inc.,
 * 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA.
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
