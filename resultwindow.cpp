#include "resultwindow.h"
#include "mywindow.h"
#include "simwindow.h"

ResultWindow::ResultWindow(MyWindow *window) : QWidget()
{
  this->setWindowTitle("So... there you go");
  PB_Ok2= new QPushButton("OK");
  QGridLayout *layout= new QGridLayout;
  layout->addWidget( PB_Ok2,1,0);
  setLayout(layout);

  QString messageW = window->message() ;

  LB_res= new QLabel(messageW);

  layout->addWidget( LB_res,0,0);
  connect(PB_Ok2,SIGNAL(clicked()),this,SLOT(close()));

}

ResultWindow::ResultWindow(SimWindow *window) : QWidget()
{
  this->setWindowTitle("So... there you go");
  PB_Ok2= new QPushButton("OK");
  QGridLayout *layout= new QGridLayout;
  layout->addWidget( PB_Ok2,1,0);
  setLayout(layout);

  QString messageW = window->message() ;

  LB_res= new QLabel(messageW);

  layout->addWidget( LB_res,0,0);

}

ResultWindow::~ResultWindow()
{
  delete PB_Ok2;
  delete LB_res;


}


