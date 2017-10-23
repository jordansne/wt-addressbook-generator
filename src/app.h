/**
 * app.h - App class, renders and handles all UI elements.
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
#ifndef APP_H
#define APP_H

#include <Wt/WApplication>
#include <Wt/WContainerWidget>
#include <Wt/WEnvironment>
#include <Wt/WJavaScript>
#include <Wt/WLineEdit>
#include <Wt/WPushButton>
#include <Wt/WText>
#include "entity/person.h"
#include "generator.h"

class App : public Wt::WApplication {

public:
    App(Generator *g, const Wt::WEnvironment &env);

private:
    Generator *generator;
    Wt::WContainerWidget *leftPane;
    Wt::WContainerWidget *rightPane;
    Wt::WText *title;
    Wt::WText *amountBoxTitle;
    Wt::WLineEdit *amountBox;
    Wt::WPushButton *generateButton;
    Wt::WContainerWidget *personList;
    Wt::WText *addressBookTitle;
    Wt::JSlot *amountErrorAlert;

    void addLeftWidgets();
    void addRightWidgets();
    void loadBook();
    Wt::WContainerWidget *generateWidget(Person *person);
    void handleButton();

};

#endif
