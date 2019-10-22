#ifndef DISPLAY_H
#define DISPLAY_H

#include <QtWidgets>

class Display : public QWidget {
public:
    Display(QWidget *parent = nullptr);
public:
    QString text();
    void setText(const QString& text);
private:
    void createDisplay();
private:
    QLineEdit *input;
    QVBoxLayout *displayLayout;
};

#endif
