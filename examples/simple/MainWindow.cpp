#include "../../examples/simple/MainWindow.h"

#include "ui_MainWindow.h"

#include <QLabel>
#include <QTimer>
#include <glwidget.h>
#include <formwithgl.h>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    // Create the dock manager. Because the parent parameter is a QMainWindow
    // the dock manager registers itself as the central widget.
	m_DockManager = new ads::CDockManager(this);

	// Create a dock widget with the title Label 1 and set the created label
	// as the dock widget content

	GLWidget *l = new GLWidget(this);
	formWithGL *f = new formWithGL(this);

	ads::CDockWidget* DockWidget = new ads::CDockWidget("GLWidget");
	DockWidget->setWidget(l);

	ads::CDockWidget* DockWidget2 = new ads::CDockWidget("FormGLWidget");
	DockWidget2->setWidget(f);

//	QTabWidget *tab = new QTabWidget(this);
//	tab->addTab(new GLWidget(this),"GL");
//	tab->addTab(new formWithGL(this),"form");
//	ads::CDockWidget* tabDock = new ads::CDockWidget("tabDock");
//	tabDock->setWidget(tab);
//	tab->setCurrentIndex(1);

	// Add the toggleViewAction of the dock widget to the menu to give
	// the user the possibility to show the dock widget if it has been closed
	ui->menuView->addAction(DockWidget->toggleViewAction());
	// Add the toggleViewAction of the dock widget to the menu to give
	// the user the possibility to show the dock widget if it has been closed
	ui->menuView->addAction(DockWidget2->toggleViewAction());
//	ui->menuView->addAction(tabDock->toggleViewAction());

	// Add the dock widget to the top dock widget area
	m_DockManager->addDockWidget(ads::TopDockWidgetArea, DockWidget);
	// Add the dock widget to the top dock widget area
	m_DockManager->addDockWidgetTab(ads::TopDockWidgetArea, DockWidget2);
//	m_DockManager->addDockWidget(ads::BottomDockWidgetArea,tabDock);
//	tab->setSizePolicy(QSizePolicy::Maximum,QSizePolicy::Maximum);


}

MainWindow::~MainWindow()
{
    delete ui;
}

