#include "wresteling_participant.h"
#include "ui_wresteling_participant.h"
#include "QString"
#include "QFile"
#include "QTextStream"
#include "QMessageBox"

wresteling_participant::wresteling_participant(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::wresteling_participant)
{
    ui->setupUi(this);
}

wresteling_participant::~wresteling_participant()
{
    delete ui;
}

 bool wresteling_participant::sign_in(QString user, QString pass, QString teamname, QString playername, QString nationalitycode, QString team_email)
 {
     wresteling_participant *bo=new wresteling_participant();
     bo->set(user,pass,teamname,playername,nationalitycode,team_email);
     QFile f("wresteling_file.txt");//if we dont have file we must make file
     f.open(QFile::WriteOnly | QFile::Append);
     f.close();

     QFile f1("wresteling_file.txt");//cheking for repeated user and teamname
     if(!f1.open(QIODevice::ReadOnly))
     {
         QMessageBox *err=new QMessageBox();
         err->setText("wresteling file not found!!");
         err->exec();
         delete err;
         this->close();
     }
     QTextStream file_box(&f1);
     wresteling_participant temp;
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


     QFile f2("wresteling_file.txt");
     if(!f1.open(QFile::WriteOnly | QFile::Append))
     {
         QMessageBox *err=new QMessageBox();
         err->setText("wresteling file not found!!");
         err->exec();
         delete err;
         this->close();
     }
     QTextStream file_box2(&f2);
     file_box2<<bo;
     f2.close();
     return true;
 }

 void wresteling_participant:: set(QString user, QString pass, QString teamname, QString playername, QString nationalitycode, QString team_email)
 {
     this->username=user;
     this->team_name=teamname;
     this->password=pass;
     this->playername=playername;
     this->nationality_code=nationalitycode;
     this->team_email=team_email;
 }


 wresteling_participant:: wresteling_participant(const wresteling_participant &boxi)
  {
     this->username=boxi.username;
     this->password=boxi.password;
     this->team_name=boxi.team_name;
     this->playername=boxi.playername;
     this->nationality_code=boxi.nationality_code;
     this->team_email=boxi.team_email;
  }

 wresteling_participant wresteling_participant:: login(QString user, QString pass)
 {
     wresteling_participant bo;
     bo.set( user,  pass,  "teamname",  "playername",  "nationalitycode",  "team_email");

     QFile f("wresteling_file.txt");//if we dont have file we must make file
     f.open(QFile::WriteOnly | QFile::Append);
     f.close();

     QFile f1("wresteling_file.txt");//cheking for repeated user and teamname
     if(!f1.open(QIODevice::ReadOnly))
     {
         QMessageBox *err=new QMessageBox();
         err->setText("wresteling file not found!!");
         err->exec();
         delete err;
         this->close();
     }
     QTextStream file_box(&f1);
     wresteling_participant temp;
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
     f1.close();
         QMessageBox login;
         login.setText("  .چنین حساب کاربری ای وجود ندارد  :)");
                 login.exec();
                 bo.username=nullptr;
                 return bo;
                 this->close();
 }

 void wresteling_participant::edit()
 {

 }

//virtual void show_competitor() = 0;//for see our competitor and theire results
 void wresteling_participant::observe_login_tournoments()
 {

 }
 void wresteling_participant::show_score_table()//we can see our competitor and they informations
 {

 }
 void wresteling_participant::show_our_tournament()//show how much time we have untill tournoment
{

}
 void wresteling_participant::shw_over_matches()
 {

 }

 QTextStream& operator << (QTextStream &out, wresteling_participant &tour)
 {
     out<<tour.username<<" "<<tour.password<<" "<<tour.team_name<<" "<<tour.playername<<" "<<tour.nationality_code<<" "<<tour.team_email<<" ";
     return out;
 }
 QTextStream& operator >> (QTextStream &input, wresteling_participant &tour)
 {
     input>>tour.username>>tour.password>>tour.team_name>>tour.playername>>tour.nationality_code>>tour.team_email;
     return input;
 }
