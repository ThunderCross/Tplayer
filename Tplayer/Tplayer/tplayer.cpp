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
	openAction->setStatusTip(tr("这里是状态栏描述信息"));

	connect(openAction, &QAction::triggered, this, &Tplayer::被单击);
	//将QAction的triggered()信号与TPplayer类的open()函数连接

	QMenu *file = menuBar()->addMenu(tr("&菜单"));

	file->addAction(openAction);


	QToolBar *toolBar = addToolBar(tr("&File"));
	toolBar->addAction(openAction);

	statusBar();

}

void Tplayer::被单击()
{
	int 结果 = QMessageBox::question(this, tr("按钮被单击"), tr("进入中文时代\n你以为这是易语言啊"), tr("难道不是吗"), tr("666"), "", 0, 0);
	//qDebug() << 结果;
	if (结果)
	{
		QMessageBox::information(this, tr("2333..."), tr("渣渣YYY!"));
	}
	else {
		QMessageBox::information(this, tr("2333..."), tr("这都被你发现了"));

	}
}

Tplayer::~Tplayer()
{

}
