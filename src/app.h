/**
 * app.h - App class, renders and handles all UI elements.
 * Jordan Mathewson - 250868197
 * CS3307A - Assignment #1
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
#include "person.h"
#include "generator.h"

class App : public Wt::WApplication {

public:
    App(Generator *g, const Wt::WEnvironment& env);

private:
    Generator* generator;
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
