#include <QtGui>
#include <QtWidgets>

#include "tplayer.h"

Tplayer::Tplayer(QWidget *parent)
	: QMainWindow(parent)
{
	//ui.setupUi(this);

	this->setWindowTitle("Main Window");

	aboutAction = new QAction(QIcon(":Tplayer/doc-ico"), tr("&About"), this);
	aboutAction->setShortcuts(QKeySequence::HelpContents);
	aboutAction->setStatusTip(tr("������״̬��������Ϣ"));

	openAction = new QAction(QIcon(":/images/file-open"), tr("&Open..."), this);
	openAction->setShortcuts(QKeySequence::Open);
	openAction->setStatusTip(tr("Open an existing file"));

	saveAction = new QAction(QIcon(":/images/file-save"), tr("&Save..."), this);
	saveAction->setShortcuts(QKeySequence::Save);
	saveAction->setStatusTip(tr("Save a new file"));

	QMenu *file = this->menuBar()->addMenu(tr("&�˵�1"));
	file->addAction(openAction);
	file->addAction(saveAction);
	file->addAction(aboutAction);

	QToolBar *toolBar = addToolBar(tr("&File"));
	toolBar->addAction(openAction);
	toolBar->addAction(saveAction);

	textEdit = new QTextEdit(this);
	setCentralWidget(textEdit);

	connect(aboutAction, &QAction::triggered, this, &Tplayer::about);
	connect(openAction, &QAction::triggered, this, &Tplayer::openFile);
	connect(saveAction, &QAction::triggered, this, &Tplayer::saveFile);
	//��QAction��triggered()�ź���TPplayer��� ��ť������() ��������

	statusBar();

}

void Tplayer::about()
{
	int ��� = QMessageBox::question(this, tr("��ť������"), tr("vs��������ʱ��\n����Ϊ���������԰�"), tr("�ѵ�������"), tr("666"), "", 0, 0);
	//qDebug() << ���;
	if (���)
	{
		QMessageBox::information(this, tr("2333..."), tr("����YYY!"));
	}
	else {
		QMessageBox::information(this, tr("2333..."), tr("�ⶼ���㷢����"));

	}
}
void Tplayer::openFile()
{
	QString path = QFileDialog::getOpenFileName(this,
		tr("Open File"),
		".",
		tr("Text Files(*.txt)"));
	if (!path.isEmpty()) {
		QFile file(path);
		if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
			QMessageBox::warning(this, tr("Read File"),
				tr("Cannot open file:\n%1").arg(path));
			return;
		}
		QTextStream in(&file);
		textEdit->setText(in.readAll());
		file.close();
	}
	else {
		QMessageBox::warning(this, tr("Path"),
			tr("You did not select any file."));
	}
}

void Tplayer::saveFile()
{
	QString path = QFileDialog::getSaveFileName(this,
		tr("Open File"),
		".",
		tr("Text Files(*.txt)"));
	if (!path.isEmpty()) {
		QFile file(path);
		if (!file.open(QIODevice::WriteOnly | QIODevice::Text)) {
			QMessageBox::warning(this, tr("Write File"),
				tr("Cannot open file:\n%1").arg(path));
			return;
		}
		QTextStream out(&file);
		out << textEdit->toPlainText();
		file.close();
	}
	else {
		QMessageBox::warning(this, tr("Path"),
			tr("You did not select any file."));
	}
}
Tplayer::~Tplayer()
{

}
