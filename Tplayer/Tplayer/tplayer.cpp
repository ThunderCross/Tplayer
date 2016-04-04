#include "tplayer.h"
#include <QMessageBox>

#include <QAction>
#include <QMenuBar>
#include <QToolBar>


Tplayer::Tplayer(QWidget *parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);

	this->setWindowTitle("Main Window");

	openAction = new QAction(QIcon(":Tplayer/doc-ico"), tr("&button..."), this);
	openAction->setShortcuts(QKeySequence::Open);
	openAction->setStatusTip(tr("������״̬��������Ϣ"));

	connect(openAction, &QAction::triggered, this, &Tplayer::������);
	//��QAction��triggered()�ź���TPplayer���open()��������

	QMenu *file = menuBar()->addMenu(tr("&�˵�"));

	file->addAction(openAction);


	QToolBar *toolBar = addToolBar(tr("&File"));
	toolBar->addAction(openAction);

	statusBar();

}

void Tplayer::������()
{
	int ��� = QMessageBox::question(this, tr("��ť������"), tr("��������ʱ��\n����Ϊ���������԰�"), tr("�ѵ�������"), tr("666"), "", 0, 0);
	//qDebug() << ���;
	if (���)
	{
		QMessageBox::information(this, tr("2333..."), tr("����YYY!"));
	}
	else {
		QMessageBox::information(this, tr("2333..."), tr("�ⶼ���㷢����"));

	}
}

Tplayer::~Tplayer()
{

}
