#include "Button.h"

Button::Button(const QString &latexText, QWidget *parent)
    : QToolButton(parent)
{
    setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Preferred);
    mathText.setFontSize(15);
    mathText.parse("$" + latexText + "$");
}

QSize Button::sizeHint() const
{
    QSize size = QToolButton::sizeHint();
    size.rheight() += 20;
    size.rwidth() = qMax(size.width(), size.height());
    return size;
}


void Button::paintEvent(QPaintEvent *event) {
    QStylePainter p(this);
    QStyleOptionToolButton opt;
    initStyleOption(&opt);
    p.drawComplexControl(QStyle::CC_ToolButton, opt);
    p.setRenderHint(QPainter::Antialiasing);
    mathText.draw(p, Qt::AlignCenter, QRectF(0,0,this->width(), this->height()), false);
    //QPainter painter;
    //mathText.useXITS();


}
