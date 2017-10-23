/**
 * person.h - Person Class
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
    Number *getNumber();
    Address *getAddress();
    std::string toJSONmin(int id);
    std::string toJSON(int id);

private:
    Name *name;
    Number *phoneNumber;
    Address *address;

};

#endif
