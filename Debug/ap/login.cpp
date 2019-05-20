#include "login.h"
#include "ui_login.h"
#include "QMessageBox"
#include "QEvent"
#include "QFile"
login::login(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::login)
{
    ui->setupUi(this);
}

login::~login()
{
    delete ui;
}


void login::on_ok_clicked()
{
    QMessageBox s;
    s.setText("sss");
    bool modirlog;
    modirlog=ui->modir->isChecked();

    if(modirlog)
    {
        QFile f1("organizer.txt");
                if(f1.open(Q))
    }
}
