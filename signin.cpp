#include "signin.h"
#include "ui_signin.h"
#include "boxing_participant.h"
#include "wresteling_participant.h"
#include "QMessageBox"
#include "login.h"
#include "footsall_participant.h"
#include "mainwindow.h"
//camel shod

signin::signin(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::signin)
{
    ui->setupUi(this);
}


signin::~signin()
{
    delete ui;
}

void signin::on_sabtenam_clicked()
{
//    if(ui->box->isChecked())
//    {

//    }
}

void signin::on_sabtenam_3_clicked()//footsall
{
    QString user=ui->usename_3->text();
    QString pass=ui->pass_3->text();
    QString teamname=ui->team_name_3->text();
    QString playernames[10]{ ui->name1->text(),ui->name2->text(),ui->name3->text(),ui->name4->text(),
                           ui->name5->text(),ui->name6->text(),ui->name7->text(),ui->name8->text(),
                           ui->name9->text(),ui->name10->text() };

    QString nationalitycode[10]{ ui->codemeli1->text(),ui->codemeli2->text(),ui->codemeli3->text(),ui->codemeli4->text(),
                ui->codemeli5->text(),ui->codemeli6->text(),ui->codemeli7->text(),ui->codemeli8->text(),
                ui->codemeli9->text(),ui->codemeli10->text() };

    QString team_email=ui->email_3->text();

    if(user==nullptr || pass==nullptr || team_email==nullptr || teamname==nullptr ||
          playernames[0]==nullptr || playernames[1]==nullptr || playernames[2]==nullptr ||
          playernames[3]==nullptr || playernames[4]==nullptr || playernames[5]==nullptr || playernames[6]==nullptr ||
          playernames[7]==nullptr || playernames[8]==nullptr || playernames[9]==nullptr || nationalitycode[0]==nullptr ||
          nationalitycode[1]==nullptr || nationalitycode[2]==nullptr || nationalitycode[3]==nullptr ||
          nationalitycode[4]==nullptr || nationalitycode[5]==nullptr || nationalitycode[6]==nullptr ||
          nationalitycode[7]==nullptr || nationalitycode[8]==nullptr || nationalitycode[9]==nullptr )
    {
        if(user==nullptr)
         {
            QString errori="نام کاربری الزامی است";
            ui->usename_3->setPlaceholderText(errori);
            QPalette palette = ui->usename_3->palette();
            palette.setColor(ui->usename_3->foregroundRole(), Qt::red);
            ui->usename_3->setPalette(palette);
          }
        if(pass==nullptr)
         {
            QString errori="رمز عبور الزامی است";
            ui->pass_3->setPlaceholderText(errori);
            QPalette palette = ui->pass_3->palette();
            palette.setColor(ui->pass_3->foregroundRole(), Qt::red);
            ui->pass_3->setPalette(palette);
          }
        if(teamname==nullptr)
         {
            QString errori="نام تیم الزامی است";
            ui->team_name_3->setPlaceholderText(errori);
            QPalette palette = ui->team_name_3->palette();
            palette.setColor(ui->team_name_3->foregroundRole(), Qt::red);
            ui->team_name_3->setPalette(palette);
         }
        if(playernames[0]==nullptr)
         {
            QString errori="نام هر بازیکن الزامی است";
            ui->name1->setPlaceholderText(errori);
            QPalette palette = ui->name1->palette();
            palette.setColor(ui->name1->foregroundRole(), Qt::red);
            ui->name1->setPalette(palette);
         }
        if(playernames[1]==nullptr)
         {
            QString errori="نام هر بازیکن الزامی است";
            ui->name2->setPlaceholderText(errori);
            QPalette palette = ui->name2->palette();
            palette.setColor(ui->name2->foregroundRole(), Qt::red);
            ui->name2->setPalette(palette);
         }
        if(playernames[2]==nullptr)
         {
            QString errori="نام هر بازیکن الزامی است";
            ui->name3->setPlaceholderText(errori);
            QPalette palette = ui->name3->palette();
            palette.setColor(ui->name3->foregroundRole(), Qt::red);
            ui->name3->setPalette(palette);
         }
        if(playernames[3]==nullptr)
         {
            QString errori="نام هر بازیکن الزامی است";
            ui->name4->setPlaceholderText(errori);
            QPalette palette = ui->name4->palette();
            palette.setColor(ui->name4->foregroundRole(), Qt::red);
            ui->name4->setPalette(palette);
         }
        if(playernames[4]==nullptr)
         {
            QString errori="نام بازیکن الزامی است";
            ui->name5->setPlaceholderText(errori);
            QPalette palette = ui->name5->palette();
            palette.setColor(ui->name5->foregroundRole(), Qt::red);
            ui->name5->setPalette(palette);
         }
        if(playernames[5]==nullptr)
         {
            QString errori="نام هر بازیکن الزامی است";
            ui->name6->setPlaceholderText(errori);
            QPalette palette = ui->name6->palette();
            palette.setColor(ui->name6->foregroundRole(), Qt::red);
            ui->name6->setPalette(palette);
         }
        if(playernames[6]==nullptr)
         {
            QString errori="نام هر بازیکن الزامی است";
            ui->name7->setPlaceholderText(errori);
            QPalette palette = ui->name7->palette();
            palette.setColor(ui->name7->foregroundRole(), Qt::red);
            ui->name7->setPalette(palette);
         }
        if(playernames[7]==nullptr)
         {
            QString errori="نام هر بازیکن الزامی است";
            ui->name8->setPlaceholderText(errori);
            QPalette palette = ui->name8->palette();
            palette.setColor(ui->name8->foregroundRole(), Qt::red);
            ui->name8->setPalette(palette);
         }
        if(playernames[8]==nullptr)
         {
            QString errori="نام هر بازیکن الزامی است";
            ui->name9->setPlaceholderText(errori);
            QPalette palette = ui->name9->palette();
            palette.setColor(ui->name9->foregroundRole(), Qt::red);
            ui->name9->setPalette(palette);
         }
        if(playernames[9]==nullptr)
         {
            QString errori="نام هر بازیکن الزامی است";
            ui->name10->setPlaceholderText(errori);
            QPalette palette = ui->name10->palette();
            palette.setColor(ui->name10->foregroundRole(), Qt::red);
            ui->name10->setPalette(palette);
         }

        if(nationalitycode[0]==nullptr)
         {
            QString errori="کد ملی هر بازیکن الزامی است";
            ui->codemeli1->setPlaceholderText(errori);
            QPalette palette = ui->codemeli1->palette();
            palette.setColor(ui->codemeli1->foregroundRole(), Qt::red);
            ui->codemeli1->setPalette(palette);
         }
        if(nationalitycode[1]==nullptr)
         {
            QString errori="کد ملی هر بازیکن الزامی است";
            ui->codemeli2->setPlaceholderText(errori);
            QPalette palette = ui->codemeli2->palette();
            palette.setColor(ui->codemeli2->foregroundRole(), Qt::red);
            ui->codemeli2->setPalette(palette);
         }
        if(nationalitycode[2]==nullptr)
         {
            QString errori="کد ملی هر بازیکن الزامی است";
            ui->codemeli3->setPlaceholderText(errori);
            QPalette palette = ui->codemeli3->palette();
            palette.setColor(ui->codemeli3->foregroundRole(), Qt::red);
            ui->codemeli3->setPalette(palette);
         }
        if(nationalitycode[3]==nullptr)
         {
            QString errori="کد ملی هر بازیکن الزامی است";
            ui->codemeli4->setPlaceholderText(errori);
            QPalette palette = ui->codemeli4->palette();
            palette.setColor(ui->codemeli4->foregroundRole(), Qt::red);
            ui->codemeli4->setPalette(palette);
         }
        if(nationalitycode[4]==nullptr)
         {
            QString errori="کد ملی هر بازیکن الزامی است";
            ui->codemeli5->setPlaceholderText(errori);
            QPalette palette = ui->codemeli5->palette();
            palette.setColor(ui->codemeli5->foregroundRole(), Qt::red);
            ui->codemeli5->setPalette(palette);
         }
        if(nationalitycode[5]==nullptr)
         {
            QString errori="کد ملی هر بازیکن الزامی است";
            ui->codemeli6->setPlaceholderText(errori);
            QPalette palette = ui->codemeli6->palette();
            palette.setColor(ui->codemeli6->foregroundRole(), Qt::red);
            ui->codemeli6->setPalette(palette);
         }
        if(nationalitycode[6]==nullptr)
         {
            QString errori="کد ملی هر بازیکن الزامی است";
            ui->codemeli7->setPlaceholderText(errori);
            QPalette palette = ui->codemeli7->palette();
            palette.setColor(ui->codemeli7->foregroundRole(), Qt::red);
            ui->codemeli7->setPalette(palette);
         }
        if(nationalitycode[7]==nullptr)
         {
            QString errori="کد ملی هر بازیکن الزامی است";
            ui->codemeli8->setPlaceholderText(errori);
            QPalette palette = ui->codemeli8->palette();
            palette.setColor(ui->codemeli8->foregroundRole(), Qt::red);
            ui->codemeli8->setPalette(palette);
         }
        if(nationalitycode[8]==nullptr)
         {
            QString errori="کد ملی هر بازیکن الزامی است";
            ui->codemeli9->setPlaceholderText(errori);
            QPalette palette = ui->codemeli9->palette();
            palette.setColor(ui->codemeli9->foregroundRole(), Qt::red);
            ui->codemeli9->setPalette(palette);
         }
        if(nationalitycode[9]==nullptr)
         {
            QString errori="کد ملی هر بازیکن الزامی است";
            ui->codemeli10->setPlaceholderText(errori);
            QPalette palette = ui->codemeli10->palette();
            palette.setColor(ui->codemeli10->foregroundRole(), Qt::red);
            ui->codemeli10->setPalette(palette);
         }
        if(team_email==nullptr)
         {
            QString errori="ایمیل تیم الزامی است";
            ui->email_3->setPlaceholderText(errori);
            QPalette palette = ui->email_3->palette();
            palette.setColor(ui->email_3->foregroundRole(), Qt::red);
            ui->email_3->setPalette(palette);
         }

    }
    else
    {

        footsall_participant sig;
        sig.sign_in(user,pass,teamname,playernames,nationalitycode,team_email);
        this->close();
        MainWindow mai;
        mai.show();
    }
}

void signin::on_sabtenam_2_clicked() //wresteling
{
    QString user=ui->usename_2->text();
    QString pass=ui->pass_2->text();
    QString teamname=ui->team_name_2->text();
    QString playername=ui->name->text();
    QString nationalitycode=ui->code_meli->text();
    QString team_email=ui->email_2->text();
    if(user==nullptr || pass==nullptr || team_email==nullptr || teamname==nullptr ||
         playername==nullptr || nationalitycode==nullptr)
    {
        if(user==nullptr)
         {
            QString errori="نام کاربری الزامی است";
            ui->usename_2->setPlaceholderText(errori);
            QPalette palette = ui->usename_2->palette();
            palette.setColor(ui->usename_2->foregroundRole(), Qt::red);
            ui->usename_2->setPalette(palette);
         }

        if(pass==nullptr)
        {
            QString errori="رمز عبور الزامی است";
            ui->pass_2->setPlaceholderText(errori);
            QPalette palette = ui->pass_2->palette();
            palette.setColor(ui->pass_2->foregroundRole(), Qt::red);
            ui->pass_2->setPalette(palette);
        }

       if(team_email==nullptr)
        {
            QString errori="ایمیل الزامی است";
            ui->email_2->setPlaceholderText(errori);
            QPalette palette = ui->email_2->palette();
            palette.setColor(ui->email_2->foregroundRole(), Qt::red);
            ui->email_2->setPalette(palette);
        }

        if(teamname==nullptr)
        {
            QString errori="نام تیم الزامی است";
            ui->team_name_2->setPlaceholderText(errori);
            QPalette palette = ui->team_name_2->palette();
            palette.setColor(ui->team_name_2->foregroundRole(), Qt::red);
            ui->team_name_2->setPalette(palette);
        }

    if(playername==nullptr)
        {
            QString errori="نام شخص الزامی است";
            ui->name->setPlaceholderText(errori);
            QPalette palette = ui->name->palette();
             palette.setColor(ui->name->foregroundRole(), Qt::red);
            ui->name->setPalette(palette);
        }

     if(nationalitycode==nullptr)
        {
            QString errori="کد ملی الزامی است";
            ui->code_meli->setPlaceholderText(errori);
            QPalette palette = ui->code_meli->palette();
             palette.setColor(ui->code_meli->foregroundRole(), Qt::red);
             ui->code_meli->setPalette(palette);
        }

    }
    else
    {
        wresteling_participant sig;
        sig.sign_in(user ,pass, teamname ,playername, nationalitycode, team_email);       
       this->close();



    }
}

void signin::on_sabtenam_4_clicked() //boxing
{
    boxing_participant bo;
    QString user=ui->usename->text();
    QString pass=ui->pass->text();
    QString teamname=ui->team_name->text();
    QString playername=ui->name_2->text();
    QString nationalitycode=ui->code_meli_2->text();
    QString team_email=ui->email->text();

    if(user==nullptr || pass==nullptr || team_email==nullptr || teamname==nullptr ||
         playername==nullptr || nationalitycode==nullptr)
    {
        if(user==nullptr)
         {
            QString errori="نام کاربری الزامی است";
            ui->usename->setPlaceholderText(errori);
            QPalette palette = ui->usename->palette();
            palette.setColor(ui->usename->foregroundRole(), Qt::red);
            ui->usename->setPalette(palette);
         }

        if(pass==nullptr)
        {
            QString errori="رمز عبور الزامی است";
            ui->pass->setPlaceholderText(errori);
            QPalette palette = ui->pass->palette();
            palette.setColor(ui->pass->foregroundRole(), Qt::red);
            ui->pass->setPalette(palette);
        }

       if(team_email==nullptr)
        {
            QString errori="ایمیل الزامی است";
            ui->email->setPlaceholderText(errori);
            QPalette palette = ui->email->palette();
            palette.setColor(ui->email->foregroundRole(), Qt::red);
            ui->email->setPalette(palette);
        }

        if(teamname==nullptr)
        {
            QString errori="نام تیم الزامی است";
            ui->team_name->setPlaceholderText(errori);
            QPalette palette = ui->team_name->palette();
            palette.setColor(ui->team_name->foregroundRole(), Qt::red);
            ui->team_name->setPalette(palette);
        }

    if(playername==nullptr)
        {
            QString errori="نام شخص الزامی است";
            ui->name_2->setPlaceholderText(errori);
            QPalette palette = ui->name_2->palette();
             palette.setColor(ui->name_2->foregroundRole(), Qt::red);
            ui->name_2->setPalette(palette);
        }

     if(nationalitycode==nullptr)
        {
            QString errori="کد ملی الزامی است";
            ui->code_meli_2->setPlaceholderText(errori);
            QPalette palette = ui->code_meli_2->palette();
             palette.setColor(ui->code_meli_2->foregroundRole(), Qt::red);
             ui->code_meli_2->setPalette(palette);

        }

    }
    else
    {

        boxing_participant sig;
        sig.sign_in(user ,pass, teamname ,playername, nationalitycode, team_email);
        this->close();
        MainWindow ssd;
        ssd.show();

    }

}
