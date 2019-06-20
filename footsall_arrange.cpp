#include "footsall_arrange.h"
#include "ui_footsall_arrange.h"
#include "match.h"
#include "QFile"
#include "QTextStream"
#include "QMessageBox"
#include "tournoment.h"
footsall_arrange::footsall_arrange(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::footsall_arrange)
{
    ui->setupUi(this);
    QFile f2("footsal_tournoment.txt");//cheking for repeated user and teamname
    if(!f2.open(QIODevice::ReadOnly))
    {
        QMessageBox *err=new QMessageBox();
        err->setText("footsal_tournoment file not found in arrange_games!!");
        err->exec();
        delete err;
    }
    QTextStream footsal_tournoment(&f2);
    tournoment salltour;
    footsal_tournoment>>salltour;

    while(salltour.tournoment_name!=nullptr)
    {
        ui->tournoments->addItem(salltour.tournoment_name);
        footsal_tournoment>>salltour;
    }
    // ui->tournoments->setCurrentText("golestan2");///baraye farakhani
     this->on_tournoments_activated(ui->tournoments->currentText());

}

footsall_arrange::~footsall_arrange()
{
    delete ui;
}
void  footsall_arrange::set_current_tournoment(QString qs)
{
    ui->tournoments->setCurrentText(qs);
    this->on_tournoments_activated(ui->tournoments->currentText());

}
void footsall_arrange::on_tournoments_activated(const QString &arg1)
{

   // ui->tour_naem_label->setText(ui->tournoments->currentText());
    QFile f2("footsal_tournoment.txt");//cheking for repeated user and teamname
    if(!f2.open(QIODevice::ReadOnly))
    {
        QMessageBox *err=new QMessageBox();
        err->setText("footsal_tournoment file not found in arrange_games!!");
        err->exec();
        delete err;
    }
    QTextStream footsal_tournoment(&f2);
    tournoment salltour;
    footsal_tournoment>>salltour;
    ui->team1->clear();
    ui->team2->clear();
    while(salltour.tournoment_name!=nullptr)
    {
        if(salltour.tournoment_name==arg1)
        {
            ui->dateTimeEdit->setDate(salltour.start_date);
            ui->dateTimeEdit->setTime(salltour.start_time);
            for(int i=0;i<salltour.teame_number;i++)          //fill team combo boxes
            {
                ui->team1->addItem(salltour.team_names[i]);
                ui->team2->addItem(salltour.team_names[i]);
            }
            break;
        }
         footsal_tournoment>>salltour;
    }
    f2.close();
    QFile f1("footsall_matches.txt");//cheking for repeated user and teamname
    if(!f1.open(QIODevice::ReadOnly))
    {
        QMessageBox *err=new QMessageBox();
        err->setText("footsall_matches file not found in arrange_games!!");
        err->exec();
        delete err;
    }
    QTextStream footsall_match(&f1);
    match footsall;
    footsall_match>>footsall;
  //  ui->our_games->clear();
    ui->our_games->setRowCount(0);
    for(int i=0;footsall.tourmonet_name!=nullptr;)
    {
        if(footsall.tourmonet_name==arg1)
        {
            ui->our_games->insertRow( ui->our_games->rowCount() );
            QTableWidgetItem *item = new
            QTableWidgetItem(footsall.team_name[0],1);
            item->setFlags(item->flags() &  ~Qt::ItemIsEditable);
            ui->our_games->setItem(i, 0, item);

            if(footsall.score[0]!= -1)
                item = new QTableWidgetItem(QString::number(footsall.score[0]),1);
            else
                item = new QTableWidgetItem("___",1);
            ui->our_games->setItem(i, 1, item);
            if(footsall.score[1]!= -1)
                item = new QTableWidgetItem(QString::number(footsall.score[1]),1);
            else
                item = new QTableWidgetItem("___",1);
            ui->our_games->setItem(i, 2, item);

            item = new QTableWidgetItem(footsall.team_name[1],1);
            item->setFlags(item->flags() &  ~Qt::ItemIsEditable);
            ui->our_games->setItem(i, 3, item);

            item = new QTableWidgetItem(footsall.start_date.toString("yyyy/MM/dd"),1);
            ui->our_games->setItem(i, 4, item);

            item = new QTableWidgetItem(footsall.start_time.toString("hh:mm"),1);
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
        footsall_match>>footsall;

    }
    f1.close();

}

void footsall_arrange::on_addgame_clicked()
{

    match mat;
    mat.type=1;
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
//    footsall_arrange dd=*this;
//    dd.show;
}

void footsall_arrange::on_our_games_cellDoubleClicked(int row, int column)
{
    if(column==7/*column==1 || column==2 || column==4 ||column==5*/)
    {

        QFile f1("footsall_matches.txt");//cheking for repeated user and teamname
        if(!f1.open(QIODevice::ReadOnly))
        {
            QMessageBox *err=new QMessageBox();
            err->setText("footsall_matches file not found in arrange_games!!");
            err->exec();
            delete err;
        }
        QTextStream footsall_match(&f1);

        QFile f2("footsall_matches2.txt");// file for edit and rename
        f2.open(QFile::WriteOnly | QFile::Append);
        QTextStream footsall_match2(&f2);

        match footsall;
        footsall_match>>footsall;
        for(int i=-1;footsall.tourmonet_name!=nullptr;)
        {
            if(footsall.tourmonet_name==ui->tournoments->currentText())
            {
                i++;
            }
            if(i==row)//ترتیب قرار گیری در فایل و جدول یکسان است
            {
                footsall.score[0]=ui->our_games->item(row,1)->text().toInt();
                footsall.score[1]=ui->our_games->item(row,2)->text().toInt();
                footsall.start_date=QDate::fromString(ui->our_games->item(row,4)->text(),"yyyy/MM/dd");
                if(!footsall.start_date.isValid())
                {
                    QMessageBox qb;
                    qb.setText("تاریخ وارد شده نا معتبر است");
                    qb.exec();
                    f1.close();
                    f2.close();
                    return;
                }
                footsall.start_time=QTime::fromString(ui->our_games->item(row,5)->text(),"hh:mm");
                if(!footsall.start_time.isValid())
                {
                    QMessageBox qb;
                    qb.setText("زمان وارد شده نا معتبر است");
                    qb.exec();
                    f1.close();
                    f2.close();
                    return;
                }
            }
            footsall_match2<<footsall;
            footsall_match>>footsall;
        }
        f2.close();
        f1.close();
        remove("footsall_matches.txt");
        rename("footsall_matches2.txt","footsall_matches.txt");
        QMessageBox edit;
        edit.setText(" تغیرات اعمال شد");
        edit.exec();
        this->on_tournoments_activated(ui->tournoments->currentText());
    }
    if(column==6)
    {
        QFile f1("footsall_matches.txt");//cheking for repeated user and teamname
        if(!f1.open(QIODevice::ReadOnly))
        {
            QMessageBox *err=new QMessageBox();
            err->setText("footsall_matches file not found in arrange_games!!");
            err->exec();
            delete err;
        }
        QTextStream footsall_match(&f1);

        QFile f2("footsall_matches2.txt");// file for edit and rename
        f2.open(QFile::WriteOnly | QFile::Append);
        QTextStream footsall_match2(&f2);

        match footsall;
        footsall_match>>footsall;
        for(int i=-1;footsall.tourmonet_name!=nullptr;)
        {
            if(footsall.tourmonet_name==ui->tournoments->currentText())
            {
                i++;
            }
            if(i!=row)//ترتیب قرار گیری در فایل و جدول یکسان است
            {
                footsall_match2<<footsall;
            }
            footsall_match>>footsall;
        }
        f2.close();
        f1.close();
        remove("footsall_matches.txt");
        rename("footsall_matches2.txt","footsall_matches.txt");
        QMessageBox edit;
        edit.setText("مسابقه حذف شد");
        edit.exec();
        this->on_tournoments_activated(ui->tournoments->currentText());//update widget table
    }
}

