#include "Display.h"

Display::Display(QWidget *parent) {
    createDisplay();
    setLayout(displayLayout);
}

void Display::createDisplay() {
    displayLayout = new QVBoxLayout;
    input = new QLineEdit;
    displayLayout->addWidget(input);
}

QString Display::text() {
    return input->text();
}
void Display::setText(const QString &text) {
    input->setText(text);
}
