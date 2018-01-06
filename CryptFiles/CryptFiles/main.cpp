#include "CryptFiles.h"
#include <QtWidgets/QApplication>
int main(int argc, char *argv[])
{

	QApplication a(argc, argv);
	CryptFiles w;
	w.show(); // GUI object

	return a.exec();
}
