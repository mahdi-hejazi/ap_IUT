#include "add_tournoment_boxing.h"
#include "ui_add_tournoment_boxing.h"
#include "tournoment.h"
#include "organizer_boxing.h"
#include "QMessageBox"
add_tournoment_boxing::add_tournoment_boxing(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::add_tournoment_boxing)
{
    ui->setupUi(this);
    ui->dateTimeEdit->setDate(QDate::currentDate());
}

add_tournoment_boxing::~add_tournoment_boxing()
{
    delete ui;
}

void add_tournoment_boxing::on_add_tournoment_butten_clicked()
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
        organizer_boxing *ob=new organizer_boxing();

        bool check=ob->add_tournament(tour);

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
