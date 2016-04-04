#include "tplayer.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);

	Tplayer w;
	w.show();

	return a.exec();
}
