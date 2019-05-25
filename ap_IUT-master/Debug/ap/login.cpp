#include "login.h"
#include "ui_login.h"
#include "QMessageBox"
#include "QEvent"
#include "QFile"
#include "QTextStream"
#include "organizer_footsal.h"
login::login(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::login)
{
    ui->setupUi(this);
}

login::~login()
{
    delete ui;
}


void login::on_ok_clicked()
{

    bool modirlog;
    modirlog=ui->modir->isChecked();

    if(modirlog)
    {
        QString p1,p2,p3,u1,u2,u3;
        QFile f1("organizer.txt");
        if(!f1.open(QIODevice::ReadOnly))
        {
            QMessageBox error;
            error.setText("file baz nashod");
            error.exec();
        }
        QTextStream file1(&f1);
        file1>>u1>>p1;
        file1>>u2>>p2;
        file1>>u3>>p3;

        if(ui->footsal->isChecked())
        {
            QMessageBox d,d1;
            if(ui->lineEdit_3->text()==u1 && ui->lineEdit_2->text()==p1)
            {
                this->close();
                QMessageBox s;
                s.setText("خوش امدید");
                s.exec();
                organizer_footsal *fo=new organizer_footsal();
                fo->show();
            }
        }
    }
}
