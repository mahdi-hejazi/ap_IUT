#include "boxing_arrange.h"
#include "ui_boxing_arrange.h"
#include "match.h"
#include "QFile"
#include "QTextStream"
#include "QMessageBox"
#include "tournoment.h"
boxing_arrange::boxing_arrange(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::boxing_arrange)
{
    ui->setupUi(this);
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

    while(boxtour.tournoment_name!=nullptr)
    {
        ui->tournoments->addItem(boxtour.tournoment_name);
        boxing_tournoment>>boxtour;
    }
    // ui->tournoments->setCurrentText("golestan2");///baraye farakhani
     this->on_tournoments_activated(ui->tournoments->currentText());

}

boxing_arrange::~boxing_arrange()
{
    delete ui;
}
void  boxing_arrange::set_current_tournoment(QString qs)
{
    ui->tournoments->setCurrentText(qs);
    this->on_tournoments_activated(ui->tournoments->currentText());

}
void boxing_arrange::on_tournoments_activated(const QString &arg1)
{

   // ui->tour_naem_label->setText(ui->tournoments->currentText());
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
    ui->team1->clear();
    ui->team2->clear();
    while(boxtour.tournoment_name!=nullptr)
    {
        if(boxtour.tournoment_name==arg1)
        {
            ui->dateTimeEdit->setDate(boxtour.start_date);
            ui->dateTimeEdit->setTime(boxtour.start_time);
            for(int i=0;i<boxtour.teame_number;i++)          //fill team combo boxes
            {
                ui->team1->addItem(boxtour.team_names[i]);
                ui->team2->addItem(boxtour.team_names[i]);
            }
            break;
        }
         boxing_tournoment>>boxtour;
    }
    f2.close();
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
  //  ui->our_games->clear();
    ui->our_games->setRowCount(0);
    for(int i=0;boxing.tourmonet_name!=nullptr;)
    {
        if(boxing.tourmonet_name==arg1)
        {
            ui->our_games->insertRow( ui->our_games->rowCount() );
            QTableWidgetItem *item = new
            QTableWidgetItem(boxing.team_name[0],1);
            item->setFlags(item->flags() &  ~Qt::ItemIsEditable);
            ui->our_games->setItem(i, 0, item);

            if(boxing.score[0]!= -1)
                item = new QTableWidgetItem(QString::number(boxing.score[0]),1);
            else
                item = new QTableWidgetItem("___",1);
            ui->our_games->setItem(i, 1, item);
            if(boxing.score[1]!= -1)
                item = new QTableWidgetItem(QString::number(boxing.score[1]),1);
            else
                item = new QTableWidgetItem("___",1);
            ui->our_games->setItem(i, 2, item);

            item = new QTableWidgetItem(boxing.team_name[1],1);
            item->setFlags(item->flags() &  ~Qt::ItemIsEditable);
            ui->our_games->setItem(i, 3, item);

            item = new QTableWidgetItem(boxing.start_date.toString("yyyy/MM/dd"),1);
            ui->our_games->setItem(i, 4, item);

            item = new QTableWidgetItem(boxing.start_time.toString("hh:mm"),1);
            ui->our_games->setItem(i, 5, item);

            item = new QTableWidgetItem("delete",1);
            item->setFlags(item->flags() &  ~Qt::ItemIsEditable);
            item->setToolTip("click to delet the match");
            ui->our_games->setItem(i, 6, item);

            item = new QTableWidgetItem("اعمال تغییرات",1);
            item->setFlags(item->flags() &  ~Qt::ItemIsEditable);
            item->setToolTip("click to delet the match");
            ui->our_games->setItem(i, 7, item);

            i++;
        }
        boxing_match>>boxing;

    }
    f1.close();

}

void boxing_arrange::on_addgame_clicked()
{

    match mat;
    mat.type=3;
    mat.tourmonet_name=ui->tournoments->currentText();
    mat.team_name[0]=ui->team1->currentText();
    mat.team_name[1]=ui->team2->currentText();
    mat.score[0]=mat.score[1]=-1;
    mat.start_date=ui->dateTimeEdit->date();
    mat.start_time=ui->dateTimeEdit->time();
    mat.add_match_to_file();
    auto q=new QMessageBox();
    q->setText("مسابقه با موفقیت ثبت شد");
    q->exec();
    this->on_tournoments_activated(ui->tournoments->currentText());
//    boxing_arrange dd=*this;
//    dd.show;
}

void boxing_arrange::on_our_games_cellDoubleClicked(int row, int column)
{
    if(column==7/*column==1 || column==2 || column==4 ||column==5*/)
    {

        QFile f1("boxing_matches.txt");//cheking for repeated user and teamname
        if(!f1.open(QIODevice::ReadOnly))
        {
            QMessageBox *err=new QMessageBox();
            err->setText("boxing_matches file not found in arrange_games!!");
            err->exec();
            delete err;
        }
        QTextStream boxing_match(&f1);

        QFile f2("boxing_matches2.txt");// file for edit and rename
        f2.open(QFile::WriteOnly | QFile::Append);
        QTextStream boxing_match2(&f2);

        match boxing;
        boxing_match>>boxing;
        for(int i=-1;boxing.tourmonet_name!=nullptr;)
        {
            if(boxing.tourmonet_name==ui->tournoments->currentText())
            {
                i++;
            }
            if(i==row)//ترتیب قرار گیری در فایل و جدول یکسان است
            {
                boxing.score[0]=ui->our_games->item(row,1)->text().toInt();
                boxing.score[1]=ui->our_games->item(row,2)->text().toInt();
                boxing.start_date=QDate::fromString(ui->our_games->item(row,4)->text(),"yyyy/MM/dd");
                if(!boxing.start_date.isValid())
                {
                    QMessageBox qb;
                    qb.setText("تاریخ وارد شده نا معتبر است");
                    qb.exec();
                    f1.close();
                    f2.close();
                    return;
                }
                boxing.start_time=QTime::fromString(ui->our_games->item(row,5)->text(),"hh:mm");
                if(!boxing.start_time.isValid())
                {
                    QMessageBox qb;
                    qb.setText("زمان وارد شده نا معتبر است");
                    qb.exec();
                    f1.close();
                    f2.close();
                    return;
                }
            }
            boxing_match2<<boxing;
            boxing_match>>boxing;
        }
        f2.close();
        f1.close();
        remove("boxing_matches.txt");
        rename("boxing_matches2.txt","boxing_matches.txt");
        QMessageBox edit;
        edit.setText(" تغیرات اعمال شد");
        edit.exec();
        this->on_tournoments_activated(ui->tournoments->currentText());
    }
    if(column==6)
    {
        QFile f1("boxing_matches.txt");//cheking for repeated user and teamname
        if(!f1.open(QIODevice::ReadOnly))
        {
            QMessageBox *err=new QMessageBox();
            err->setText("boxing_matches file not found in arrange_games!!");
            err->exec();
            delete err;
        }
        QTextStream boxing_match(&f1);

        QFile f2("boxing_matches2.txt");// file for edit and rename
        f2.open(QFile::WriteOnly | QFile::Append);
        QTextStream boxing_match2(&f2);

        match boxing;
        boxing_match>>boxing;
        for(int i=-1;boxing.tourmonet_name!=nullptr;)
        {
            if(boxing.tourmonet_name==ui->tournoments->currentText())
            {
                i++;
            }
            if(i!=row)//ترتیب قرار گیری در فایل و جدول یکسان است
            {
                boxing_match2<<boxing;
            }
            boxing_match>>boxing;
        }
        f2.close();
        f1.close();
        remove("boxing_matches.txt");
        rename("boxing_matches2.txt","boxing_matches.txt");
        QMessageBox edit;
        edit.setText("مسابقه حذف شد");
        edit.exec();
        this->on_tournoments_activated(ui->tournoments->currentText());//update widget table
    }
}

