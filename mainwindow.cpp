#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "mywindow.h"
#include "simwindow.h"
#include <QPixmap>
#include <QLabel>
#include <QGridLayout>
#include <QDir>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QLabel *label = new QLabel(this);
    //label->set(50);

    QDir dir = QDir() ;
    QPixmap *p = new QPixmap ;
    QString s = dir.absoluteFilePath("taux.png") ;
    //QMessageBox::warning(0,"",s) ;
    p->load(s);
    //label->setPixmap(*p);

    int w = label->width();
    int h = label->height();

    // set a scaled pixmap to a w x h window keeping its aspect ratio
    label->setPixmap(p->scaled(w,h,Qt::KeepAspectRatio));

    //QGridLayout *gridLayout = new QGridLayout(label);
    //gridLayout->addWidget(label, 0, 0);
    //setLayout(gridLayout);

}

MainWindow::~MainWindow()
{
    delete ui;

}

void MainWindow::on_PushButton_clicked()
{
    MyWindow *window2=new MyWindow;
    window2->show();
}

void MainWindow::on_PushButton_2_clicked()
{
    SimWindow *simwindow2=new SimWindow;
    simwindow2->show();

}
