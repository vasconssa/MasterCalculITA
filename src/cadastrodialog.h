#ifndef CADASTRODIALOG_H
#define CADASTRODIALOG_H

#include <QDialog>

namespace Ui {
class CadastroDialog;
}

class CadastroDialog : public QDialog
{
    Q_OBJECT

public:
    explicit CadastroDialog(QWidget *parent = 0);
    ~CadastroDialog();

private:
    Ui::CadastroDialog *ui;
};

#endif // CADASTRODIALOG_H
