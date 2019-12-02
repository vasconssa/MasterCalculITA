#include "Interface.h"
#include <QApplication>
#include <logindialog.h>

int main(int argc, char *argv[]) {
	QApplication a(argc, argv);
//	Interface interface;
//	interface.show();

    LoginDialog ld;

    ld.show();


	return a.exec();
}
