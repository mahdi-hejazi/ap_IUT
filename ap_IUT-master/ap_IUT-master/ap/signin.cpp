#include "signin.h"
#include "ui_signin.h"
#include "boxing_participant.h"
signin::signin(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::signin)
{
    ui->setupUi(this);
}

signin::~signin()
{
    delete ui;
}

void signin::on_sabtenam_clicked()
{
//    if(ui->box->isChecked())
//    {

//    }
}

void signin::on_sabtenam_3_clicked()//footsall
{

}
