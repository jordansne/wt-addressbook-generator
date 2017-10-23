/**
 * name.cpp - Name Class, represents a person's name.
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

#include "name.h"

using namespace std;

/**
 *  Name constructor.
 *   Params: f - string: The first name of the person.
 *           l - string: The last name of the person.
 */
Name::Name(string f, string l) {
    firstName = f;
    lastName = l;
}

/**
 * Get the first name of the person.
 *   Return - string: The first name.
 */
string Name::getFirstName() {
    return firstName;
}

/**
 * Get the last name of the person.
 *   Return - string: The last name.
 */
string Name::getLastName() {
    return lastName;
}

/**
 * Get the full name of the person.
 *   Return - string: The person's full name (first and last).
 */
string Name::getFullName() {
    return firstName + " " + lastName;
}

/**
 * Sets the first name of the person.
 *   Params: f - string: The new first name.
 */
void Name::setFirstName(string f) {
    firstName = f;
}

/**
 * Sets the last name of the person.
 *   Params: f - string: The new last name.
 */
void Name::setLastName(string l) {
    lastName = l;
}
