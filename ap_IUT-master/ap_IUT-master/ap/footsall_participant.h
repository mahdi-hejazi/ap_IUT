#ifndef FOOTSALL_PARTICIPANT_H
#define FOOTSALL_PARTICIPANT_H
#include"QTextStream"
#include <QWidget>
#include "QTextStream"
#include "participant.h"
#include "QString"
namespace Ui {
class footsall_participant;
}

class footsall_participant : public QWidget,public participant
{
    Q_OBJECT

public:
    explicit footsall_participant(QWidget *parent = nullptr);
    ~footsall_participant();

    footsall_participant (const footsall_participant &footi);
    footsall_participant login(QString user,QString pass);
    void set(QString user,QString pass,QString teamname,QString playernames[10],QString nationalitycode[10],QString team_email);
    virtual bool sign_in(QString user, QString pass, QString teamname, QString playernames[10], QString nationalitycode[10], QString team_email);
    virtual void edit();
    //virtual void show_competitor() = 0;//for see our competitor and theire results
    virtual void observe_login_tournoments();
    virtual void show_score_table();//we can see our competitor and they informations
    virtual void show_our_tournament();//show how much time we have untill tournoment
    virtual void shw_over_matches();
    friend QTextStream& operator << (QTextStream &out, footsall_participant &tour);
    friend QTextStream& operator >> (QTextStream &input, footsall_participant &tour);

private:
    Ui::footsall_participant *ui;
    QString playernames[10];//we have at most ten players
    QString nationality_code[10];
};

#endif // FOOTSALL_PARTICIPANT_H
