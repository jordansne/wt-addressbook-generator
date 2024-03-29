/**
 * address.cpp - Address class
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

#include "address.h"

using namespace std;

/**
 * Address constructor.
 *   Params: s - string: Street name and number of the address.
 *           c - string: City of the address.
 *           n - string: Province of the address.
 */
Address::Address(string s, string c, string p) {
    street = s;
    city = c;
    province = p;
    country = "Canada";
}

/**
 * Get the street name and number.
 *   Return - string: The street name and number of the address.
 */
string Address::getStreet() {
    return street;
}

/**
 * Get the city name.
 *   Return - string: The city of the address.
 */
string Address::getCity() {
    return city;
}

/**
 * Get the province name.
 *   Return - string: The province of the address.
 */
string Address::getProvince() {
    return province;
}

/**
 * Get the country name.
 *   Return - string: The country of the address.
 */
string Address::getCountry() {
    return country;
}

/**
 * Get the entire address in the form of a string.
 *   Return - string: The full address in the format: '# STREETNAME, CITY PROVINCE, COUNTRY'
 */
string Address::getFullAddress() {
    return street + ", " + city + " " + province + ", " + country;
}
