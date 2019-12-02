#include "logindialog.h"
#include "ui_logindialog.h"
#include <QMessageBox>

LoginDialog::LoginDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::LoginDialog)
{
    ui->setupUi(this);
}

LoginDialog::~LoginDialog()
{
    delete ui;
}

void LoginDialog::on_pushButton_Login_clicked()
{
    QString username = ui->lineEdit_User->text();
    QString password = ui->lineEdit_Password->text();


    //Chamar função no COntroller pra obter password do usuario
    QString rightPassword = "password";

    if(username=="username" && password == rightPassword){
        //Login realizado com sucesso
        hide();

        //Setar configurações do user global
    }
    else{
        QMessageBox::information(this,"Login","Usuário e senha não conferem.");
    }
}
