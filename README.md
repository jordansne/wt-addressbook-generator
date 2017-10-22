# Wt Address Book Generator

## About

This project was an assignment for an object oriented design course in third year at university. It uses the [Wt library](https://www.webtoolkit.eu/wt) for a web server to provide a simple web interface available at the root and two REST APIs at `/people` & `/people/#`. Contacts can be generated on the web interface and accessed through the APIs. The server stores contacts in memory until shutdown.

## Building

    $ git clone https://github.com/jordansne/wt-addressbook-generator
    $ cd wt-addressbook-generator
    $ g++ src/*.cpp src/entity/*.cpp -o server -std=c++11 -lwthttp -lwt -lboost_system

## Running

    $ ./server --docroot ./html --http-address localhost --http-port 8080

## Requirements

- Wt version 3.3.8
