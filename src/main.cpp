/**
 * main.cpp - Program entry point.
 * Jordan Mathewson - 250868197
 * CS3307A - Assignment #1
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
