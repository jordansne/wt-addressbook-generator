/**
 * people_resource.cpp - People API resource class.
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

#include <vector>
#include "people_resource.h"
#include "entity/person.h"

using namespace std;
using namespace Wt::Http;

/**
 * PeopleResource constructor.
 *   Params: Generator - g: The generator object that stores the address book.
 */
PeopleResource::PeopleResource(Generator *g) {
    generator = g;
}

/**
 * Handles incoming requests for the '/people' path.
 *   Params: Request  - request:  The request object provided by Wt.
 *           Response - response: The response object provided by Wt.
 */
void PeopleResource::handleRequest(const Request &request, Response &response) {
    // URL text following "/people"
    string subPath = request.pathInfo();

    if (subPath.length() > 1) {
        // Remove preceeding '/' in subPath before calling handlePerson
        handlePerson(subPath.substr(1, subPath.length() - 1), response);
    } else {
        handleBook(response);
    }
}

/**
 * Handles a request to retrieve an individual person's data.
 *   Params: string  - person:    The provided ID of the person being requested. May be invalid.
 *           Response - response: The response object provided by Wt.
 */
void PeopleResource::handlePerson(string person, Response &response) {
    vector<Person*> book = generator->getCurrentBook();

    // Check if all the characters are digits in the input (which also disallows negative numbers)
    if (person != "" && all_of(person.begin(), person.end(), ::isdigit)) {
        // Convert to integer
        int personID = stoi(person);

        // Check the ID is within the range of the address book
        if (personID < book.size()) {
            response.setMimeType("application/json");
            response.out() << book.at(personID)->toJSON(personID);
        } else {
            response.setStatus(404);
            response.out() << "404: Not found" << endl << "ID out of range" << endl;
        }
    } else {
        response.setStatus(400);
        response.out() << "400: Bad request" << endl << "Invalid person ID";
    }
}

/**
 * Handles a request to retrieve all the person's data in the address book.
 *   Params: Response - response: The response object provided by Wt.
 */
void PeopleResource::handleBook(Response &response) {
    vector<Person*> book = generator->getCurrentBook();
    string json;

    json += "{\n";
    json += "  \"people\": [\n";

    // Add each person to the JSON string
    for (int person = 0; person < book.size(); person++) {
        json += "    " + book[person]->toJSONmin(person);

        // Add comma after each JSON object (except for last one)
        if (person != book.size() - 1) {
            json += ",";
        }
        json += "\n";
    }

    json += "  ]\n";
    json += "}\n";

    response.setMimeType("application/json");
    response.out() << json;
}
