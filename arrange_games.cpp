#include "arrange_games.h"
#include "ui_arrange_games.h"
#include "match.h"
#include "QFile"
#include "QTextStream"
#include "QMessageBox"
arrange_games::arrange_games(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::arrange_games)
{
    ui->setupUi(this);
}


void arrange_games::setup(int type,tournoment &tour)
{
    this->tour=tour;
    this->type=type;

    for(int i=0;i<this->tour.teame_number;i++)          //fill team combo boxes
    {

        ui->team1->addItem(tour.team_names[i]);
        ui->team2->addItem(tour.team_names[i]);
    }

    this->ui->tour_naem_label->setText(tour.tournoment_name);//show our tournoment name

    if(this->type==1)//fill our game table
    {
        QFile f1("footsal_matches.txt");//cheking for repeated user and teamname
        if(!f1.open(QIODevice::ReadOnly))
        {
            QMessageBox *err=new QMessageBox();
            err->setText("footsal_matches file not found in arrange_games!!");
            err->exec();
            delete err;
        }
        QTextStream footsal_match(&f1);
        match footsal;
        footsal_match>>footsal;

        for(int i=0;footsal.tourmonet_name!=nullptr;)
        {
            if(footsal.tourmonet_name==this->tour.tournoment_name)
            {
                QTableWidgetItem *item = new
                QTableWidgetItem(footsal.team_name[0],1);
                this->ui->our_games->setItem(i, 0, item);

                item = new QTableWidgetItem(QString::number(footsal.score[0])+":"+QString::number(footsal.score[1]),1);
                this->ui->our_games->setItem(i, 1, item);

                item = new QTableWidgetItem(footsal.team_name[1],1);
                this->ui->our_games->setItem(i, 2, item);

                item = new QTableWidgetItem(footsal.start_date.toString("yy/MM/dd"),1);
                this->ui->our_games->setItem(i, 3, item);

                item = new QTableWidgetItem(footsal.start_time.toString("hh:mm"),1);
                this->ui->our_games->setItem(i, 4, item);

                item = new QTableWidgetItem("delete",1);
                item->setToolTip("click to delet the match");
                this->ui->our_games->setItem(i, 5, item);

                i++;
            }
            footsal_match>>footsal;

        }

    }
    else if(this->type==2)//fill our game table for westling
    {

        QFile f1("wrestling_matches.txt");//cheking for repeated user and teamname
        if(!f1.open(QIODevice::ReadOnly))
        {
            QMessageBox *err=new QMessageBox();
            err->setText("wrestling_matches file not found in arrange_games!!");
            err->exec();
            delete err;
        }
        QTextStream wrestling_match(&f1);
        match wrestling;
        wrestling_match>>wrestling;

        for(int i=0;wrestling.tourmonet_name!=nullptr;)
        {
            if(wrestling.tourmonet_name==this->tour.tournoment_name)
            {
                QTableWidgetItem *item = new
                QTableWidgetItem(wrestling.team_name[0],1);
                this->ui->our_games->setItem(i, 0, item);

                item = new QTableWidgetItem(QString::number(wrestling.score[0])+":"+QString::number(wrestling.score[1]),1);
                this->ui->our_games->setItem(i, 1, item);

                item = new QTableWidgetItem(wrestling.team_name[1],1);
                this->ui->our_games->setItem(i, 2, item);

                item = new QTableWidgetItem(wrestling.start_date.toString("yy/MM/dd"),1);
                this->ui->our_games->setItem(i, 3, item);

                item = new QTableWidgetItem(wrestling.start_time.toString("hh:mm"),1);
                this->ui->our_games->setItem(i, 4, item);

                item = new QTableWidgetItem("delete",1);
                item->setToolTip("click to delet the match");
                this->ui->our_games->setItem(i, 5, item);

                i++;
            }
            wrestling_match>>wrestling;

        }
        f1.close();
    }
    else if(this->type==3)//fill our game table
    {
        QFile f2("boxing_tournoment.txt");//cheking for repeated user and teamname
        if(!f2.open(QIODevice::ReadOnly))
        {
            QMessageBox *err=new QMessageBox();
            err->setText("boxing_tournoment file not found in arrange_games!!");
            err->exec();
            delete err;
        }
        QTextStream boxing_tournoment(&f2);
        tournoment boxtour;
        boxing_tournoment>>boxtour;

        for(int i=0;i<boxtour.teame_number;i++)          //fill team combo boxes
        {
            ui->tournoments->addItem(boxtour.tournoment_name);
        }
        ui->tournoments->setCurrentText(tour.tournoment_name);///////////////////////////////
        QFile f1("boxing_matches.txt");//cheking for repeated user and teamname
        if(!f1.open(QIODevice::ReadOnly))
        {
            QMessageBox *err=new QMessageBox();
            err->setText("boxing_matches file not found in arrange_games!!");
            err->exec();
            delete err;
        }
        QTextStream boxing_match(&f1);
        match boxing;
        boxing_match>>boxing;
        for(int i=0;boxing.tourmonet_name!=nullptr;)
        {
            if(boxing.tourmonet_name==this->tour.tournoment_name)
            {
                QTableWidgetItem *item = new
                QTableWidgetItem(boxing.team_name[0],1);
                ui->our_games->setItem(i, 0, item);

                item = new QTableWidgetItem(QString::number(boxing.score[0])+":"+QString::number(boxing.score[1]),1);
                ui->our_games->setItem(i, 1, item);

                item = new QTableWidgetItem(boxing.team_name[1],1);
                ui->our_games->setItem(i, 2, item);

                item = new QTableWidgetItem(boxing.start_date.toString("yy/MM/dd"),1);
                ui->our_games->setItem(i, 3, item);

                item = new QTableWidgetItem(boxing.start_time.toString("hh:mm"),1);
                ui->our_games->setItem(i, 4, item);

                item = new QTableWidgetItem("delete",1);
                item->setToolTip("click to delet the match");
                ui->our_games->setItem(i, 5, item);

                i++;
            }
            boxing_match>>boxing;

        }
        f1.close();

    }
    else
    {
        QMessageBox qmb;
        qmb.setText("error in type in arrange ");
        qmb.exec();
    }
    // this->ui->our_games->setItem()
}

arrange_games::~arrange_games()
{
    delete ui;
}

void arrange_games::on_pushButton_clicked()//for adding match to file
{
    match temp;
    temp.tourmonet_name=this->tour.tournoment_name;
    temp.start_date=this->ui->dateTimeEdit->date();
    temp.start_time=this->ui->dateTimeEdit->time();
    temp.team_name[0]=this->ui->team1->currentText();
    temp.team_name[1]=this->ui->team2->currentText();
    temp.type=this->type;
    temp.score[0]=-1;//bazi hanoz shoro nashode
    temp.score[1]=-1;

   temp.add_match_to_file();

}

void arrange_games::on_our_games_cellClicked(int row, int column)
{
    //برای حذف کردن باید کد نویسی کنیم
}

void arrange_games::on_our_games_cellChanged(int row, int column)
{
    //برای اعمال تغییرا تباید کد نویسی کنیم
}
