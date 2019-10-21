#include "Keyboard.h"

Keyboard::Keyboard(QWidget* parent) {
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


    Button *radianButton = new Button("rad");
    Button *asinButton = new Button("\\sin^-1");
    Button *acosButton = new Button("\\cos^-1");
    Button *atanButton = new Button("\\tan^-1");
    Button *piButton = new Button("\\pi");

    numericLayout->addWidget(radianButton, 1, 0);
    numericLayout->addWidget(asinButton, 2, 0);
    numericLayout->addWidget(acosButton, 3, 0);
    numericLayout->addWidget(atanButton, 4, 0);
    numericLayout->addWidget(piButton, 5, 0);

    Button *degreeButton = new Button("\\degree");
    Button *sinButton = new Button("\\sin");
    Button *cosButton = new Button("\\cos");
    Button *tanButton = new Button("\\tan");
    Button *eulerButton = new Button("e");

    numericLayout->addWidget(degreeButton, 1, 1);
    numericLayout->addWidget(sinButton, 2, 1);
    numericLayout->addWidget(cosButton, 3, 1);
    numericLayout->addWidget(tanButton, 4, 1);
    numericLayout->addWidget(eulerButton, 5, 1);

    Button *squareRootButton = new Button("\\sqrt{x}");
    Button *lnButton = new Button("ln");
    Button *logButton = new Button("log");
    Button *power2Button = new Button("x^2");
    Button *powerButton = new Button("x^n");

    numericLayout->addWidget(squareRootButton, 1, 2);
    numericLayout->addWidget(lnButton, 2, 2);
    numericLayout->addWidget(logButton, 3, 2);
    numericLayout->addWidget(power2Button, 4, 2);
    numericLayout->addWidget(powerButton, 5, 2);

    Button *clearButton = new Button(tr("Clear"));
    Button *divisionButton = new Button("\\div");
    Button *timesButton = new Button("\\times");
    Button *minusButton = new Button("-");
    Button *plusButton = new Button("+");

    numericLayout->addWidget(clearButton, 1, 6);
    numericLayout->addWidget(divisionButton, 2, 6);
    numericLayout->addWidget(timesButton, 3, 6);
    numericLayout->addWidget(minusButton, 4, 6);
    numericLayout->addWidget(plusButton, 5, 6);



    Button *leftParButton = new Button("\\left\\right(");
    Button *rigthParButton = new Button("\\left\\right)");
    Button *percentButton = new Button("\\%");
    for (int i = 0; i < NumDigitButtons; ++i) {
        digitButtons[i] = new Button(QString::number(i));
    }
    Button *pointButton = new Button(tr("."));
    Button *equalButton = new Button("=");


    numericLayout->addWidget(leftParButton, 1, 3);
    numericLayout->addWidget(rigthParButton, 1, 4);
    numericLayout->addWidget(percentButton, 1, 5);
    for (int i = 1; i < NumDigitButtons; ++i) {
        int row = ((9 - i) / 3) + 2;
        int column = ((i - 1) % 3) + 3;
        numericLayout->addWidget(digitButtons[i], row, column);
    }

    numericLayout->addWidget(digitButtons[0], 5, 3);
    numericLayout->addWidget(pointButton, 5, 4);
    numericLayout->addWidget(equalButton, 5, 5);

    numericKeyboard->setLayout(numericLayout);

}
