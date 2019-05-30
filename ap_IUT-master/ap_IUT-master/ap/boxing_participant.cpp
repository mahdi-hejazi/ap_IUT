#include "boxing_participant.h"
#include "ui_boxing_participant.h"
#include "QString"
#include "QFile"
#include "QTextStream"
#include "QMessageBox"

boxing_participant::boxing_participant(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::boxing_participant)
{
    ui->setupUi(this);
}



boxing_participant::~boxing_participant()
{
    delete ui;
}


bool boxing_participant:: sign_in(QString user, QString pass, QString teamname, QString playername, QString nationalitycode, QString team_email)
{
    boxing_participant *bo=new boxing_participant();
    bo->set(user,pass,teamname,playername,nationalitycode,team_email);
    QFile f("boxing_file.txt");//if we dont have file we must make file
    f.open(QFile::WriteOnly | QFile::Append);
    f.close();

    QFile f1("boxing_file.txt");//cheking for repeated user and teamname
    if(!f1.open(QIODevice::ReadOnly))
    {
        QMessageBox *err=new QMessageBox();
        err->setText("boxing file not found!!");
        err->exec();
        delete err;
        this->close();
    }
    QTextStream file_box(&f1);
    boxing_participant temp;
    temp.set("lll","lll","lll","lll","lll","lll");
    file_box>>temp;
    while(temp.playername!=nullptr)
    {
        if(temp.username==bo->username)
        {
            QMessageBox *err=new QMessageBox();
            err->setText("نام کاربری وارد شده تکراری است");
            err->exec();
            delete err;
            return false;
        }
        if(temp.team_name==bo->team_name)
        {
            QMessageBox *err=new QMessageBox();
            err->setText("نام تیم وارد شده تکراری است");
            err->exec();
            delete err;
            return false;
        }
        file_box>>temp;
    }
    f1.close();


    QFile f2("boxing_file.txt");
    if(!f1.open(QFile::WriteOnly | QFile::Append))
    {
        QMessageBox *err=new QMessageBox();
        err->setText("boxing file not found!!");
        err->exec();
        delete err;
        this->close();
    }
    QTextStream file_box2(&f2);
    file_box2<<bo;
    f2.close();
    return true;
}


void boxing_participant:: set(QString user, QString pass, QString teamname, QString playername, QString nationalitycode, QString team_email)
{
    this->username=user;
    this->team_name=teamname;
    this->password=pass;
    this->playername=playername;
    this->nationality_code=nationalitycode;
    this->team_email=team_email;
}

boxing_participant:: boxing_participant(const boxing_participant &boxi)
 {
    this->username=boxi.username;
    this->password=boxi.password;
    this->team_name=boxi.team_name;
    this->playername=boxi.playername;
    this->nationality_code=boxi.nationality_code;
    this->team_email=boxi.team_email;
 }

boxing_participant boxing_participant:: login(QString user, QString pass)
{
    boxing_participant bo;
    bo.set( user,  pass,  "teamname",  "playername",  "nationalitycode",  "team_email");

    QFile f("boxing_file.txt");//if we dont have file we must make file
    f.open(QFile::WriteOnly | QFile::Append);
    f.close();

    QFile f1("boxing_file.txt");//cheking for repeated user and teamname
    if(!f1.open(QIODevice::ReadOnly))
    {
        QMessageBox *err=new QMessageBox();
        err->setText("boxing file not found!!");
        err->exec();
        delete err;
        this->close();
    }
    QTextStream file_box(&f1);
    boxing_participant temp;
    temp.set("lll","lll","lll","lll","lll","lll");
    file_box>>temp;
    while(temp.playername!=nullptr)
    {
        if(temp.username==bo.username)
        {
            if(temp.password==bo.password)
            {
                QMessageBox login;
                login.setText(".خوش آمدید  :)");
                        login.exec();
                        return temp;
                        this->close();
            }
            else
            {
                QMessageBox login;
                login.setText(" . رمز عبور اشتباه است  :)");
                        login.exec();
                        bo.username=nullptr;
                        return bo;
                        this->close();
            }
        }
       }
        QMessageBox login;
        login.setText("  .چنین حساب کاربری ای وجود ندارد  :)");
                login.exec();
                bo.username=nullptr;
                return bo;
                this->close();

}
void boxing_participant:: edit()
{

}


//virtual void show_competitor() ;//for see our competitor and theire results
void boxing_participant::  observe_login_tournoments()
{

}

void boxing_participant::  show_score_table()//we can see our competitor and they informations
{

}

void boxing_participant::  show_our_tournament()//show how much time we have untill tournoment
{

}

void boxing_participant::  shw_over_matches()
{

}


 QTextStream& operator << (QTextStream &out, boxing_participant &tour)
 {
    out<<tour.username<<" "<<tour.password<<" "<<tour.team_name<<" "<<tour.playername<<" "<<tour.nationality_code<<" "<<tour.team_email<<" ";
    return out;
 }

 QTextStream& operator >> (QTextStream &input, boxing_participant &tour)
 {
     input>>tour.username>>tour.password>>tour.team_name>>tour.playername>>tour.nationality_code>>tour.team_email;
     return input;
 }
