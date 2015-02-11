#include "mywindow.h"
#include "resultwindow.h"
#include "deltaneutral.h"

MyWindow::MyWindow() :QWidget()
{
    // donner un nom à la fenetre
    this->setWindowTitle("Get our suggestion!!!");

    // instancier le pointeur de type QGridLayout
    layout = new QGridLayout ;

    // instancier les deux boutons
    PB_res=new QPushButton("Check our suggestion");
    PB_res->setFont(QFont("Comic Sans MS",14));
    PB_res->setCursor(Qt::PointingHandCursor);


    PB_quit=new QPushButton("Quit");
    PB_quit->setFont(QFont("Comic Sans MS",14));
    PB_quit->setCursor(Qt::PointingHandCursor);


    // instancier les autres Qwidgets
    LE_S0=new QLineEdit;
    LE_K=new QLineEdit;
    LE_r=new QLineEdit;
    LE_sigma=new QLineEdit;
    LE_T=new QLineEdit;
    SB_nCall=new QSpinBox;
    SB_nPut=new QSpinBox;
    RB_long=new QRadioButton("long");
    RB_short=new QRadioButton("short");
    RB_call=new QRadioButton("call");
    RB_put=new QRadioButton("put");

    RB_long->setChecked(true);
    loong=true;
    RB_call->setChecked(true);
    calll=true;
    SB_nPut->setDisabled(true);

    // création de deux groupboxs en utilisant un layout horizontal
    // pour "type d'option" et "position" repectivement
    // avec deux RadioButtons dans chaque groupbox

    groupbox=new QGroupBox("Option Type",this);
    hbox=new QHBoxLayout;
    hbox->addWidget(RB_call);
    hbox->addWidget(RB_put);
    groupbox->setLayout(hbox);

    groupbox2=new QGroupBox("Position",this);
    hbox2=new QHBoxLayout;
    hbox2->addWidget(RB_long);
    hbox2->addWidget(RB_short);
    groupbox2->setLayout(hbox2);

    // instancier les labels

    Label_S0=new QLabel("Initial Value");
    Label_K=new QLabel("Strike");
    Label_r=new QLabel("Interest Rate");
    Label_sigma=new QLabel("Volatility");
    Label_T=new QLabel("Maturity");
    Label_nCall=new QLabel("Number of Calls");
    Label_nPut=new QLabel("Number of Puts");

    // on ajoute dans le layout les widgets que l'on a créés
    // la deuxième colonne (,1)
    layout->addWidget(LE_S0,0,1);
    layout->addWidget(LE_K,1,1);
    layout->addWidget(LE_r,2,1);
    layout->addWidget(LE_sigma,3,1);
    layout->addWidget(LE_T,4,1);
    layout->addWidget(SB_nCall,13,1);
    layout->addWidget(SB_nPut,14,1);
    layout->addWidget(PB_quit,15,1);

    // la première colonne (,0)
    layout->addWidget(Label_S0,0,0);
    layout->addWidget(Label_K,1,0);
    layout->addWidget(Label_r,2,0);
    layout->addWidget(Label_sigma,3,0);
    layout->addWidget(Label_T,4,0);
    layout->addWidget(Label_nCall,13,0);
    layout->addWidget(Label_nPut,14,0);
    layout->addWidget(PB_res,15,0);

    // on y ajoute les deux groupboxs
    layout->addWidget(groupbox2,5,0,2,3);
    layout->addWidget(groupbox,9,0,2,3);

    // on affiche le layout sur la fenêtre
    setLayout(layout);

    // connexion des signaux et des slots

    // si on click sur PB_quit, on quite la fenêtre
    connect(PB_quit,SIGNAL(clicked()),this,SLOT(close())) ;

    // si on click sur PB_res, on exécute la fonction open_result()
    connect(PB_res,SIGNAL(clicked()),this,SLOT(open_result())) ;

    // si coche ou décoche RB_call, on exécute la fonction disable()
    connect(RB_call,SIGNAL(toggled(bool)),this,SLOT(disable()));

    // si coche ou décoche RB_long, on exécute la fonction change_position()
    connect(RB_long,SIGNAL(toggled(bool)),this,SLOT(change_position()));

}

MyWindow::~MyWindow()
{
    delete PB_res;
    delete PB_quit;
    delete LE_S0;
    delete LE_K;
    delete LE_r;
    delete LE_sigma;
    delete LE_T;
    delete SB_nCall;
    delete SB_nPut;
    delete RB_short;
    delete RB_long;
    delete RB_put;
    delete RB_call;
    delete Label_S0;
    delete Label_K;
    delete Label_r;
    delete Label_sigma;
    delete Label_T;
    delete Label_nCall;
    delete Label_nPut;
    delete layout;
    delete groupbox;
    delete groupbox2;
    delete hbox;
    delete hbox2;



}



bool MyWindow::save_S0()
{
    //la fonction permet de prendre ce qui est saisi par utilisateur dans LE_S0 dans la variable S0
    //la fonction renvoi vrai si S0 n'est pas nul
    S0=0;
    QString s1 = LE_S0->text() ;
    QTextStream stream(&s1) ;
    stream >> S0;
    if (S0==0){
        return false;
    }
    return true;
}

bool MyWindow::save_K()
{
    //la fonction permet de prendre ce qui est saisi par utilisateur dans LE_K dans la variable K
    //la fonction renvoi vrai si K n'est pas nul
    K=0;
    QString s1 = LE_K->text() ;
    QTextStream stream(&s1) ;
    stream >> K;
    if (K==0){
        return false;
    }
    return true;
}

bool MyWindow::save_r()
{
    //la fonction permet de prendre ce qui est saisi par utilisateur dans LE_r dans la variable r
    //la fonction renvoi vrai si r n'est pas nul
    r=0;
    QString s1 = LE_r->text() ;
    QTextStream stream(&s1) ;
    stream >> r;
    if (r==0){
        return false;
    }
    return true;
}

bool MyWindow::save_T()
{   //la fonction permet de prendre ce qui est saisi par utilisateur dans LE_T dans la variable T
    //la fonction renvoi vrai si T n'est pas nul
    T=0;
    QString s1 = LE_T->text() ;
    QTextStream stream(&s1) ;
    stream >> T;
    if (T==0){
        return false;
    }
    return true;
}

bool MyWindow::save_n()
{
    //la fonction permet de prendre la valeur de n
    //si c'est un call, n prend la valeur de SB_nCall
    //si c'est un put, n prend la valeur de SB_nPut
    //la fonction renvoi vrai si n n'est pas nul
    n=0;
    if(calll){
        n = SB_nCall->value();
    }
    else{
        n = SB_nPut->value();
    }
    if (n==0){
        return false;
    }
    return true;
}

bool MyWindow::save_sigma()
{
    //la fonction permet de prendre ce qui est saisi par utilisateur dans LE_sigma dans la variable Sigma
    //la fonction renvoi vrai si Sigma n'est pas nul
    sigma=0;
    QString s1 = LE_sigma->text() ;
    QTextStream stream(&s1) ;
    stream >> sigma;
    if (sigma==0){
        return false;
    }
    return true;
}

void MyWindow::open_result()
{
    // Si les LineEdits et n étaient bien saisis, on ouvre le ResultWindow,
    // sinon on affiche une message de warning, qui dit à l'utilisateur de remplir les cases
    if (!save_K() | !save_S0() |!save_T() |!save_n() |!save_r() |!save_sigma() ){
        QString message="ERROR! Please entre a real!";
        QMessageBox::warning(this,"",message) ;
        return ;
    }
    ResultWindow *result=new ResultWindow(this);
    result->show();
}


void MyWindow::disable()
{
    // si le booléen calll est vrai, il devient faux et vice versa
    // en même temps, on active ou désactive les SpinBoxs correspondants
    if(calll){
    calll=false;
    SB_nCall->setDisabled(true);
    SB_nPut->setEnabled(true);

    }
    else{
    calll=true;
    SB_nPut->setDisabled(true);
    SB_nCall->setEnabled(true);
    }
}

void MyWindow::change_position()
{
    // la valeur du booléen loong change si on change la valeur de RadioButton_long
    if(loong){
        loong=false;
    }
    else{
    loong=true;
    }
}

QString MyWindow::message()
{   // la fonction permet d'afficher le resultat calculé dans QString s
    QString s = QString::fromStdString(DeltaNeutral(calll, loong, S0, K, T, r, sigma,n));
    return s;
}
