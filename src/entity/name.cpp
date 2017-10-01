/**
 * name.cpp - Name Class, represents a person's name.
 * Jordan Mathewson - 250868197
 * CS3307A - Assignment #1
 */

#include <string>
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
