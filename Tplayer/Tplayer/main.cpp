#include "tplayer.h"
#include <QtWidgets/QApplication>

#include <QtGui>
#include <QtWidgets>

void 给主窗口加些配件(Tplayer *main);
void 创建输入年龄窗口();

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);

	Tplayer main;
	给主窗口加些配件(&main);
	main.show();


	return a.exec();
}
void 给主窗口加些配件(Tplayer *main)
{
	QMenuBar *第1个菜单列表 = main->menuBar();
	QMenu *第2个菜单列表 = main->menuBar()->addMenu("菜单2");
	QAction *AgeAction = new QAction("输入年龄", 第2个菜单列表);
	第2个菜单列表->addAction(AgeAction);
	main->connect(AgeAction, &QAction::triggered, 创建输入年龄窗口);
}

void 创建输入年龄窗口()
{
	static int 是否已创建 = false; 
	static QWidget window;
	if (!是否已创建)
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
		是否已创建 = true;
	}

	window.show();
}
