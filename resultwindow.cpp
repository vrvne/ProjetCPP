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

  // messageW prend le QString défini dans MyWindow::message()
  // et l'affiche dans un QLabel
  QString messageW = window->message();
  LB_res= new QLabel(messageW);

  layout->addWidget( LB_res,0,0);

  connect(PB_Ok2,SIGNAL(clicked()),this,SLOT(close()));

}

ResultWindow::ResultWindow(SimWindow *window) : QWidget()
{
    // titre de la fenêtre
  this->setWindowTitle("So... there you go");
  PB_Ok2= new QPushButton("OK");
  QGridLayout *layout= new QGridLayout;
  layout->addWidget( PB_Ok2,1,0);
  setLayout(layout);

  // messageW prend le QString défini dans SimWindow::message()
  // et l'affiche dans un QLabel
  QString messageW = window->message() ;
  LB_res= new QLabel(messageW);

  layout->addWidget( LB_res,0,0);
  connect(PB_Ok2,SIGNAL(clicked()),this,SLOT(close()));

}

ResultWindow::~ResultWindow()
{
  delete PB_Ok2;
  delete LB_res;

}


