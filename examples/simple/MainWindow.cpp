//#include "../../examples/simple/MainWindow.h"

#include <MainWindow.h>
#include <QLabel>
#include <QTimer>
//#include <glwidget.h>
//#include <formwithgl.h>
#include "ui_MainWindow.h"
#include <QQuickWidget>

MainWindow::MainWindow(QWidget *parent) :
	QMainWindow(parent)
{
	ui = new Ui::MainWindow();
	ui->setupUi(this);
//	QQuickWidget *w = new QQuickWidget(this);
//	ui->centralwidget->layout()->addWidget(w);
    // Create the dock manager. Because the parent parameter is a QMainWindow
    // the dock manager registers itself as the central widget.
	m_DockManager = new ads::CDockManager(this);
	m_DockManager->setConfigFlag(ads::CDockManager::DefaultBaseConfig, true);
	m_DockManager->setStyleSheet("");
//	m_DockManager->setConfigFlag(ads::CDockManager::FloatingContainerForceQWidgetTitleBar, true);

	// Create a dock widget with the title Label 1 and set the created label
	// as the dock widget content

//	GLWidget *l = new GLWidget(this);
//	formWithGL *f = new formWithGL(this);

//	ads::CDockWidget* DockWidget = new ads::CDockWidget("GLWidget");
//	DockWidget->setWidget(l);

//	ads::CDockWidget* DockWidget2 = new ads::CDockWidget("FormGLWidget");
//	DockWidget2->setWidget(f);

	QLabel* l = new QLabel();
	l->setWordWrap(true);
	l->setAlignment(Qt::AlignTop | Qt::AlignLeft);
	l->setText("Lorem ipsum dolor sit amet, consectetuer adipiscing elit. ");

	// Create a dock widget with the title Label 1 and set the created label
	// as the dock widget content
	ads::CDockWidget* DockWidget = new ads::CDockWidget("Label 1");
	DockWidget->setWidget(l);
	DockWidget->setFeature(ads::CDockWidget::DockWidgetFloatable, false);

	QLabel* l2 = new QLabel();
	l2->setWordWrap(true);
	l2->setAlignment(Qt::AlignTop | Qt::AlignLeft);
	l2->setText("AYYYY LMAO. ");

	// Create a dock widget with the title Label 1 and set the created label
	// as the dock widget content
	ads::CDockWidget* DockWidget2 = new ads::CDockWidget("Label 2");
	DockWidget2->setWidget(l2);
	DockWidget2->setFeature(ads::CDockWidget::DockWidgetFloatable, false);


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

