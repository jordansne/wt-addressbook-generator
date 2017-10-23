/**
 * name.h - Name Class, represents a person's name.
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
