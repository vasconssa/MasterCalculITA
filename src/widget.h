#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <jkqtmathtext/jkqtmathtext.h>
#include "Display.h"

class Helper;

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(Display *display, QWidget *parent = nullptr);

public slots:
    void animate();

protected:
    void paintEvent(QPaintEvent *event) override;
    void updateParser();

private:
    int elapsed;
    JKQTMathText mathText;
    QString latexText;
    Display *display;
};

#endif
