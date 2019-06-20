#include "footsall_participant.h"
#include "ui_footsall_participant.h"
#include "QString"
#include "QFile"
#include "QTextStream"
#include "QMessageBox"
#include "file.h"
#include "QDate"
#include "QTime"
#include "QTextStream"
#include "tournoment.h"
#include "QTableWidgetItem"
footsall_participant::footsall_participant(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::footsall_participant)
{
    ui->setupUi(this);


    QFile f1("footsal_tournoment.txt");//cheking for repeated user and teamname
    if(!f1.open(QIODevice::ReadOnly))
    {
        QMessageBox *err=new QMessageBox();
        err->setText("footsal_tournoment file not found in wrestling_organizer!!");
        err->exec();
        delete err;
    }

    QTextStream footsal_tour(&f1);
    tournoment footsal;
    footsal_tour>>footsal;
//tournoment table
    for(int i=0;footsal.tournoment_name!=nullptr;this->ui->tournoments_info->insertRow( this->ui->tournoments_info->rowCount() ))
    {
//        if(footsal.start_date > QDate::currentDate())
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

footsall_participant::~footsall_participant()
{
    delete ui;
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

    while(temp.username !=nullptr) //tekrari naboodan
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

    QFile f2("footsall_file.txt");
    if(!f2.open(QFile::WriteOnly | QFile::Append))
    {
        QMessageBox *err=new QMessageBox();
        err->setText("footsall_file file not found!!");
        err->exec();
        delete err;
        this->close();
    }
    QTextStream file_box2(&f2);
    file_box2<<*bo;
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


bool footsall_participant::login(footsall_participant &log)
{

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
    file_box>>temp;

    while(temp.username !=nullptr)
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
                       for(int i=10;i<10;i++)
                       {
                           this->nationality_code[i]=temp.nationality_code[i];
                           this->playernames[i]=temp.playernames[i];
                       }
                        return true;
                        //this->close();
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
    QMessageBox login;
    login.setText("  .چنین حساب کاربری ای وجود ندارد  :)");
            login.exec();
            log.username=nullptr;
            f1.close();
            return false;
           // this->close();

}


 void footsall_participant::edit(footsall_participant& before_edit,footsall_participant& after_edit)
{

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

     file_box>>temp;

     QFile f2("footsall_file2.txt");//cheking for repeated user and teamname
     f1.open(QFile::WriteOnly);
     QTextStream file_box2(&f2);
     file_box>>temp;
     while(temp.username !=nullptr) //tekrari naboodan
     {

         if(temp.username==before_edit.username)
         {
             if(temp.password==before_edit.password)
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
     remove("footsall_file.txt");
     rename("footsall_file2.txt","boxing_file.txt");
     QMessageBox edit;
     edit.setText(" .تغییرات صورت گرفت");
     edit.exec();
     this->close();
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
     out<<attach_qstring( tour.username)<<" "<<attach_qstring( tour.password)<<" "<<attach_qstring( tour.team_name)<<" ";


    out<<tour.username<<" "<<tour.password<<" "<<tour.team_name<<" ";
    for(int i=0;i<10;i++)
    {
        out<<attach_qstring( tour.playernames[i])<<" ";
    }

    for(int i=0;i<10;i++)
    {
        out<<attach_qstring( tour.nationality_code[i])<<" ";
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
     input>>tour.team_email;
     tour.username=separate_qstring(tour.username);
     tour.password=separate_qstring(tour.password);
     tour.team_name=separate_qstring(tour.team_name);
     for(int i=0;i<10;i++)
     {
         tour.playernames[i]=separate_qstring(tour.playernames[i]);
         tour.nationality_code[i]=separate_qstring(tour.nationality_code[i]);
     }

     tour.team_email=separate_qstring(tour.team_email);
     return input;
}

 void footsall_participant:: operator = (footsall_participant &as)
{
    this->username=as.username;
     this->team_email=as.team_email;
     this->password=as.password;
     this->team_name=as.team_name;

     for(int i=0; i<10;i++)
     {
         this->playernames[i]=as.playernames[i];
     }

     for(int i=0; i<10;i++)
     {
         this->nationality_code[i]=as.nationality_code[i];
     }
}



void footsall_participant::on_tournoments_info_cellClicked(int row, int column)
{
    QMessageBox *qb=new QMessageBox();
    qb->setText("آیا می خواهید در این تورنومنت شرکت کنید؟");
    qb->setStandardButtons(QMessageBox::Yes | QMessageBox::No);
    int natije=qb->exec();

    if(natije==QMessageBox::Yes)
    {
             QFile f1("footsal_tournoment.txt");//cheking for repeated user and teamname
        if(!f1.open(QIODevice::ReadOnly))
        {
            QMessageBox *err=new QMessageBox();
            err->setText("footsal tournoment file not found!!");
            err->exec();
            delete err;
            this->close();
        }
        QTextStream file_box(&f1);

        QFile f2("footsal_tournoment2.txt");// file for edit and rename
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
        remove("footsal_tournoment.txt");
        rename("footsal_tournoment2.txt","footsal_tournoment.txt");
        QMessageBox edit;
        edit.setText(" شما در تورنومنت ثبت شدید");
        edit.exec();

    }
}

void footsall_participant::on_refresh_clicked()
{
    footsall_participant *fp=new footsall_participant();
    *fp=*this;
    fp->showFullScreen();
    delete this;
}
