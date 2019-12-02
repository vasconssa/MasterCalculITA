#include "logindialog.h"
#include "ui_logindialog.h"
#include <QMessageBox>
#include <cadastrodialog.h>

LoginDialog::LoginDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::LoginDialog)
{
    ui->setupUi(this);

    return;

    QString logoPath = QString(":/resources/images/master_logo.png");
    QImage image(logoPath);


    ui->label_Image->setPixmap(QPixmap::fromImage(image));


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

void LoginDialog::on_pushButton_NewUser_clicked()
{
    hide();
    cd = new CadastroDialog(this);

    cd->show();

}
