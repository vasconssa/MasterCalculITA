#include "Button.h"

Button::Button(const QString &text, QWidget *parent)
    : QToolButton(parent)
{
    setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Preferred);
    //setText(text);
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
    JKQTMathText mathText;
    mathText.setFontSize(15);
    mathText.parse("$\\alpha$");
    mathText.draw(p, Qt::AlignCenter, QRectF(0,0,this->width(), this->height()), false);
    //QPainter painter;
    //mathText.useXITS();


}
