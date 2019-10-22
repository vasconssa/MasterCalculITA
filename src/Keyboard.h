#ifndef KEYBOARD_H
#define KEYBOARD_H

#include <QtWidgets>
#include "Button.h"
#include "Display.h"

class Keyboard : public QWidget {
    Q_OBJECT
public:
    explicit Keyboard(Display *display, QWidget *parent = nullptr);
private:
    void createNumericKeyboard();
    Button* createButton(const QString& latexText, const char *member);
private slots:
    void buttonClicked();
public:
    enum { NumDigitButtons = 10 };
    Button *digitButtons[NumDigitButtons];
private:
    QTabWidget *tabWidget;
    QWidget *numericKeyboard;
    Display *display;
};

#endif
