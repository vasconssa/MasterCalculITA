#include "Display.h"
#include <QSplitter>

Display::Display(QWidget *parent) {
    createDisplay();
    setLayout(displayLayout);
}

void Display::createDisplay() {
    displayLayout = new QVBoxLayout;
    input = new QLineEdit;
    glWidget = new GLWidget(this);
    QSplitter *splitter = new QSplitter();
    splitter->setOrientation(Qt::Vertical);
    splitter->addWidget(input);
    splitter->addWidget(glWidget);
    displayLayout->addWidget(splitter);

    QTimer *timer = new QTimer(this);
    connect(timer, &QTimer::timeout, glWidget, &GLWidget::animate);
    timer->start(50);
}

QString Display::text() {
    return input->text();
}
void Display::setText(const QString &text) {
    input->setText(text);
}
