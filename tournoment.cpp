#include "tournoment.h"
#include "ui_tournoment.h"
#include "QDate"
#include "QString"
#include "QFile"
#include "QTextStream"
#include "QMessageBox"
#include "file.h"

tournoment::tournoment(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::tournoment)
{
    ui->setupUi(this);
    this->about="nullptr";
    this->start_date=QDate::currentDate();
    this->start_time=QTime::currentTime();
    this->tournoment_name="nullptr";
    this->teame_number=0;
    this->team_names.clear();
    this->tournoment_id="000";
    //this->team_names=nullptr;
}

tournoment::~tournoment()
{
    delete ui;
    this->team_names.clear();
}
tournoment::tournoment(const tournoment &tour)
{
    this->tournoment_name=tour.tournoment_name;
    this->teame_number=tour.teame_number;
    this->start_date=tour.start_date;
    this->start_time=tour.start_time;
    this->about=tour.about;
    this->team_names=tour.team_names;
//    this->team_names=new QString(tour.teame_number);
//    for(int i=0;i<tour.teame_number;i++)
//    {
//        tour.team_names[i]=tour.team_names[i];
//    }
}
bool tournoment::add_team_names(QString new_team)
{
//    QString *temp=new QString(this->teame_number+1);
//    for(int i=0;i<this->teame_number;i++)
//    {
//        temp[i]=this->team_names[i];

//    }

//    delete this->team_names;

//    this->team_names=temp;

//    QString *qs=new QString();
//    *qs=new_team;
//    this->team_names[this->teame_number]=*qs;
    this->team_names.append(new_team);
    this->teame_number++;
    return true;
}
void tournoment:: operator =(tournoment tour)
{
    this->tournoment_name=tour.tournoment_name;
    this->teame_number=tour.teame_number;
    this->start_date=tour.start_date;
    this->start_time=tour.start_time;
    this->about=tour.about;
   // this->team_names=new QString(tour.teame_number);
    this->tournoment_name=tour.tournoment_name;
    for(int i=0;i<tour.teame_number;i++)
    {
        tour.team_names[i]=tour.team_names[i];
    }

}
void tournoment::  setID()
{
    this->tournoment_id=QDate::currentDate().toString("yyyy/MM/dd")+QTime::currentTime().toString("hh:mm:ss");

}
QTextStream& operator << (QTextStream &out, tournoment &tour)
{
     out<<attach_qstring(tour.tournoment_id)<<" ";
     out<<tour.type<<" ";
     out<<attach_qstring(tour.tournoment_name)<<" ";
     out<<attach_qstring(tour.start_date.toString("yyyy/MM/dd"))<<" ";
     out<<attach_qstring(tour.start_time.toString("hh:mm"))<<" ";
     out<<tour.teame_number<<" ";
     for(int i=0;i<tour.teame_number;i++)
     {
         out<<attach_qstring(tour.team_names[i])<<" ";
     }
     out<<attach_qstring(tour.about)<<"\n";
     return out;
}

QTextStream& operator >> (QTextStream &input, tournoment &tour)
{

    input>>tour.tournoment_id;
    tour.tournoment_id=separate_qstring(tour.tournoment_id);
   input>>tour.type;
   input>>tour.tournoment_name;
    tour.tournoment_name=separate_qstring(tour.tournoment_name);
    //if(tour.tournoment_name==nullptr) return input;//rafe irade gir oftadan to loop baraye file khali
    QString s1;

    input>>s1;
    s1=separate_qstring(s1);
    tour.start_date = QDate::fromString(s1,"yyyy/MM/dd");
    input>>s1;
    s1=separate_qstring(s1);
    tour.start_time = QTime::fromString(s1,"hh:mm");

    input>>tour.teame_number;

    //tour.team_names=new QString(tour.teame_number);
    QString qs;
    tour.team_names.clear();
    for(int i=0;i<tour.teame_number;i++)
    {
        input>>qs;
        qs=separate_qstring(qs);
        tour.team_names.append(qs);

    }
    input>>tour.about;

    tour.about=separate_qstring(tour.about);
    return input;
}
