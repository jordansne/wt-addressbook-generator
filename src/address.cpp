/**
 * address.cpp - Address class
 * Jordan Mathewson - 250868197
 * CS3307A - Assignment #1
 */

#include <string>
#include "address.h"

using namespace std;

/**
 * Address constructor.
 *
 * Parameters:
 *   s - string:   Street name and number of the address.
 *   c - string:   City of the address.
 *   n - string:   Province of the address.
 */
Address::Address(string s, string c, string p) {
    street = s;
    city = c;
    province = p;
    country = "Canada";
}

/**
 * Get the street name and number.
 *
 * Returns - string: The street name and number of the address.
 */
string Address::getStreet() {
    return street;
}

/**
 * Get the city name.
 *
 * Returns - string: The city of the address.
 */
string Address::getCity() {
    return city;
}

/**
 * Get the province name.
 *
 * Returns - string: The province of the address.
 */
string Address::getProvince() {
    return province;
}

/**
 * Get the country name.
 *
 * Returns - string: The country of the address.
 */
string Address::getCountry() {
    return country;
}

/**
 * Get the entire address in the form of a string.
 *
 * Returns - string: The full address in the format: '# STREETNAME, CITY PROVINCE, COUNTRY'
 */
string Address::getFullAddress() {
    return street + ", " + city + " " + province + ", " + country;
}
