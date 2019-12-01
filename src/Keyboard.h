#ifndef KEYBOARD_H
#define KEYBOARD_H

#include <QtWidgets>
#include "Button.h"
#include "Display.h"
#include "controller.h"

class Controller;

class Keyboard : public QWidget {
    Q_OBJECT
public:
    explicit Keyboard(Display *display, Controller *cont, QWidget *parent = nullptr);
private:
    void createNumericKeyboard();
    Button* createButton(const QString& latexText, const char *member);
private slots:
    void buttonClicked();
public:
    enum { NumDigitButtons = 5 };
    Button *digitButtons[NumDigitButtons];
    Controller *controller;
private:
    QTabWidget *tabWidget;
    QWidget *numericKeyboard;
    Display *display;
};

#endif
