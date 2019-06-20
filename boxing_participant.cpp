#include "boxing_participant.h"
#include "ui_boxing_participant.h"
#include "QString"
#include "QFile"
#include "QMessageBox"
#include "file.h"
#include "QDate"
#include "QTime"
#include "QTextStream"
#include "tournoment.h"
boxing_participant::boxing_participant(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::boxing_participant)
{
    ui->setupUi(this);

    QFile f1("boxing_tournoment.txt");//cheking for repeated user and teamname
    if(!f1.open(QIODevice::ReadOnly))
    {
        QMessageBox *err=new QMessageBox();
        err->setText("boxing_tournoment file not found in wrestling_organizer!!");
        err->exec();
        delete err;
    }

    QTextStream footsal_tour(&f1);
    tournoment footsal;
    footsal_tour>>footsal;
//tournoment table
    for(int i=0;footsal.tournoment_name!=nullptr;this->ui->tournoments_info->insertRow( this->ui->tournoments_info->rowCount() ))
    {
//       if(footsal.start_date > QDate::currentDate() )
//        {
            QTableWidgetItem *item = new QTableWidgetItem(footsal.tournoment_name,1);
            item->setFlags(item->flags() &  ~Qt::ItemIsEditable);//for set this item uneditable
            this->ui->tournoments_info->setItem(i,0,item);
            item = new QTableWidgetItem(footsal.start_date.toString("yyyy/MM/dd"),1);
            item->setFlags(item->flags() &  ~Qt::ItemIsEditable);
            this->ui->tournoments_info->setItem(i,1,item);
            item = new QTableWidgetItem(footsal.start_time.toString("hh:mm"),1);
            item->setFlags(item->flags() &  ~Qt::ItemIsEditable);
            this->ui->tournoments_info->setItem(i,2,item);
            item = new QTableWidgetItem(QString::number(footsal.teame_number),1);
            item->setFlags(item->flags() &  ~Qt::ItemIsEditable);
            this->ui->tournoments_info->setItem(i,3,item);
            QString qs1;
            for(int j=0;j<footsal.teame_number;j++)
            {
               qs1+=footsal.team_names[j];
               qs1+=" _ ";
            }
            item = new QTableWidgetItem("our teams",1);
            item->setToolTip(qs1);
            this->ui->tournoments_info->setItem(i,4,item);
            item->setFlags(item->flags() &  ~Qt::ItemIsEditable);
            item = new QTableWidgetItem("about",1);
            item->setToolTip(footsal.about);
            this->ui->tournoments_info->setItem(i,5,item);
            item->setFlags(item->flags() &  ~Qt::ItemIsEditable);
            i++;
            footsal_tour>>footsal;
      // }
    }
    this->ui->tournoments_info->removeRow(this->ui->tournoments_info->rowCount()-1);

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
    if(!f2.open(QFile::WriteOnly | QFile::Append))
    {
        QMessageBox *err=new QMessageBox();
        err->setText("boxing file not found!!");
        err->exec();
        delete err;
        this->close();
    }
    QTextStream file_box2(&f2);
    file_box2<<*bo;
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




bool boxing_participant:: login(boxing_participant&log)
{

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
        if(temp.username==log.username)
        {
            if(temp.password==log.password)
            {
                QMessageBox login;
                login.setText(".خوش آمدید  :)");
                        login.exec();
                        this->username=temp.username;
                        this->password=temp.password;
                        this->team_email=temp.team_email;
                        this->team_name=temp.team_name;
                        this->nationality_code=temp.nationality_code;
                        this->playername=temp.playername;
                        return true;             
            }
            else
            {
                QMessageBox login;
                login.setText(" . رمز عبور اشتباه است  :)");
                        login.exec();
                        log.username=nullptr;
                        return false;
                        //this->close();
            }
        }
         file_box>>temp;
       }
        QMessageBox *notlogin=new QMessageBox();
        notlogin->setText("  .چنین حساب کاربری ای وجود ندارد  :)");
        notlogin->exec();
        delete notlogin;
        log.username=nullptr;
        return false;
        //this->close();

}


void boxing_participant:: edit(boxing_participant &befor_edit,boxing_participant &after_edit) //after log in send ubject for edit
{


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

    QFile f2("boxing_file2.txt");// file for edit and rename
    f2.open(QFile::WriteOnly | QFile::Append);
    QTextStream file_box2(&f2);

    boxing_participant temp;
    temp.set("lll","lll","lll","lll","lll","lll");
    file_box>>temp;
    while(temp.playername!=nullptr)
    {
        if(temp.username==befor_edit.username)
        {
            if(temp.password==befor_edit.password)
            {
                file_box2<<after_edit;

            }
            else
            {
               file_box2<<temp;
            }
        }

        else
        {
            file_box2<<temp;
        }

        file_box>>temp;
    }
    f1.close();
    f2.close();
    remove("boxing_file.txt");
    rename("boxing_file2.txt","boxing_file.txt");
    QMessageBox edit;
    edit.setText(" .تغییرات صورت گرفت");
    edit.exec();
    this->close();

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
    out<<attach_qstring( tour.username)<<" "<<attach_qstring( tour.password)<<" "<<attach_qstring( tour.team_name)<<" "<<attach_qstring( tour.playername)<<" "<<attach_qstring( tour.nationality_code)<<" "<<attach_qstring( tour.team_email)<<" ";
    return out;
 }

 QTextStream& operator >> (QTextStream &input, boxing_participant &tour)
 {
     input>> tour.username>>tour.password>>tour.team_name>>tour.playername>>tour.nationality_code>>tour.team_email;
     tour.username=separate_qstring(tour.username);
     tour.password=separate_qstring(tour.password);
     tour.team_name=separate_qstring(tour.team_name);
     tour.playername=separate_qstring(tour.playername);
     tour.nationality_code=separate_qstring(tour.nationality_code);
     tour.team_email=separate_qstring(tour.team_email);
     return input;
 }

 void boxing_participant::operator=(boxing_participant &asli)
 {
     this->username=asli.username;
     this->team_name=asli.team_name;
     this->password=asli.password;
     this->playername=asli.playername;
     this->nationality_code=asli.nationality_code;
     this->team_email=asli.team_email;
 }

void boxing_participant::on_tournoments_info_cellClicked(int row, int column)
{
    QMessageBox *qb=new QMessageBox();
    qb->setText("آیا می خواهید در این تورنومنت شرکت کنید؟");
    qb->setStandardButtons(QMessageBox::Yes | QMessageBox::No);
    int natije=qb->exec();

    if(natije==QMessageBox::Yes)
    {
        QFile f1("boxing_tournoment.txt");//cheking for repeated user and teamname
        if(!f1.open(QIODevice::ReadOnly))
        {
            QMessageBox *err=new QMessageBox();
            err->setText("boxing tournoment file not found!!");
            err->exec();
            delete err;
            this->close();
        }
        QTextStream file_box(&f1);

        QFile f2("boxing_tournoment2.txt");// file for edit and rename
        f2.open(QFile::WriteOnly | QFile::Append);
        QTextStream file_box2(&f2);
        tournoment temp;


        file_box>>temp;
        while(temp.tournoment_name!=nullptr)
        {


            if(temp.tournoment_name==ui->tournoments_info->item(row,0)->text())///////////////////'
            {
                temp.add_team_names(this->team_name);
                file_box2<<temp;
            }

            else
            {
                file_box2<<temp;
            }

            file_box>>temp;
        }
        f1.close();
        f2.close();
        remove("boxing_tournoment.txt");
        rename("boxing_tournoment2.txt","wrestling_tournoment.txt");
        QMessageBox edit;
        edit.setText(" شما در تورنومنت ثبت شدید");
        edit.exec();

    }
}

void boxing_participant::on_refresh_clicked()
{
    boxing_participant *bp=new boxing_participant();
    *bp=*this;
    bp->showFullScreen();
    delete this;
}
