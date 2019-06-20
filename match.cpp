#include "match.h"
#include "ui_match.h"
#include "file.h"
//#include "tournoment.h"
#include "QMessageBox"



match::match(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::match)
{
    ui->setupUi(this);
}

match::~match()
{
    delete ui;
}
void match::delete_match_from_file()
{
    /////////////////////////////////////////function for deleting a match . we will write it.
    if(this->type==1)
    {


    }
    else if(this->type==2)
    {

    }
    else if(this->type==3)
    {

    }
}
void match::add_match_to_file()
{
    if(this->type==1)
    {
        QFile f("footsall_matches.txt");//if we dont have file we must make file
        f.open(QFile::WriteOnly | QFile::Append);
        QTextStream fstream(&f);
        fstream<<*this;
        f.close();
    }
    else if(this->type==2)
    {
        QFile f("wresteling_matches.txt");//if we dont have file we must make file
        f.open(QFile::WriteOnly | QFile::Append);
        QTextStream fstream(&f);
        fstream<<*this;
        f.close();
    }
    else if(this->type==3)
    {
        QFile f("boxing_matches.txt");//if we dont have file we must make file
        f.open(QFile::WriteOnly | QFile::Append);
        QTextStream fstream(&f);
        fstream<<*this;
        f.close();
    }

}
bool match:: operator ==(match &mat)
{
    if(mat.tourmonet_name==this->tourmonet_name && mat.start_date==this->start_date && mat.start_time==this->start_time && mat.type==this->type)
        return true;
    else
        return false;
}
QTextStream& operator << (QTextStream &out, match &mat)
{
    out<<mat.type<<" ";
    out<<attach_qstring(mat.tourmonet_name)<<" ";
    out<<attach_qstring(mat.start_date.toString("yyyy/MM/dd"))<<" ";
    out<<attach_qstring(mat.start_time.toString("hh:mm"))<<" ";
    out<<attach_qstring(mat.team_name[0])<<" ";
    out<<attach_qstring(mat.team_name[1])<<" ";
    out<<mat.score[0]<<" ";
    out<<mat.score[1]<<"\n";
    return out;
}
QTextStream& operator >> (QTextStream &input, match &mat)
{
    input>>mat.type;
    input>>mat.tourmonet_name;
    mat.tourmonet_name=separate_qstring(mat.tourmonet_name);
    QString qs;
    input>>qs;
    mat.start_date=QDate:: fromString(qs,"yyyy/MM/dd");
    input>>qs;
    mat.start_time=QTime:: fromString(qs,"hh:mm");
    input>>mat.team_name[0]>>mat.team_name[1];
    mat.team_name[0]=separate_qstring(mat.team_name[0]);
    mat.team_name[1]=separate_qstring(mat.team_name[1]);
    input>>mat.score[0]>>mat.score[1];
    return input;
}
