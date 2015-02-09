
#include "simwindow.h"
#include "resultwindow.h"

#include "deltaneutral.h"

SimWindow::SimWindow() : QWidget()
{
    this->setWindowTitle("Get our simulations!!!!");
    QGridLayout *layout = new QGridLayout ;

    PB_sim=new QPushButton("Simulation");
    PB_sim->setFont(QFont("Comic Sans MS",14));
    PB_sim->setCursor(Qt::PointingHandCursor);
    layout->addWidget(PB_sim,15,0);

    PB_quit=new QPushButton("Quit");
    PB_quit->setFont(QFont("Comic Sans MS",14));
    PB_quit->setCursor(Qt::PointingHandCursor);
    layout->addWidget(PB_quit,15,1);


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

    QGroupBox *groupbox=new QGroupBox("Option Type",this);
    QHBoxLayout *hbox=new QHBoxLayout;
    hbox->addWidget(RB_call);
    hbox->addWidget(RB_put);
    groupbox->setLayout(hbox);

    QGroupBox *groupbox2=new QGroupBox("Position",this);
    QHBoxLayout *hbox2=new QHBoxLayout;
    hbox2->addWidget(RB_long);
    hbox2->addWidget(RB_short);
    groupbox2->setLayout(hbox2);


    Label_S0=new QLabel("Initial Value");
    Label_K=new QLabel("Strike");
    Label_r=new QLabel("Interest Rate");
    Label_sigma=new QLabel("Volatility");
    Label_T=new QLabel("Maturity");
    Label_nCall=new QLabel("Number of Calls");
    Label_nPut=new QLabel("Number of Puts");



    layout->addWidget(LE_S0,0,1);
    layout->addWidget(LE_K,1,1);
    layout->addWidget(LE_r,2,1);
    layout->addWidget(LE_sigma,3,1);
    layout->addWidget(LE_T,4,1);
    layout->addWidget(SB_nCall,13,1);
    layout->addWidget(SB_nPut,14,1);

    layout->addWidget(Label_S0,0,0);
    layout->addWidget(Label_K,1,0);
    layout->addWidget(Label_r,2,0);
    layout->addWidget(Label_sigma,3,0);
    layout->addWidget(Label_T,4,0);


    layout->addWidget(groupbox2,5,0,2,3);
    layout->addWidget(groupbox,9,0,2,3);

    layout->addWidget(Label_nCall,13,0);
    layout->addWidget(Label_nPut,14,0);

    setLayout(layout);

    connect(PB_quit,SIGNAL(clicked()),this,SLOT(close())) ;
    connect(PB_sim,SIGNAL(clicked()),this,SLOT(open_simulation())) ;
    connect(RB_call,SIGNAL(toggled(bool)),this,SLOT(disable(bool)));
    connect(RB_long,SIGNAL(toggled(bool)),this,SLOT(change_position(bool)));

}

SimWindow::~SimWindow()
{
    delete PB_sim;
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

}


bool SimWindow::save_S0()
{
    S0=0;
    QString s1 = LE_S0->text() ;
    QTextStream stream(&s1) ;
    stream >> S0;
    if (S0==0){
        return false;
    }
    return true;
}

bool SimWindow::save_K()
{
    K=0;
    QString s1 = LE_K->text() ;
    QTextStream stream(&s1) ;
    stream >> K;
    if (K==0){
        return false;
    }
    return true;
}

bool SimWindow::save_r()
{
    r=0;
    QString s1 = LE_r->text() ;
    QTextStream stream(&s1) ;
    stream >> r;
    if (r==0){
        return false;
    }
    return true;
}

bool SimWindow::save_T()
{
    T=0;
    QString s1 = LE_T->text() ;
    QTextStream stream(&s1) ;
    stream >> T;
    if (T==0){
        return false;
    }
    return true;
}

bool SimWindow::save_n(bool calll)
{
    if(calll){
    n = SB_nCall->value();
    }
    else{
    n = SB_nPut->value();
    }
    return true ;
}

bool SimWindow::save_sigma()
{
    sigma=0;
    QString s1 = LE_sigma->text() ;
    QTextStream stream(&s1) ;
    stream >> sigma;
    if (sigma==0){
        return false;
    }
    return true;
}

void SimWindow::open_simulation()
{
    if (!save_K() | !save_S0() |!save_T() |!save_n(calll) |!save_r() |!save_sigma() ){
        QString message="ERROR! Please entre a real!";
        QMessageBox::warning(this,"",message) ;
        return ;
    }
    ResultWindow *sim=new ResultWindow(this);
    sim->show();
}


void SimWindow::disable(bool calll)
{
    if(calll){
        calll=false;
        SB_nPut->setDisabled(true);
        SB_nCall->setEnabled(true);
    }
    else{
    calll=true;
    SB_nCall->setDisabled(true);
    SB_nPut->setEnabled(true);
    }
}

void SimWindow::change_position(bool loong)
{
    if(loong){
        loong=false;
    }
    else{
    loong=true;
    }
}

QString SimWindow::message()
{
    QString s = QString::fromStdString(DeltaNeutral(calll, loong, S0, K, T, r, sigma,n));
    return s;
}





