#ifndef GLWIDGET_H
#define GLWIDGET_H

#include <QOpenGLWidget>
#include <jkqtmathtext/jkqtmathtext.h>

class Display;

class GLWidget : public QOpenGLWidget
{
    Q_OBJECT

public:
    GLWidget(Display *display, QWidget *parent = nullptr);

public slots:
    void animate();

protected:
    void paintEvent(QPaintEvent *event) override;

private:
    void updateParser();

    JKQTMathText mathText;
    QString latexText;
    Display *display;
    int elapsed;
};
#endif
