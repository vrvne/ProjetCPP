#ifndef MYWINDOW_H
#define MYWINDOW_H

#include <QApplication>
#include <QWidget>
#include <QMainWindow>
#include <QPushButton>
#include <QGridLayout>
#include <QLineEdit>
#include <QMessageBox>
#include <QString>
#include <QTextStream>
#include <QSpinBox>
#include <QLabel>
#include <QRadioButton>
#include <QGroupBox>

class MyWindow: public QWidget // hérite de QWighet
{   Q_OBJECT
public:
    MyWindow();
    ~MyWindow();
    bool save_K();
    bool save_S0();
    bool save_r();
    bool save_sigma();
    bool save_T();
    bool save_n();
    QString message();

public slots:
    void open_result();
    void disable();
    void change_position();

private:
    QPushButton *PB_res;
    QPushButton *PB_quit;
    QLineEdit *LE_S0;
    QLineEdit *LE_K;
    QLineEdit *LE_T;
    QSpinBox *SB_nCall;
    QSpinBox *SB_nPut;
    QLineEdit *LE_r;
    QLineEdit *LE_sigma;
    QRadioButton *RB_long;
    QRadioButton *RB_short;
    QRadioButton *RB_call;
    QRadioButton *RB_put;
    QLabel *Label_S0;
    QLabel *Label_K;
    QLabel *Label_T;
    QLabel *Label_nCall;
    QLabel *Label_nPut;
    QLabel *Label_r;
    QLabel *Label_sigma;
    QGridLayout *layout ;
    QGroupBox *groupbox;
    QHBoxLayout *hbox;
    QGroupBox *groupbox2;
    QHBoxLayout *hbox2;

    double S0;
    double K;
    double r;
    double sigma;
    double T;
    double n;
    bool calll;
    bool loong;

};





#endif // MyWindow

