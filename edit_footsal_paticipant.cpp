#include "edit_footsal_paticipant.h"
#include "ui_edit_footsal_paticipant.h"
#include "footsall_participant.h"
edit_footsal_paticipant::edit_footsal_paticipant(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::edit_footsal_paticipant)
{
    ui->setupUi(this);
}

edit_footsal_paticipant::~edit_footsal_paticipant()
{
    delete ui;
}

void edit_footsal_paticipant::on_edit_clicked()
{
    QString user=ui->usename_3->text();
    QString pass=ui->pass_3->text();
    QString teamname=ui->team_name_3->text();
    QString playernames[10]{ ui->name1->text(),ui->name2->text(),ui->name3->text(),ui->name4->text(),
                           ui->name5->text(),ui->name6->text(),ui->name7->text(),ui->name8->text(),
                           ui->name9->text(),ui->name10->text() };

    QString nationalitycode[10]{ ui->codemeli1->text(),ui->codemeli2->text(),ui->codemeli3->text(),ui->codemeli4->text(),
                ui->codemeli5->text(),ui->codemeli6->text(),ui->codemeli7->text(),ui->codemeli8->text(),
                ui->codemeli9->text(),ui->codemeli10->text() };

    QString team_email=ui->email_3->text();
        after_edit=before_edit;
        if(user!=nullptr)
         {
            after_edit.username=user;
          }
        if(pass!=nullptr)
         {
            after_edit.password=pass;
          }
        if(teamname!=nullptr)
         {
            after_edit.team_name=teamname;
         }

        for(int i=0;i<10;i++)
        {
            if(playernames[i]!=nullptr)
                after_edit.playernames[i]=playernames[i];
        }

        for(int i=0;i<10;i++)
        {
            if(nationalitycode[i]!=nullptr)
                after_edit.nationality_code[i]=nationalitycode[i];
        }

        if(team_email!=nullptr)
         {
            after_edit.team_email=team_email;
         }
        footsall_participant().edit(before_edit,after_edit);
        this->close();
}

