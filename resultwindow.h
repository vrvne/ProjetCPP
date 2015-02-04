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



class ResultWindow: public QWidget
{ Q_OBJECT
public:
    ResultWindow();
    ~ResultWindow();
private:
    QPushButton *PB_Ok2;

    double n;
public slots:
    void result();
};



















#endif // RESULTWINDOW_H
