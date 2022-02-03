#ifndef FORMWITHGL_H
#define FORMWITHGL_H

#include <QObject>
#include <QWidget>
#include <ui_form.h>
#include <QPaintEvent>
#include <glwidget.h>

class formWithGL : public QWidget
{
	Q_OBJECT
public:
	Ui::Form *ui;
	formWithGL(QWidget *parent = nullptr);
	~formWithGL();
	void paintEvent(QPaintEvent *pv) override;
//	void loseParent();
private:
	GLWidget *gl;
};

#endif // FORMWITHGL_H
