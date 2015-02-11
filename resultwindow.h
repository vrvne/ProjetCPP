#ifndef RESULTWINDOW_H
#define RESULTWINDOW_H

#include <QApplication>
#include <QWidget>
#include <QMainWindow>
#include <QPushButton>
#include <QGridLayout>
#include <QLineEdit>
#include <QMessageBox>
#include <QString>
#include <QTextStream>
#include <QLabel>

// on a besoin de ces deux classes
class MyWindow ;
class SimWindow;

class ResultWindow: public QWidget
{ Q_OBJECT
public:

    // ResultWindow peut prendre deux types d'argument
    ResultWindow(MyWindow* window);
    ResultWindow(SimWindow* window);
    ~ResultWindow();
private:
    QPushButton *PB_Ok2;
    QLabel *LB_res;
    double n;
};





#endif // RESULTWINDOW_H
