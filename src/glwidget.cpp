#include "glwidget.h"
#include "Display.h"
#include <iostream>

#include <QPainter>
#include <QTimer>

GLWidget::GLWidget(Display *display, QWidget *parent)
    : QOpenGLWidget(parent), display(display)
{
    elapsed = 0;
    //setFixedSize(200, 200);
    setAutoFillBackground(true);
}

void GLWidget::animate()
{
    elapsed = (elapsed + qobject_cast<QTimer*>(sender())->interval()) % 1000;
    update();
}

void GLWidget::paintEvent(QPaintEvent *event)
{

    QPainter p;
    p.begin(this);
    p.setRenderHint(QPainter::Antialiasing);
    latexText = display->text();
    updateParser();
    mathText.draw(p, Qt::AlignCenter, QRectF(0,0,this->width(), this->height()), false);
    p.end();
}

void GLWidget::updateParser()
{
    mathText.setFontSize(35);
    mathText.parse("$" + latexText + "$");
    //mathText.parse("$\\left[-\\frac{\\hbar^2}{2m}\\frac{\\partial^2}{\\partial x^2}+V(x)\\right]\\Psi(x)=\\mathrm{i}\\hbar\\frac{\\partial}{\\partial t}\\Psi(x)$");
}
