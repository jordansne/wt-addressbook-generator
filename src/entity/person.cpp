/**
 * person.cpp - Person class
 * Jordan Mathewson - 250868197
 * CS3307A - Assignment #1
 */

#include <string>
#include "person.h"
#include "address.h"
#include "name.h"

using namespace std;

/**
 * Person constructor.
 *   Params: n - Name:     The Name object for the person.
 *           num - string: The phone number of the person.
 *           a - Address*: Address object of the person.
 */
Person::Person(Name *n, string num, Address *a) {
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
 *   Return - string: The person's phone number.
 */
string Person::getNumber() {
    return phoneNumber;
}

/**
 * Get the address.
 *   Return - string: The person's first name.
 */
Address* Person::getAddress() {
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
    json += "  \"phone\": \"" + phoneNumber + "\"\n";
    json += "}";

    return json;
}
