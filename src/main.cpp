#include "Interface.h"
#include <QApplication>

int main(int argc, char *argv[]) {
	QApplication a(argc, argv);
	Interface interface;
	interface.show();

	return a.exec();
}
