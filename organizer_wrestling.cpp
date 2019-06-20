#include "organizer_wrestling.h"
#include "ui_organizer_wrestling.h"
#include "QDate"
#include "QTime"
#include "QString"
#include "QFile"
#include "QTextStream"
#include "QMessageBox"
#include "add_tournament_wrestling.h"
#include "tournoment.h"
#include "QTableWidgetItem"
#include "wresteling_arrange.h"
organizer_wrestling::organizer_wrestling(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::organizer_wrestling)
{
    ui->setupUi(this);
    QFile f1("wrestling_tournoment.txt");//cheking for repeated user and teamname
    if(!f1.open(QIODevice::ReadOnly))
    {
        QMessageBox *err=new QMessageBox();
        err->setText("wrestling_tournoment file not found in wrestling_organizer!!");
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
    this->ui->tournoments_info->removeRow(this->ui->tournoments_info->rowCount()-1);
}

organizer_wrestling::~organizer_wrestling()
{
    delete ui;
}
void organizer_wrestling::show_participant(){}
void organizer_wrestling::show_tournament(){}//and show matches in every tournament
void organizer_wrestling::show_score_table(){}
bool organizer_wrestling::add_tournoment(tournoment *tour)
{

    QFile f("wrestling_tournoment.txt");//if we dont have file we must make file
    f.open(QFile::WriteOnly | QFile::Append);
    f.close();

    QFile f1("wrestling_tournoment.txt");//cheking for repeated user and teamname
    if(!f1.open(QIODevice::ReadOnly))
    {
        QMessageBox *err=new QMessageBox();
        err->setText("wrestling_tournoment file not found!!");
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
            err->setText("نامی که شما برای این مسابقه انتخاب کردید ، تکراری است. ");
            err->exec();
            delete err;
            return false;
        }
        else
            file_box>>tour_temp;
    }
    f1.close();
    QFile f2("wrestling_tournoment.txt");
    if(!f2.open(QFile::WriteOnly | QFile::Append))
    {
        QMessageBox *err=new QMessageBox();
        err->setText("wrestling_tournoment file not found!!");
        err->exec();
        delete err;
        this->close();
    }

    QTextStream file_box2(&f2);


    file_box2 << *tour;

    f2.close();
    return true;
}
void organizer_wrestling::manage_matches(){}//define matches in a tournoment
void organizer_wrestling::update_results(){}
void organizer_wrestling::edit_match(){}
void organizer_wrestling::cancel_match(){}

void organizer_wrestling::on_add_tour_clicked()
{
    add_tournament_wrestling *atw=new add_tournament_wrestling();
    atw->show();
}

void organizer_wrestling::on_refresh_clicked()
{
    organizer_wrestling *ow=new organizer_wrestling();
    ow->showFullScreen();
    delete this;
}

void organizer_wrestling::on_tournoments_info_cellClicked(int row, int column)
{
    wresteling_arrange *ba=new wresteling_arrange();
    ba->set_current_tournoment(ui->tournoments_info->item(row,0)->text());
    ba->showFullScreen();
}
