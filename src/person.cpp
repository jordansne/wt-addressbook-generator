/**
 * person.cpp - Person class
 * Jordan Mathewson - 250868197
 * CS3307A - Assignment #1
 */

#include <string>
#include "person.h"
#include "address.h"

using namespace std;

/**
 * Person constructor.
 *   Params: f - string:   First name of the Person.
 *           l - string:   Last name of the person.
 *           n - string:   First name of the person.
 *           a - Address*: Address object of the person.
 */
Person::Person(string f, string l, string n, Address* a) {
    firstName = f;
    lastName = l;
    phoneNumber = n;
    address = a;
}

/**
 * Get the first name.
 *   Return - string: The person's first name.
 */
string Person::getFirstName() {
    return firstName;
}

/**
 * Get the last name.
 *   Return - string: The person's last name.
 */
string Person::getLastName() {
    return lastName;
}

/**
 * Get the full name.
 *   Return - string: The person's first and last name.
 */
string Person::getName() {
    return firstName + " " + lastName;
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
    json += "\"firstName\": \"" + firstName + "\", ";
    json += "\"lastName\": \"" + lastName + "\" }";

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
    json += "  \"firstName\": \"" + firstName + "\",\n";
    json += "  \"lastName\": \"" + lastName + "\",\n";
    json += "  \"streetaddress\": \"" + address->getStreet() + "\",\n";
    json += "  \"city\": \"" + address->getCity() + "\",\n";
    json += "  \"country\": \"" + address->getCountry() + "\",\n";
    json += "  \"phone\": \"" + phoneNumber + "\"\n";
    json += "}";

    return json;
}
