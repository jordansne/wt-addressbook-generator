/**
 * people_resource.cpp - People API resource class.
 * Jordan Mathewson - 250868197
 * CS3307A - Assignment #1
 */

#include <string>
#include <vector>
#include <Wt/Http/Request>
#include <Wt/Http/Response>
#include "people_resource.h"
#include "generator.h"
#include "person.h"

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
 *   Params: Request - request:   The request object provided by Wt.
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
 *   Params: string - person:     The provided ID of the person being requested. May be invalid.
 *           Response - response: The response object provided by Wt.
 */
void PeopleResource::handlePerson(string person, Response &response) {
    vector<Person*> book = generator->getCurrentBook();

    try {
        // Try to parse ID to an integer
        int personID = stoi(person);

        // Check the ID is within the range of the address book
        if (personID < 0 || personID >= book.size()) {
            response.setStatus(404);
            response.out() << "404: Not found" << endl << "ID out of range" << endl;
            return;
        }

        response.setMimeType("application/json");
        response.out() << book.at(personID)->toJSON(personID);

    } catch (invalid_argument &e) {
        response.setStatus(400);
        response.out() << "400: Bad request" << endl << "Could not parse ID";
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
