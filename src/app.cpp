/**
 * app.cpp - App class, renders and handles all UI elements.
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

#include <string>
#include "app.h"

using namespace std;
using namespace Wt;

/**
 * App constructor. Initializes the UI.
 *   Params: Generator           - g:   The generator object that stores the address book.
 *           const WEnvironment& - env: Environment object to provide to superclass
 */
App::App(Generator *g, const WEnvironment &env): WApplication(env) {
    generator = g;

    // Set page properties
    setTitle("Address Book Generator");
    useStyleSheet("resources/custom/style.css");
    root()->setStyleClass("app");

    leftPane = new WContainerWidget(root());
    leftPane->setStyleClass("pane left");
    addLeftWidgets();

    rightPane = new WContainerWidget(root());
    rightPane->setStyleClass("pane right");
    addRightWidgets();

    // Create Javascript popup window object
    amountErrorAlert = new JSlot();
    amountErrorAlert->setJavaScript("function(message) { alert(message); }");

    loadBook();
}

/**
 * Initializes all widgets in the left pane (The title, options and generate button).
 */
void App::addLeftWidgets() {
    // Add page title
    title = new WText("Address Book Generator", leftPane);
    title->setStyleClass("title");

    // Add amount title
    amountBoxTitle = new WText("Number to Generate:", leftPane);
    amountBoxTitle->setStyleClass("amountTitle");

    // Add amount textbox
    amountBox = new WLineEdit(leftPane);
    amountBox->setStyleClass("amountBox");

    // Add generate button
    generateButton = new WPushButton("Generate", leftPane);
    generateButton->setStyleClass("generateButton");
    generateButton->clicked().connect(this, &App::handleButton);
}

/**
 * Initializes all widgets in the right pane (The address book container).
 */
void App::addRightWidgets() {
    // Add address book title
    addressBookTitle = new WText("Generated Address Book", rightPane);
    addressBookTitle->setStyleClass("bookTitle");

    // Add the person container
    personList = new WContainerWidget(rightPane);
    personList->setStyleClass("personList");
}

/**
 * Loads the existing address book into the container. Called on first load of the webpage
 * and whenever a new address book is generated.
 */
void App::loadBook() {
    vector<Person*> addressBook = generator->getCurrentBook();

    // Remove existing records
    personList->clear();

    // Create and add a widget contain for each person in the address book
    for (int person = 0; person < addressBook.size(); person++) {
        personList->addWidget(generateWidget(addressBook[person]));
    }
}

/**
 * Creates a Widget Container for the provided person object.
 *   Params: Person* - person: The person to create the widget with.
 */
WContainerWidget *App::generateWidget(Person *person) {
    WContainerWidget *personContainer = new WContainerWidget();
    personContainer->setStyleClass("person");

    WText *name = new WText("Name: " + person->getName()->getFullName(), personContainer);
    name->setStyleClass("name");

    WText *address = new WText("Address: " + person->getAddress()->getFullAddress(), personContainer);
    address->setStyleClass("address");

    WText *phone = new WText("Phone: " + person->getNumber()->getFullNumber(), personContainer);
    phone->setStyleClass("phone");

    return personContainer;
}

/**
 * Method for handling clicking of the generate button.
 */
void App::handleButton() {
    // Retrieve the input for the amount box
    string amountText = amountBox->text().narrow();

    // Check if all the characters are digits in the input (which also disallows negative numbers)
    if (amountText != "" && all_of(amountText.begin(), amountText.end(), ::isdigit)) {
        // Convert to integer
        int amount = stoi(amountText);

        generator->generateNewBook(amount);
        loadBook();
    } else {
        amountErrorAlert->exec("\"Please enter a valid number that is 0 or greater!\"");
    }
}
