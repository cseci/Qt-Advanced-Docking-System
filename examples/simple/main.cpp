#include <QApplication>
#include "../../examples/simple/MainWindow.h"

int main(int argc, char *argv[])
{
//	QCoreApplication::setAttribute(Qt::AA_ShareOpenGLContexts,true);
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
	w.resize(1280,800);

    return a.exec();
}
