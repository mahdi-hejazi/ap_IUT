#include "add_tournament_wrestling.h"
#include "ui_add_tournament_wrestling.h"
#include "tournoment.h"
#include "organizer_wrestling.h"
#include "QMessageBox"
add_tournament_wrestling::add_tournament_wrestling(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::add_tournament_wrestling)
{
    ui->setupUi(this);
    ui->dateTimeEdit->setDate(QDate::currentDate());
}

add_tournament_wrestling::~add_tournament_wrestling()
{
    delete ui;
}

void add_tournament_wrestling::on_add_tournoment_butten_clicked()
{
    if(this->ui->tournoment_name->text()==nullptr)
    {
        QString errori="نوشتن نام مسابق الزامی است";
        ui->tournoment_name->setPlaceholderText(errori);
        QPalette palette = ui->tournoment_name->palette();
        palette.setColor(ui->tournoment_name->foregroundRole(), Qt::red);
        ui->tournoment_name->setPalette(palette);
    }
    if(ui->tournoment_about->text()==nullptr)
    {
        QString errori="نوشتن توضیحات الزامی است";
        ui->tournoment_about->setPlaceholderText(errori);
        QPalette palette = ui->tournoment_about->palette();
        palette.setColor(ui->tournoment_about->foregroundRole(), Qt::red);
        ui->tournoment_about->setPalette(palette);
    }
    else
    {
        tournoment *tour=new tournoment();
        tour->tournoment_name=this->ui->tournoment_name->text();
        tour->about=this->ui->tournoment_about->text();
        tour->start_date=this->ui->dateTimeEdit->date();
        tour->start_time=this->ui->dateTimeEdit->time();
        tour->teame_number=0;
        organizer_wrestling *ow=new organizer_wrestling();

        bool check=ow->add_tournoment(tour);

        delete tour;
        if (check)
        {
            QMessageBox *pm=new QMessageBox();
            pm->setText("تورنومنت شما ثبت شد.");
            pm->exec();
            delete pm;
        }
    }
}
