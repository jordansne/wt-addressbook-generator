/**
 * person.cpp - Person class
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

#include "person.h"

using namespace std;

/**
 * Person constructor.
 *   Params: n   - Name:     The Name object for the person.
 *           num - Number*:  The phone number object of the person.
 *           a   - Address*: Address object of the person.
 */
Person::Person(Name *n, Number *num, Address *a) {
    name = n;
    phoneNumber = num;
    address = a;
}

/**
 * Get the person's name object.
 *   Return - Name: The name object.
 */
Name *Person::getName() {
    return name;
}

/**
 * Get the phone number.
 *   Return - Number: The person's phone number.
 */
Number *Person::getNumber() {
    return phoneNumber;
}

/**
 * Get the address.
 *   Return - string: The person's first name.
 */
Address *Person::getAddress() {
    return address;
}

/**
 * Returns a minimal JSON string representation of the object (only first and last name).
 *   Params: id - int: The ID number to be part of the JSON object.
 *   Return - string:  JSON representation of the object.
 */
string Person::toJSONmin(const int id) {
    string json = "";

    json += "{ \"id\": \"" + to_string(id) + "\", ";
    json += "\"firstName\": \"" + name->getFirstName() + "\", ";
    json += "\"lastName\": \"" + name->getLastName() + "\" }";

    return json;
}

/**
 * Returns a full JSON string representation of the object.
 *   Params: id - int: The ID number to be part of the JSON object.
 *   Return - string:  JSON representation of the object.
 */
string Person::toJSON(const int id) {
    string json = "";

    json += "{\n";
    json += "  \"id\": \"" + to_string(id) + "\",\n";
    json += "  \"firstName\": \"" + name->getFirstName() + "\",\n";
    json += "  \"lastName\": \"" + name->getLastName() + "\",\n";
    json += "  \"streetaddress\": \"" + address->getStreet() + "\",\n";
    json += "  \"city\": \"" + address->getCity() + "\",\n";
    json += "  \"country\": \"" + address->getCountry() + "\",\n";
    json += "  \"phone\": \"" + phoneNumber->getFullNumber() + "\"\n";
    json += "}";

    return json;
}
