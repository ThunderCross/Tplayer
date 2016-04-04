#ifndef TPLAYER_H
#define TPLAYER_H

#include <QtWidgets/QMainWindow>
#include "ui_tplayer.h"

class Tplayer : public QMainWindow
{
	Q_OBJECT

public:
	Tplayer(QWidget *parent = 0);
	~Tplayer();

private:
	Ui::TplayerClass ui;
};

#endif // TPLAYER_H
