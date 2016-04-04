#ifndef TPLAYER_H
#define TPLAYER_H

#include <QtWidgets/QMainWindow>
#include "ui_tplayer.h"

#include <QtCore>

#ifdef _MSC_VER
#pragma execution_character_set("utf-8")
#endif

class Tplayer : public QMainWindow
{
	Q_OBJECT

public:
	Tplayer(QWidget *parent = 0);
	~Tplayer();

private:
	void ±»µ¥»÷();
	QAction *openAction;

	Ui::TplayerClass ui;
};

#endif // TPLAYER_H
