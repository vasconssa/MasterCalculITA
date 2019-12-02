#ifndef DISPLAY_H
#define DISPLAY_H

#include <QtWidgets>
#include <glwidget.h>
#include <jkqtmathtext/jkqtmathtext.h>

class Display : public QWidget {
    Q_OBJECT
public:
    Display(QWidget *parent = nullptr);
public:
    QString text();
public slots:
    void setText(const QString& text);
    void setFromHistory(QListWidgetItem *item);
    void clear();
private:
    void createDisplay();
private:
    QLineEdit *input;
    QVBoxLayout *displayLayout;
    GLWidget *glWidget;
    QSplitter *splitter;
};

#endif
