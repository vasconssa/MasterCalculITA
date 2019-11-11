#ifndef DISPLAY_H
#define DISPLAY_H

#include <QtWidgets>
#include <glwidget.h>
#include <jkqtmathtext/jkqtmathtext.h>

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
    GLWidget *glWidget;
    QSplitter *splitter;
};

#endif
