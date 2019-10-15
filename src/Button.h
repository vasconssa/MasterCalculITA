#ifndef BUTTON_H
#define BUTTON_H

#include <QtWidgets>

class Button : public QToolButton
{
    Q_OBJECT

public:
    explicit Button(const QString &text, QWidget *parent = nullptr);

    QSize sizeHint() const override;
};

#endif // BUTTON_H
