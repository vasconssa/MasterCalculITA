#define PY_SSIZE_T_CLEAN
#include <Python.h>
#include "controller.h"
#include <QDir>
#include <QFile>
#include <QDebug>

Controller::Controller(Display *disp):display(disp) {
    const QString DRIVER("QSQLITE");
    if(QSqlDatabase::isDriverAvailable(DRIVER)) {
        db = QSqlDatabase::addDatabase(DRIVER);
    }
    QString db_path = QDir::currentPath();
    qDebug() << db_path;    //current path
    db_path =  db_path + QString("/database");
    db.setDatabaseName(db_path);
    if(!db.open())
        qWarning() << "ERROR: " << db.lastError();
    else
        qDebug() << "Database open with success";
}

int Controller::process(const char *input_expression, const char *output_expression) {

    PyObject *pName, *pModule, *pDict, *pFunc;
    PyObject *pArgs, *pValue;
    int i;

    const char * file = "sympy";
    const char * function = "simplify";


    Py_Initialize();
    //PyRun_SimpleString("from sympy import *\n");
    pName = PyUnicode_DecodeFSDefault(file);

    pModule = PyImport_Import(pName);
    Py_DECREF(pName);

    return 0;

}

void Controller::equalButtonProcess() {
    QString text = display->text();
    text.remove('=');
    qDebug() << text;
    QSqlQuery query;
    query.prepare("INSERT INTO historico(expressao, usuario) VALUES(:expr, 1)");
    query.bindValue(":expr", text);
    if(!query.exec())
      qWarning() << "ERROR: " << query.lastError().text();

    query.prepare("SELECT expressao FROM historico WHERE usuario = 1");
    if(!query.exec())
      qWarning() << "ERROR: " << query.lastError().text();
    history->clear();
    while(query.next()) {
        QString expressao = query.value(0).toString();
        history->addItem(expressao);
    }

}
