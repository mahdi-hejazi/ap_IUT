#include "footsall_participant.h"
#include "ui_footsall_participant.h"
#include "QString"
#include "QFile"
#include "QTextStream"
#include "QMessageBox"

footsall_participant::footsall_participant(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::footsall_participant)
{
    ui->setupUi(this);
}

footsall_participant::~footsall_participant()
{
    delete ui;
}

footsall_participant::footsall_participant (const footsall_participant &footi)
{
    this->username=footi.username;
    this->team_name=footi.team_name;
    this->password=footi.password;
    this->team_email=footi.team_email;
    for(int i=0;i<10;i++)
    {
        this->playernames[i]=footi.playernames[i];
    }
    for(int i=0;i<10;i++)
    {
        this->nationality_code[i]=footi.nationality_code[i];
    }
}

bool footsall_participant::sign_in(QString user, QString pass, QString teamname, QString playernames[10], QString nationalitycode[10], QString team_email)
{
    footsall_participant *bo=new footsall_participant();
    bo->set(user,pass,teamname,playernames,nationalitycode,team_email);
    QFile f("footsall_file.txt");//if we dont have file we must make file
    f.open(QFile::WriteOnly | QFile::Append);
    f.close();

    QFile f1("footsall_file.txt");//cheking for repeated user and teamname
    if(!f1.open(QIODevice::ReadOnly))
    {
        QMessageBox *err=new QMessageBox();
        err->setText("footsall file not found!!");
        err->exec();
        delete err;
        this->close();
    }

    QTextStream file_box(&f1);
    footsall_participant temp;
    QString l[10]{"l","l","l","l","l","l","l","l","l","l"};
    temp.set("lll","lll","lll",l,l,"lll");
    file_box>>temp;
    while(temp.team_email !=nullptr)
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


void footsall_participant:: set(QString user, QString pass, QString teamname, QString playernames[10], QString nationalitycode[10], QString team_email)
{
    this->username=user;
    this->team_name=teamname;
    this->password=pass;
    this->team_email=team_email;
    for(int i=0;i<10;i++)
    {
        this->playernames[i]=playernames[i];
    }
    for(int i=0;i<10;i++)
    {
        this->nationality_code[i]=nationalitycode[i];
    }
}


footsall_participant footsall_participant::login(QString user,QString pass)
{
    footsall_participant bo;
    QString l[10]{"l","l","l","l","l","l","l","l","l","l"};
    bo.set(user,pass,"teamname",l,l,"team_email");

    QFile f("footsall_file.txt");//if we dont have file we must make file
    f.open(QFile::WriteOnly | QFile::Append);
    f.close();

    QFile f1("footsall_file.txt");//cheking for repeated user and teamname
    if(!f1.open(QIODevice::ReadOnly))
    {
        QMessageBox *err=new QMessageBox();
        err->setText("footsall file not found!!");
        err->exec();
        delete err;
        this->close();
    }

    QTextStream file_box(&f1);
    footsall_participant temp;
    temp.set("lll","lll","lll",l,l,"lll");
    file_box>>temp;
    while(temp.team_email !=nullptr)
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
        file_box>>temp;
    }
    QMessageBox login;
    login.setText("  .چنین حساب کاربری ای وجود ندارد  :)");
            login.exec();
            bo.username=nullptr;
            return bo;
            this->close();

    f1.close();


}


void footsall_participant::edit()
{


}

//virtual void show_competitor() = 0;//for see our competitor and theire results
 void footsall_participant::observe_login_tournoments()
{

}

 void footsall_participant::show_score_table()//we can see our competitor and they informations
{

}
 void footsall_participant::show_our_tournament()//show how much time we have untill tournoment
{

}
 void footsall_participant::shw_over_matches()
{

}
 QTextStream& operator << (QTextStream &out, footsall_participant &tour)
{
    out<<tour.username<<" "<<tour.password<<" "<<tour.team_name<<" ";
    for(int i=0;i<10;i++)
    {
        out<<tour.playernames[i]<<" ";
    }

    for(int i=0;i<10;i++)
    {
        out<<tour.nationality_code[i]<<" ";
    }
    out<<tour.team_email<<" ";
    return out;
}
 QTextStream& operator >> (QTextStream &input, footsall_participant &tour)
{
     input>>tour.username>>tour.password>>tour.team_name;
     for(int i=0;i<10;i++)
     {
         input>>tour.playernames[i];
     }

     for(int i=0;i<10;i++)
     {
         input>>tour.nationality_code[i];
     }
     input<<tour.team_email;
     return input;
}
