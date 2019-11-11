#include "widget.h"

#include <QPainter>
#include <QTimer>

Widget::Widget(Display *display, QWidget *parent)
    : QWidget(parent), display(display)
{
    elapsed = 0;
    setFixedSize(200, 200);
}

void Widget::animate()
{
    elapsed = (elapsed + qobject_cast<QTimer*>(sender())->interval()) % 1000;
    update();
}


void Widget::paintEvent(QPaintEvent *event)
{

    QPainter p;
    p.setRenderHint(QPainter::Antialiasing);
    updateParser();
    mathText.draw(p, Qt::AlignCenter, QRectF(0,0,this->width(), this->height()), false);
}

void Widget::updateParser()
{
    mathText.setFontSize(15);
    latexText = display->text();
    mathText.parse("$" + latexText + "$");
}
