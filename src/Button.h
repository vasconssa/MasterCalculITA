#ifndef BUTTON_H
#define BUTTON_H

#include <QtWidgets>
#include <jkqtmathtext/jkqtmathtext.h>

class Button : public QToolButton
{
    Q_OBJECT

protected:
    virtual void paintEvent(QPaintEvent *event) override;
public:
    explicit Button(const QString &latexText, QWidget *parent = nullptr);

    QSize sizeHint() const override;
private:
    JKQTMathText mathText;
};

#endif // BUTTON_H
