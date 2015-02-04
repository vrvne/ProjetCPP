//#include "mainwindow.h"
#include "guidewindow.h"
#include <QApplication>
#include "mywindow.h"
#include "simwindow.h"
#include <QMessageBox>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    //MyWindow Window;
    //Window.show();

    //MainWindow Window1;
    //Window1.show();


    GuideWindow Window1;
    Window1.show();

    //QMessageBox::warning(0,"","Bonjour") ;
    return a.exec();
}
