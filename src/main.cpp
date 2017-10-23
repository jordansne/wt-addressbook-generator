/**
 * main.cpp - Program entry point.
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

#include <Wt/WApplication>
#include <Wt/WEnvironment>
#include <Wt/WServer>
#include "app.h"
#include "generator.h"
#include "people_resource.h"

using namespace std;
using namespace Wt;

Generator *generator;

WApplication *createApp(const WEnvironment &env) {
    return new App(generator, env);
}

int main(int argc, char *argv[]) {
    WServer server(argc, argv, WTHTTP_CONFIGURATION);
    generator = new Generator();

    try {
        // Add API resource
        server.addResource(new PeopleResource(generator), "/people");
        // Add app homepage entry point
        server.addEntryPoint(Application, &createApp);

        if (server.start()) {
            int signal = WServer::waitForShutdown(argv[0]);

            cout << "Shutting down server.. Signal: " << signal << endl;
            server.stop();
        }

    } catch (WServer::Exception &e) {
        cerr << "Error: " << e.what() << endl;
        return 1;
    } catch (exception &e) {
        cerr << "Error: " << e.what() << endl;
        return 1;
    }
}
