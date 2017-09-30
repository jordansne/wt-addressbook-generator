/**
 * people_resource.h - People API resource class.
 * Jordan Mathewson - 250868197
 * CS3307A - Assignment #1
 */

#ifndef PEOPLE_RESOURCE_H
#define PEOPLE_RESOURCE_H

#include <string>
#include <Wt/WResource>
#include <Wt/Http/Request>
#include <Wt/Http/Response>
#include "generator.h"

class PeopleResource : public Wt::WResource {

public:
    PeopleResource(Generator *g);

protected:
    void handleRequest(const Wt::Http::Request &request, Wt::Http::Response &response);

private:
    Generator *generator;

    void handlePerson(std::string requestID, Wt::Http::Response &response);
    void handleBook(Wt::Http::Response &response);

};

#endif
