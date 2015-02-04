#include "resultwindow.h"

ResultWindow::ResultWindow() : QWidget()
{
  this->setWindowTitle("So... there you go");
  PB_Ok2= new QPushButton("OK");
  QGridLayout *layout= new QGridLayout;
  layout->addWidget( PB_Ok2,0,0);
  setLayout(layout);



}

ResultWindow::~ResultWindow()
{
  delete PB_Ok2;


}

void ResultWindow::result()
{

}
