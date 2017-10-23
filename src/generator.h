/**
 * generator.h - Generator Class
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

#ifndef GENERATOR_H
#define GENERATOR_H

#include <string>
#include <vector>
#include "entity/address.h"
#include "entity/person.h"
#include "entity/phone_number.h"

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
    Number *randNumber();
    Address *randAddress();
    int genRand(int min, int max);

};

#endif
