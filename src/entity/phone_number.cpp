/**
 * phone_number.h - Phone number class.
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

#include "phone_number.h"

using namespace std;

/**
 *  Name constructor.
 *   Params: s1 - string: Segment one of the number '###'.
 *           s2 - string: Segment two of the number '###'.
 *           s3 - string: Segment three of the number '####'.
 */
Number::Number(string s1, string s2, string s3) {
    segment1 = s1;
    segment2 = s2;
    segment3 = s3;
}

/**
 * Get the full phone number of the person in the form '###-###-####'.
 *   Return - string: The person's phone number.
 */
string Number::getFullNumber() {
    return segment1 + "-" + segment2 + "-" + segment3;
}

/**
 * Get the first segment of the phone number.
 *   Return - string: The first segment of the number.
 */
string Number::getSeg1() {
    return segment1;
}

/**
 * Get the second segment of the phone number.
 *   Return - string: The second segment of the number.
 */
string Number::getSeg2() {
    return segment2;
}

/**
 * Get the third segment of the phone number.
 *   Return - string: The third segment of the number.
 */
string Number::getSeg3() {
    return segment3;
}

/**
 * Set the first segment of the phone number.
 *   Params: s1 - string: The new first segment in the form '###'.
 */
void Number::setSeg1(string s1) {
    segment1 = s1;
}

/**
 * Set the second segment of the phone number.
 *   Params: s2 - string: The new second segment in the form '###'.
 */
void Number::setSeg2(string s2) {
    segment2 = s2;
}

/**
 * Set the third segment of the phone number.
 *   Params: s3 - string: The new third segment in the form '####'.
 */
void Number::setSeg3(string s3) {
    segment3 = s3;
}
