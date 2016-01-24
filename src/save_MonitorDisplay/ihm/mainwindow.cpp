#include "mainwindow.h"
#include "ui_IHM.h"

#include <QDesktopWidget>

MainWindow::MainWindow(QWidget *parent) :
  QMainWindow(parent),
  ui(new Ui::MainWindow)
{
  ui->setupUi(this);

  QRect screenGeometry = QApplication::desktop()->screenGeometry();
  int x = (screenGeometry.width()-this->width()) / 2;
  int y = (screenGeometry.height()-this->height()) / 2;
  move(x, y);

  QObject::connect((ui->pushButton), SIGNAL(clicked()), this, SLOT(quit())); // Exit program (dont work)
}

MainWindow::~MainWindow()
{
  delete ui;
}
