#include "cadastrodialog.h"
#include "ui_cadastrodialog.h"

CadastroDialog::CadastroDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::CadastroDialog)
{
    ui->setupUi(this);
}

CadastroDialog::~CadastroDialog()
{
    delete ui;
}
