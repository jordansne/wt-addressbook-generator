/**
 * address.h - Address Class
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
