#ifndef CONTROLLER_H
#define CONTROLLER_H

#include <QObject>
#include <QWidget>
#include <QSqlDatabase>
#include <QSqlDriver>
#include <QSqlError>
#include <QSqlQuery>
#include <Display.h>

class Controller : public QWidget
{
    Q_OBJECT
public:
    Controller(Display *disp);
    int process(const char* input_expression, const char* output_expression);
    void setHistoryWidget(QListWidget *wd) { history = wd;}
public slots:
    void equalButtonProcess();
private:
    QSqlDatabase db;
    Display *display;
    QListWidget *history;
};

#endif // CONTROLLER_H
