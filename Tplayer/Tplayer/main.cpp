#include "tplayer.h"
#include <QtWidgets/QApplication>

#include <QtGui>
#include <QtWidgets>

void �������ڼ�Щ���(Tplayer *main);
void �����������䴰��();

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);

	Tplayer main;
	�������ڼ�Щ���(&main);
	main.show();


	return a.exec();
}
void �������ڼ�Щ���(Tplayer *main)
{
	QMenuBar *��1���˵��б� = main->menuBar();
	QMenu *��2���˵��б� = main->menuBar()->addMenu("�˵�2");
	QAction *AgeAction = new QAction("��������", ��2���˵��б�);
	��2���˵��б�->addAction(AgeAction);
	main->connect(AgeAction, &QAction::triggered, �����������䴰��);
}

void �����������䴰��()
{
	static int �Ƿ��Ѵ��� = false; 
	static QWidget window;
	if (!�Ƿ��Ѵ���)
	{
		window.setWindowTitle("Enter your age");

		QSpinBox *spinBox = new QSpinBox(&window);
		QSlider *slider = new QSlider(Qt::Horizontal, &window);
		spinBox->setRange(0, 130);
		slider->setRange(0, 130);

		QObject::connect(slider, &QSlider::valueChanged, spinBox, &QSpinBox::setValue);
		void (QSpinBox:: *spinBoxSignal)(int) = &QSpinBox::valueChanged;
		QObject::connect(spinBox, spinBoxSignal, slider, &QSlider::setValue);
		spinBox->setValue(35);

		QHBoxLayout *layout = new QHBoxLayout;
		layout->addWidget(spinBox);
		layout->addWidget(slider);
		window.setLayout(layout);
		�Ƿ��Ѵ��� = true;
	}

	window.show();
}
