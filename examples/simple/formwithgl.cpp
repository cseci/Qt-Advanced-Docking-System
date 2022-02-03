#include "formwithgl.h"
#include "ui_form.h"
#include <QOpenGLWidget>

formWithGL::formWithGL(QWidget *parent) : QWidget(parent)
{
	ui = new Ui::Form();
	ui->setupUi(this);
	gl = new GLWidget(ui->widget);
	ui->widget->setAttribute(Qt::WA_DeleteOnClose);
	//gl->setAttribute(Qt::WA_AlwaysStackOnTop);
//	gl->setUpdateBehavior(QOpenGLWidget::NoPartialUpdate);
//	connect(ui->pushButton,SIGNAL(clicked()),this,SLOT(loseParent()));
}

formWithGL::~formWithGL()
{
	delete gl;

}

void formWithGL::paintEvent(QPaintEvent *pv) {	
	QWidget::paintEvent(pv);
}



/*


*/
