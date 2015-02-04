#ifndef GUIDEWINDOW_H
#define GUIDEWINDOW_H

#include <QWidget>
#include "mywindow.h"
#include "simwindow.h"
#include <QPixmap>
#include <QLabel>
#include <QGridLayout>
#include <QDir>

class GuideWindow : public QWidget
{
    Q_OBJECT
public:
    explicit GuideWindow();
    ~GuideWindow();


public slots:

    void on_PB_res_clicked();
    void on_PB_sim_clicked();

private:
    QLabel *label_png;
    QLabel *label_welcome;
    QPushButton *PB_res;
    QPushButton *PB_sim;


};

#endif // GUIDEWINDOW_H
