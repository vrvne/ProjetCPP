#include "guidewindow.h"


GuideWindow::GuideWindow() : QWidget()
{
    this->setWindowTitle("Portfolio Replicating Program");
        label_png = new QLabel();
        //label->set(50);

        QDir dir = QDir() ;
        QPixmap *p = new QPixmap ;
        QString s = dir.absoluteFilePath("argent.png") ;
        //QMessageBox::warning(0,"",s) ;
        p->load(s);
        //label->setPixmap(*p);

        int w = label_png->width();
        int h = label_png->height();

        // set a scaled pixmap to a w*h window keeping its aspect ratio
        label_png->setPixmap(p->scaled(w,h,Qt::KeepAspectRatio));

        QGridLayout *gridLayout = new QGridLayout;
        gridLayout->addWidget(label_png, 0, 0);
        setLayout(gridLayout);

        label_welcome = new QLabel("Welcome to our Portfolio Replicating simulation program!!!");
        gridLayout->addWidget(label_welcome, 0, 1);


        PB_res=new QPushButton("Portfolio Replicating");
        PB_res->setFont(QFont("Comic Sans MS",14));
        PB_res->setCursor(Qt::PointingHandCursor);
        gridLayout->addWidget(PB_res,2,0);


        PB_sim=new QPushButton("Simulation");
        PB_sim->setFont(QFont("Comic Sans MS",14));
        PB_sim->setCursor(Qt::PointingHandCursor);
        gridLayout->addWidget(PB_sim,2,1);

        connect(PB_res,SIGNAL(clicked()),this,SLOT(on_PB_res_clicked())) ;
        connect(PB_sim,SIGNAL(clicked()),this,SLOT(on_PB_sim_clicked())) ;


}

GuideWindow::~GuideWindow()
{
    delete label_png;
    delete label_welcome;
    delete PB_res;
    delete PB_sim;
}

void GuideWindow::on_PB_res_clicked()
{
    MyWindow *window2=new MyWindow;
    window2->show();
}

void GuideWindow::on_PB_sim_clicked()
{
    SimWindow *simwindow2=new SimWindow;
    simwindow2->show();

}

