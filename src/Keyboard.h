#ifndef KEYBOARD_H
#define KEYBOARD_H

#include <QtWidgets>
#include "Button.h"

class Keyboard : public QWidget {
public:
    Keyboard(QWidget *parent = nullptr);
private:
    void createNumericKeyboard();
public:
    enum { NumDigitButtons = 10 };
    Button *digitButtons[NumDigitButtons];
private:
    QTabWidget *tabWidget;
    QWidget *numericKeyboard;
};

#endif
