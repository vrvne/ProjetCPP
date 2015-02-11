#include "guidewindow.h"


GuideWindow::GuideWindow() : QWidget()
{
    //titre de la fenetre
    this->setWindowTitle("Portfolio Replicating Program");
        label_png = new QLabel();

        //QDir() donne l'access du répertoire du programme
        // on va prendre le chemin d'acces de l'image dans s
        QDir dir = QDir() ;
        QPixmap *p = new QPixmap ;
        QString s = dir.absoluteFilePath("argent.png") ;
        p->load(s);

        // on essaye de garder la même echeclle d'image
        int w = label_png->width();
        int h = label_png->height();

        // on affiche l'image sur label
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

        // on est dirigé vers deux fonctions, si on click sur les deux boutons
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
    // si on click sur PB_res, la fenêtre window2 de type MyWindow s'ouvre
    MyWindow *window2=new MyWindow;
    window2->show();
}

void GuideWindow::on_PB_sim_clicked()
{
    // si on click sur PB_sim, la fenêtre simwindow2 de type SimWindow s'ouvre
    SimWindow *simwindow2=new SimWindow;
    simwindow2->show();

}

