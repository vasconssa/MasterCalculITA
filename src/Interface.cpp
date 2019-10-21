#include "Interface.h"
#include "ui_Interface.h"

Interface::Interface(QWidget *parent) : QMainWindow(parent), ui(new Ui::Interface) {

    ui->setupUi(this);
    leftSideBarLayout = ui->leftSideBarLayout;
    rightSideBarLayout = ui->rightSideBarLayout;
    canvasLayout = ui->canvasLayout;
    createMainArea();
}

Interface::~Interface() {
    delete ui;
}

void Interface::createMainArea() {
    display = new Display;
    auto mainAreaLayout = new QVBoxLayout;
    keyboard = new Keyboard;

    mainAreaLayout->addWidget(display);
    mainAreaLayout->addWidget(keyboard);
    auto mainAreaWidget = new QWidget;
    mainAreaWidget->setLayout(mainAreaLayout);
    mainAreaStack = new QStackedWidget;
    mainAreaStack->addWidget(mainAreaWidget);
    canvasLayout->addWidget(mainAreaStack);

}

void Interface::createLeftSideBar() {
}

void Interface::createRightSideBar() {
}
