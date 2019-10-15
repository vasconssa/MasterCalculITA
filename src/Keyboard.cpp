#include "Keyboard.h"
Keyboard::Keyboard(QWidget* parent) {
    createButtons();
}

void Keyboard::createButtons() {

    for (int i = 0; i < NumDigitButtons; ++i) {
        digitButtons[i] = new Button(QString::number(i));
    }

    Button *pointButton = new Button(tr("."));
    Button *changeSignButton = new Button(tr("\302\261"));

    Button *backspaceButton = new Button(tr("Backspace"));
    Button *clearButton = new Button(tr("Clear"));
    Button *clearAllButton = new Button(tr("Clear All"));

    Button *clearMemoryButton = new Button(tr("MC"));
    Button *readMemoryButton = new Button(tr("MR"));
    Button *setMemoryButton = new Button(tr("MS"));
    Button *addToMemoryButton = new Button(tr("M+"));

    Button *divisionButton = new Button(tr("\303\267"));
    Button *timesButton = new Button(tr("\303\227"));
    Button *minusButton = new Button(tr("-"));
    Button *plusButton = new Button(tr("+"));

    Button *squareRootButton = new Button(tr("Sqrt"));
    Button *powerButton = new Button(tr("x\302\262"));
    Button *reciprocalButton = new Button(tr("1/x"));
    Button *equalButton = new Button(tr("="));

    QGridLayout *mainLayout = new QGridLayout;
    mainLayout->setSizeConstraint(QLayout::SetFixedSize);
    mainLayout->addWidget(backspaceButton, 1, 0, 1, 2);
    mainLayout->addWidget(clearButton, 1, 2, 1, 2);
    mainLayout->addWidget(clearAllButton, 1, 4, 1, 2);

    mainLayout->addWidget(clearMemoryButton, 2, 0);
    mainLayout->addWidget(readMemoryButton, 3, 0);
    mainLayout->addWidget(setMemoryButton, 4, 0);
    mainLayout->addWidget(addToMemoryButton, 5, 0);

    for (int i = 1; i < NumDigitButtons; ++i) {
        int row = ((9 - i) / 3) + 2;
        int column = ((i - 1) % 3) + 1;
        mainLayout->addWidget(digitButtons[i], row, column);
    }

    mainLayout->addWidget(digitButtons[0], 5, 1);
    mainLayout->addWidget(pointButton, 5, 2);
    mainLayout->addWidget(changeSignButton, 5, 3);

    mainLayout->addWidget(divisionButton, 2, 4);
    mainLayout->addWidget(timesButton, 3, 4);
    mainLayout->addWidget(minusButton, 4, 4);
    mainLayout->addWidget(plusButton, 5, 4);

    mainLayout->addWidget(squareRootButton, 2, 5);
    mainLayout->addWidget(powerButton, 3, 5);
    mainLayout->addWidget(reciprocalButton, 4, 5);
    mainLayout->addWidget(equalButton, 5, 5);
    setLayout(mainLayout);

}
