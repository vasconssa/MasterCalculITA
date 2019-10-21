#ifndef INTERFACE_H
#define INTERFACE_H

#include <QMainWindow>
#include <QGraphicsItem>
#include <QtWidgets>
#include "Keyboard.h"
#include "Display.h"

namespace Ui {
    class Interface;
}

class Interface : public QMainWindow {
    Q_OBJECT
public:
        explicit Interface(QWidget *parent = nullptr);
        ~Interface();
private:
        void createLeftSideBar();
        void createRightSideBar();
        void createMainArea();
private:
        Ui::Interface *ui;
        Display *display;
        Keyboard *keyboard;
        QVBoxLayout *leftSideBarLayout;
        QVBoxLayout *rightSideBarLayout;
        QVBoxLayout *canvasLayout;

        QStackedWidget* mainAreaStack;

};

#endif
