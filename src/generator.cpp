/**
 * generator.cpp - Generator Class
 * Jordan Mathewson - 250868197
 * CS3307A - Assignment #1
 */

#include <cstdlib>
#include <string>
#include <vector>
#include "generator.h"
#include "address.h"
#include "person.h"

using namespace std;

/**
 * Arrays of constants for random generation.
 */
const string Generator::firstNames[OPTIONS] = {
    "Charles", "Wilber", "Major", "Odell", "Morton", "Dusty", "Virgil",
    "Tobias", "Glenn", "Lino", "Nicolas", "Von", "Jorge", "Chas", "Lyle"
};
const string Generator::lastNames[OPTIONS] = {
    "Collier", "Mckay", "Page", "Pacheco", "Estes", "Braun", "Brock", "Duncan",
    "Bates", "Lawson", "Briggs", "Pham", "Sanford", "Haas", "Johnson"
};
const string Generator::streetNames[OPTIONS] = {
    "Access Road", "Whiteside Street", "Northwest Juggs Park", "Guting Boulevard", "Southwest Street",
    "West Mount Street", "West Clio Road", "Tall Ships Boulevard", "Southwest Back Lane", "West Messiter Avenue",
    "West Westmora Street", "Sherill Parkway Road", "South Inglewood Alley", "Southeast Hendon Parkway",
    "Clovewood Boulevard"
};
const string Generator::cityNames[OPTIONS] = {
    "Nokomis", "Fort Erie", "Harptree", "Smithville", "Centralia", "Calgary", "Demmitt", "Prince George",
    "Villeneuve", "Calmar", "Mingan", "Readford", "Rigoulette", "Niganishe", "Hunter River"
};
const string Generator::provinceNames[10] = {
    "Ontario", "Quebec", "Manitoba", "PEI", "Alberta", "British Columbia", "Nova Scotia", "Saskatchewan",
    "Newfoundland & Labrador", "New Brunswick"
};

/**
 * Generator constructor. Initializes the random number generator.
 */
Generator::Generator() {
    srand((unsigned) time(0));
}

/**
 * Get the address book currently saved in memory.
 *   Return - vector: The address book.
 */
vector<Person*> Generator::getCurrentBook() {
    return addressBook;
}

/**
 * Generates a new address book and saves it in memory (deleting the existing address book).
 *   Params: size - int: The number of random persons to generate.
 */
void Generator::generateNewBook(const int size) {
    // Delete any existing records
    for (int i = 0; i < addressBook.size(); i++) {
        delete addressBook[i];
    }
    addressBook.clear();

    // Fill the addressBook with new random persons
    addressBook.reserve(size);
    for (int i = 0; i < size; i++) {
        addressBook.push_back(new Person(randFirstName(), randLastName(), randNumber(), randAddress()));
    }
}

/**
 * Returns a random first name.
 *   Returns - string: A first name.
 */
string Generator::randFirstName() {
    return firstNames[genRand(0, OPTIONS - 1)];
}

/**
 * Returns a random last name.
 *   Return - string: A last name.
 */
string Generator::randLastName() {
    return lastNames[genRand(0, OPTIONS - 1)];
}

/**
 * Returns a random phone number.
 *   Return - string: A phone number in the form '###-###-####'.
 */
string Generator::randNumber() {
    string number = "";

    // First 3 numbers
    number += to_string(genRand(100, 999)) + "-";

    // Second 3 numbers
    number += to_string(genRand(100, 999)) + "-";

    // Last 4 numbers
    int lastDigits = genRand(0, 9999);
    if (lastDigits <= 9) {
        number += "000" + to_string(lastDigits);
    } else if (lastDigits <= 99) {
        number += "00" + to_string(lastDigits);
    } else if (lastDigits <= 999) {
        number += "0" + to_string(lastDigits);
    } else {
        number += to_string(lastDigits);
    }

    return number;
}

/**
 * Returns a random address.
 *   Return - Address*: A random address object.
 */
Address* Generator::randAddress() {
    const string streetName = to_string(genRand(1, 999)) + " " + streetNames[genRand(0, OPTIONS - 1)];
    const string city = cityNames[genRand(0, OPTIONS - 1)];
    const string province = provinceNames[genRand(0, 9)];

    return new Address(streetName, city, province);
}

/**
 * Helper method, returns a random number within a given range (inclusive).
 *   Params: min - int: The minimum value of the number.
 *           max - int: The maximum value of the number.
 *   Return - int:      A random number.
 */
int Generator::genRand(const int min, const int max) {
    return (rand() % (max - min)) + min;
}
