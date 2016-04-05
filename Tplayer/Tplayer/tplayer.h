#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QtWidgets/QMainWindow>
#include "ui_tplayer.h"

//#include <QtCore>
//#include <QTextEdit>

#ifdef _MSC_VER
#pragma execution_character_set("utf-8")
#endif

class QTextEdit;

class Tplayer : public QMainWindow
{
	Q_OBJECT

public:
	Tplayer(QWidget *parent = 0);
	~Tplayer();

private:
	void openFile();
	void saveFile();

	void about();

	QTextEdit *textEdit;

	QAction *aboutAction;
	QAction *openAction;
	QAction *saveAction;

	Ui::TplayerClass ui;
};

#endif // TPLAYER_H
