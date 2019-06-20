#include "login.h"
#include "ui_login.h"
#include "QMessageBox"
#include "QEvent"
#include "QFile"
#include "QTextStream"
#include "organizer_footsal.h"
#include "organizer_wrestling.h"
#include "organizer_boxing.h"
#include "footsall_participant.h"
#include "wresteling_participant.h"
#include "boxing_participant.h"
#include "mainwindow.h"
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
                QMessageBox *s=new QMessageBox;
               // s->setText("خوش امدید");
                QPixmap bkgnd(":/new/background_image/image/wellcome/footsal2_wellcome.jpg");
                s->setIconPixmap(bkgnd);
                s->exec();
                delete s;
                organizer_footsal *fo=new organizer_footsal();
                fo->showFullScreen();
            }
            else
            {
                QMessageBox *s=new QMessageBox;
                s->setText("your username or password is wrong!");
                s->exec();
                delete s;
            }
        }
        else if(ui->coshti->isChecked()==true)
        {
            if(ui->lineEdit_3->text()==u2 && ui->lineEdit_2->text()==p2)
            {
                QMessageBox *s=new QMessageBox;
               // s->setText("خوش امدید");
                QPixmap bkgnd(":/new/background_image/image/wellcome/wellcome.jpg");
                s->setIconPixmap(bkgnd);
                s->exec();
                delete s;
                organizer_wrestling *ow = new organizer_wrestling();
                ow->showFullScreen();
                this->close();

            }
            else
            {
                QMessageBox *s=new QMessageBox;
                s->setText("your username or password is wrong!");
                s->exec();
                delete s;
            }
        }
        else if(ui->box->isChecked()==true)
        {
            if(ui->lineEdit_3->text()==u3 && ui->lineEdit_2->text()==p3)
            {
                QMessageBox *s=new QMessageBox;
               // s->setText("خوش امدید");
                QPixmap bkgnd(":/new/background_image/image/wellcome/box2_wellcome.jpg");
                s->setIconPixmap(bkgnd);
                s->exec();
                delete s;
                organizer_boxing *ob=new organizer_boxing();
                ob->showFullScreen();
                this->close();
            }
            else
            {
                QMessageBox *s=new QMessageBox;
                s->setText("<i>your username or password is wrong!</i>");
                s->exec();
                delete s;
            }
        }
        else
        {
            QMessageBox *s=new QMessageBox;
            s->setText("لطفا نوع ورزش خود را تعریف کنید.");
            s->exec();
            delete s;
        }
    }

    else if(ui->varzeshcar->isChecked())
    {
        bool vorod;//check login is success or not
        if(ui->footsal->isChecked())
        {
            footsall_participant *log=new footsall_participant();
            QString l[10]{"l","l","l","l","l","l","l","l","l","l"};
            footsall_participant log2;
            log2.set(ui->lineEdit_3->text(),ui->lineEdit_2->text(),"l",l,l,"l");
            vorod=log->login(log2);
            if(vorod)
            {
                this->close();
                log->showFullScreen();

            }


        }
        else if(ui->coshti->isChecked())
        {
            wresteling_participant *log=new wresteling_participant();
            wresteling_participant log2;
            log2.set(ui->lineEdit_3->text(),ui->lineEdit_2->text(),"l","l","l","l");
            vorod=log->login(log2);
            if(vorod)
            {
                this->close();
               log->showFullScreen();
            }

        }
        else if (ui->box->isChecked())
        {
            boxing_participant *log=new boxing_participant();
            boxing_participant log2;
            log2.set(ui->lineEdit_3->text(),ui->lineEdit_2->text(),"l","l","l","l");
            vorod=log->login(log2);
             if(vorod)
             {
                  this->close();
                 log->showFullScreen();
             }

        }
    }
}
