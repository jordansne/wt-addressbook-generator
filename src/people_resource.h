/**
 * people_resource.h - People API resource class.
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
