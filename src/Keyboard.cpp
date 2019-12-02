#include "Keyboard.h"

Keyboard::Keyboard(Display* display, Controller *cont, QWidget* parent):display(display), controller(cont) {
    createNumericKeyboard();
    tabWidget = new QTabWidget;
    tabWidget->addTab(numericKeyboard, QIcon(QString(":/resources/images/calculator.png")), "");
    QVBoxLayout *mainLayout = new QVBoxLayout;
    mainLayout->addWidget(tabWidget);
    setLayout(mainLayout);
}

void Keyboard::createNumericKeyboard() {
    numericKeyboard = new QWidget;
    QGridLayout *numericLayout = new QGridLayout;

    //numericLayout->setSizeConstraint(QLayout::SetFixedSize);


    Button *radianButton = createButton("rad", SLOT(buttonClicked()));
    Button *asinButton = createButton("\\sin^{-1}", SLOT(buttonClicked()));
    Button *acosButton = createButton("\\cos^{-1}", SLOT(buttonClicked()));
    Button *atanButton = createButton("\\tan^{-1}", SLOT(buttonClicked()));
    Button *piButton = createButton("\\pi", SLOT(buttonClicked()));

    numericLayout->addWidget(radianButton, 1, 0);
    numericLayout->addWidget(asinButton,   2, 0);
    numericLayout->addWidget(acosButton,   3, 0);
    numericLayout->addWidget(atanButton,   4, 0);
    numericLayout->addWidget(piButton,     5, 0);

    Button *degreeButton = createButton("\\degree", SLOT(buttonClicked()));
    Button *sinButton = createButton("\\sin", SLOT(buttonClicked()));
    Button *cosButton = createButton("\\cos", SLOT(buttonClicked()));
    Button *tanButton = createButton("\\tan", SLOT(buttonClicked()));
    Button *eulerButton = createButton("e", SLOT(buttonClicked()));

    numericLayout->addWidget(degreeButton, 1, 1);
    numericLayout->addWidget(sinButton,    2, 1);
    numericLayout->addWidget(cosButton,    3, 1);
    numericLayout->addWidget(tanButton,    4, 1);
    numericLayout->addWidget(eulerButton,  5, 1);

    Button *squareRootButton = createButton("\\sqrt{x}", SLOT(buttonClicked()));
    Button *lnButton = createButton("ln", SLOT(buttonClicked()));
    Button *logButton = createButton("log", SLOT(buttonClicked()));
    Button *power2Button = createButton("x^2", SLOT(buttonClicked()));
    Button *powerButton = createButton("x^n", SLOT(buttonClicked()));

    numericLayout->addWidget(squareRootButton, 1, 2);
    numericLayout->addWidget(lnButton,         2, 2);
    numericLayout->addWidget(logButton,        3, 2);
    numericLayout->addWidget(power2Button,     4, 2);
    numericLayout->addWidget(powerButton,      5, 2);

    Button *clearButton = new Button("Clear");
    connect(clearButton, SIGNAL(clicked()), display, SLOT(clear()));
    Button *divisionButton = createButton("\\div", SLOT(buttonClicked()));
    Button *timesButton = createButton("\\times", SLOT(buttonClicked()));
    Button *minusButton = createButton("-", SLOT(buttonClicked()));
    Button *plusButton = createButton("+", SLOT(buttonClicked()));

    numericLayout->addWidget(clearButton,    1, 6);
    numericLayout->addWidget(divisionButton, 2, 6);
    numericLayout->addWidget(timesButton,    3, 6);
    numericLayout->addWidget(minusButton,    4, 6);
    numericLayout->addWidget(plusButton,     5, 6);



    Button *leftParButton = createButton("\\left\\right(", SLOT(buttonClicked()));
    Button *rigthParButton = createButton("\\left\\right)", SLOT(buttonClicked()));
    Button *percentButton = createButton("\\%", SLOT(buttonClicked()));
    for (int i = 0; i < NumDigitButtons; ++i){
        digitButtons[i] = createButton(QString::number(i), SLOT(buttonClicked()));
    }
    Button *pointButton = createButton(tr("."), SLOT(buttonClicked()));
    Button *equalButton = createButton("=", SLOT(buttonClicked()));
    connect(equalButton, SIGNAL(clicked()), controller, SLOT(equalButtonProcess()));


    numericLayout->addWidget(leftParButton,    1, 3);
    numericLayout->addWidget(rigthParButton,   1, 4);
    numericLayout->addWidget(percentButton,    1, 5);
    for (int i = 1; i < NumDigitButtons; ++i) {
        int row = ((9 - i) / 3) + 2;
        int column = ((i - 1) % 3) + 3;
        numericLayout->addWidget(digitButtons[i], row, column);
    }

    numericLayout->addWidget(digitButtons[0], 5, 3);
    numericLayout->addWidget(pointButton,     5, 4);
    numericLayout->addWidget(equalButton,     5, 5);

    numericKeyboard->setLayout(numericLayout);

}

Button *Keyboard::createButton(const QString &latexText, const char *member)
{
    Button *button = new Button(latexText);
    connect(button, SIGNAL(clicked()), this, member);
    return button;
}

void Keyboard::buttonClicked() {
    Button *clickedButton = qobject_cast<Button *>(sender());
    QString value = clickedButton->text();
    display->setText(display->text() + value);
}
