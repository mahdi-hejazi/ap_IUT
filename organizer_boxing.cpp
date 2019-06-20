#include "organizer_boxing.h"
#include "ui_organizer_boxing.h"
#include "QDate"
#include "QTime"
#include "QString"
#include "QFile"
#include "QTextStream"
#include "QMessageBox"
#include "add_tournoment_boxing.h"
#include "tournoment.h"
#include "QTableWidgetItem"
#include "boxing_arrange.h"
organizer_boxing::organizer_boxing(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::organizer_boxing)
{
    ui->setupUi(this);

    QFile f1("boxing_tournoment.txt");//cheking for repeated user and teamname
    if(!f1.open(QIODevice::ReadOnly))
    {
        QMessageBox *err=new QMessageBox();
        err->setText("boxing_tournoment file not found in boxing_organizer!!");
        err->exec();
        delete err;
    }

    QTextStream footsal_tour(&f1);
    tournoment footsal;
    footsal_tour>>footsal;
//tournoment table
    for(int i=0;footsal.tournoment_name!=nullptr;this->ui->tournoments_info->insertRow( this->ui->tournoments_info->rowCount() ))
    {
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
    }
    f1.close();
    this->ui->tournoments_info->removeRow(this->ui->tournoments_info->rowCount()-1);
}
//organizer_boxing:: organizer_boxing(const organizer_boxing &ob)
//{
//    this->type=ob.type;
//}
organizer_boxing::~organizer_boxing()
{
    delete ui;
}
void organizer_boxing::show_participant(){}
void organizer_boxing::show_tournament(){}//and show matches in every tournament
void organizer_boxing::show_score_table(){}
bool organizer_boxing::add_tournament(tournoment *tour)
{

    QFile f("boxing_tournoment.txt");//if we dont have file we must make file
    f.open(QFile::WriteOnly | QFile::Append);
    f.close();

    QFile f1("boxing_tournoment.txt");//cheking for repeated user and teamname
    if(!f1.open(QIODevice::ReadOnly))
    {
        QMessageBox *err=new QMessageBox();
        err->setText("boxing_tournoment file not found!!");
        err->exec();
        delete err;
        this->close();
    }

    QTextStream file_box(&f1);
    tournoment tour_temp;

    file_box>>tour_temp;

    while(tour_temp.tournoment_name != nullptr)
    {

        if(tour_temp.tournoment_name==tour->tournoment_name)
        {
            QMessageBox *err=new QMessageBox();
            err->setText("نامی که شما برای این تورنومنت انتخاب کردید ، تکراری است. ");
            err->exec();
            delete err;
            return false;
        }
        else
            file_box>>tour_temp;
    }
    f1.close();
    QFile f2("boxing_tournoment.txt");
    if(!f2.open(QFile::WriteOnly | QFile::Append))
    {
        QMessageBox *err=new QMessageBox();
        err->setText("boxing_tournoment file not found!!");
        err->exec();
        delete err;
        this->close();
    }

    QTextStream file_box2(&f2);


    file_box2 << *tour;

    f2.close();
    return true;
}
void organizer_boxing::manage_matches(){}//define matches in a tournoment
void organizer_boxing::update_results(){}
void organizer_boxing::edit_match(){}
void organizer_boxing::cancel_match(){}





void organizer_boxing::on_add_tour_clicked()
{
    add_tournoment_boxing *atb=new add_tournoment_boxing();
    atb->show();
}



void organizer_boxing::on_tournoments_info_cellClicked(int row, int column)
{
    boxing_arrange *ba=new boxing_arrange();
    ba->set_current_tournoment(ui->tournoments_info->item(row,0)->text());
    ba->showFullScreen();

}

void organizer_boxing::on_refresh_clicked()
{
    organizer_boxing *ob=new organizer_boxing();
   // *ob = *this;
    delete this;
    ob->showFullScreen();
}
