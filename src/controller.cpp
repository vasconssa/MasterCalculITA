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
    Py_Initialize();
    PyRun_SimpleString("import sys");
    PyRun_SimpleString("sys.path.append(\".\")");
}

int Controller::process(const char *input_expression, QString &output_expression) {

    PyObject *pName, *pModule, *pDict, *pFunc;
    PyObject *pArgs, *pValue;
    int i;

    const char * file = "use_sympy";
    const char * func = "process";

    QString db_path = QDir::currentPath();

    //PyRun_SimpleString("from sympy import *\n");
    pName = PyUnicode_FromString(file);

    pModule = PyImport_Import(pName);
    Py_DECREF(pName);

    if (pModule != NULL) {
        pFunc = PyObject_GetAttrString(pModule, func);
        if (pFunc && PyCallable_Check(pFunc)) {
            pArgs = PyTuple_New(1);
            pValue = PyUnicode_FromString(input_expression);
            if (!pValue) {
                Py_DECREF(pArgs);
                Py_DECREF(pModule);
                fprintf(stderr, "Cannot convert argument\n");
                return 1;
            }
            PyTuple_SetItem(pArgs, 0, pValue);
            pValue = PyObject_CallObject(pFunc, pArgs);
            Py_DECREF(pArgs);
            if (pValue != NULL) {
                pValue = PyObject_Str(pValue);
                printf("Result of call: %s\n", PyUnicode_AsUTF8(pValue));
                Py_ssize_t size;
                output_expression = QString(PyUnicode_AsUTF8(pValue));
                printf("Result of call: %s\n", output_expression.toLatin1().data());
                Py_DECREF(pValue);
            }
            else {
                Py_DECREF(pFunc);
                Py_DECREF(pModule);
                PyErr_Print();
                fprintf(stderr,"Call failed\n");
                return 1;
            }
        }
        else {
            if (PyErr_Occurred())
                PyErr_Print();
            fprintf(stderr, "Cannot find function \"%s\"\n", func);
        }
        Py_XDECREF(pFunc);
        Py_DECREF(pModule);
    }
    else {
        PyErr_Print();
        fprintf(stderr, "Failed to load \"%s\"\n", file);
        return 1;
    }
    //Py_Finalize();

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
    QString output;
    process(text.toLatin1().data(), output);
    output.replace("\log", "\log ");
    qDebug() << QString(output);
    QString newText = text + "=" + output;
    display->setText(newText);

}
