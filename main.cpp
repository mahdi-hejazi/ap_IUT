#include "mainwindow.h"
#include <QApplication>
#include "QMessageBox"
#include "tournoment_info.h"
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
//    MainWindow w;
//    w.showFullScreen();

    tournoment_info f;
    f.set("iranian",3,"mahdi");
    f.setupview();
    f.show();
    return a.exec();
}
