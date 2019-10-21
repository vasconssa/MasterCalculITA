#ifndef DISPLAY_H
#define DISPLAY_H

#include <QtWidgets>

class Display : public QWidget {
public:
    Display(QWidget *parent = nullptr);
private:
    void createDisplay();
private:
    QTextEdit *input;
    QVBoxLayout *displayLayout;
};

#endif
