#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "QFile"
#include "QTextStream"
#include "login.h"
#include "QString"
#include "signin.h"
//#include "wresteling_participan.h"
#include "QDate"
#include "QTime"
#include "QMessageBox"
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    QFile f("organizer.txt");
    f.open(QFile::WriteOnly);
    QTextStream ss(&f);
    QString s="hossein";
    QString s2="salimi";
    QString s3="mahdi";
    QString s4="hejazi";
    QString s5="sina";
    QString s6="fattahi";
    ss<<s<<" "<<s2<<" "<<s3<<" "<<s4<<" "<<s5<<" "<<s6<<" ";



}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_login_clicked()
{

    login *log=new login();
    log->showFullScreen();
    this->close();
}

void MainWindow::on_signin_clicked()
{
    signin *sig=new signin();
    sig->showFullScreen();

}
