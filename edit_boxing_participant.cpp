#include "edit_boxing_participant.h"
#include "ui_edit_boxing_participant.h"

edit_boxing_participant::edit_boxing_participant(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::edit_boxing_participant)
{
    ui->setupUi(this);
}

edit_boxing_participant::~edit_boxing_participant()
{
    delete ui;
}

void edit_boxing_participant::set_beforeedit(boxing_participant &asli)
{
    before_edit.username=asli.username;
    before_edit.team_name=asli.team_name;
    before_edit.password=asli.password;
    before_edit.playername=asli.playername;
    before_edit.nationality_code=asli.nationality_code;
    before_edit.team_email=asli.team_email;
}

void edit_boxing_participant::on_edit_clicked()
{

    QString user=ui->usename->text();
    QString pass=ui->pass->text();
    QString teamname=ui->team_name->text();
    QString playername=ui->name_2->text();
    QString nationalitycode=ui->code_meli_2->text();
    QString team_email=ui->email->text();
    after_edit=before_edit;
        if(user!=nullptr)
         {
            after_edit.username=user;
         }

        if(pass!=nullptr)
        {
            after_edit.password=pass;
        }

       if(team_email!=nullptr)
        {
            after_edit.team_email=team_email;
        }

        if(teamname!=nullptr)
        {
            after_edit.team_name=teamname;
        }

    if(playername!=nullptr)
        {
            after_edit.playername=playername;
        }

     if(nationalitycode!=nullptr)
        {
            after_edit.nationality_code=nationalitycode;

        }
        boxing_participant().edit(before_edit,after_edit);
        this->close();
}
