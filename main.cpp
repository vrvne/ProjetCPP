
#include "guidewindow.h"
#include <QApplication>
#include "mywindow.h"
#include "simwindow.h"
#include <QMessageBox>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    // L'affichage de la fenêtre GuideWindow

    GuideWindow Window1;
    Window1.show();

    return a.exec();
}
