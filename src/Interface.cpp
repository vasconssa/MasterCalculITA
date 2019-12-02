#include "Interface.h"
#include "ui_Interface.h"

Interface::Interface(QWidget *parent) : QMainWindow(parent), ui(new Ui::Interface) {

    ui->setupUi(this);
    leftSideBarLayout = ui->leftSideBarLayout;
    rightSideBarLayout = ui->rightSideBarLayout;
    canvasLayout = ui->canvasLayout;
    mainAreaStack = new QStackedWidget;
    createMainArea();
    createLeftSideBar();
    createRightSideBar();
}

Interface::~Interface() {
    delete ui;
}

void Interface::createMainArea() {
    display = new Display;
    auto mainAreaLayout = new QVBoxLayout;
    controler = new Controller(display);
    keyboard = new Keyboard(display, controler);

    mainAreaLayout->addWidget(display);
    mainAreaLayout->addWidget(keyboard);

    auto mainAreaWidget = new QWidget;
    mainAreaWidget->setLayout(mainAreaLayout);

    mainAreaStack->addWidget(mainAreaWidget);
    mainAreaStack->setSizePolicy(QSizePolicy::Expanding,QSizePolicy::Expanding);

    auto functionAreaWidget = new QWidget;
    mainAreaStack->addWidget(functionAreaWidget);

    auto userAreaWidget = new QWidget;
    mainAreaStack->addWidget(userAreaWidget);
    canvasLayout->addWidget(mainAreaStack);

}

void Interface::createLeftSideBar() {
    auto left= new QVBoxLayout;
    QGroupBox *groupBox = new QGroupBox();
    QPushButton *functionButton = new QPushButton("&Funções Personalizadas", this);
    functionButton->setCheckable(true);
    QPushButton *userAreaButton = new QPushButton("&Area do Usuário", this);
    functionButton->setCheckable(true);
    QPushButton *calculatorButton = new QPushButton("&Calculadora", this);
    calculatorButton->setCheckable(true);
    calculatorButton->setChecked(true);
    left->addWidget(calculatorButton);
    left->addWidget(functionButton);
    left->addWidget(userAreaButton);
    left->addStretch(1);
    groupBox->setLayout(left);
    leftSideBarLayout->addWidget(groupBox);

    auto signalMapper = new QSignalMapper(this);
    connect(functionButton, SIGNAL(clicked()), signalMapper, SLOT(map()));
    connect(calculatorButton, SIGNAL(clicked()), signalMapper, SLOT(map()));
    connect(userAreaButton, SIGNAL(clicked()), signalMapper, SLOT(map()));
    signalMapper->setMapping(calculatorButton, 0);
    signalMapper->setMapping(functionButton, 1);
    signalMapper->setMapping(userAreaButton, 2);
    //groupBox->setSizePolicy(QSizePolicy::Expanding,QSizePolicy::Expanding);

    connect(signalMapper, SIGNAL(mapped(int)), mainAreaStack, SLOT(setCurrentIndex(int)));
    //connect(signalMapper, SIGNAL(mapped(bool)), functionButton, SLOT(setChecked(bool)));
    //connect(signalMapper, SIGNAL(!mapped(int)), calculatorButton, SLOT(setChecked(bool)));
}

void Interface::createRightSideBar() {
    auto right = new QVBoxLayout;
    historyListWidget = new QListWidget(this);
    connect(historyListWidget, SIGNAL(itemDoubleClicked(QListWidgetItem *)),display, SLOT(setFromHistory(QListWidgetItem *)));
    controler->setHistoryWidget(historyListWidget);
    mainAreaStack->setSizePolicy(QSizePolicy::MinimumExpanding,QSizePolicy::MinimumExpanding);
    rightSideBarLayout->addWidget(historyListWidget);
}
