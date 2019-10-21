#include "Display.h"

Display::Display(QWidget *parent) {
    createDisplay();
    setLayout(displayLayout);
}

void Display::createDisplay() {
    displayLayout = new QVBoxLayout;
    input = new QTextEdit;
    displayLayout->addWidget(input);
}
