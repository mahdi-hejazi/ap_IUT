#ifndef FOOTSALL_PARTICIPANT_H
#define FOOTSALL_PARTICIPANT_H
#include"QTextStream"
#include <QWidget>
#include "QTextStream"
#include "participant.h"
//#include "QString"
namespace Ui {
class footsall_participant;
}

class footsall_participant : public QWidget,public participant
{
    Q_OBJECT

public:
    friend class edit_footsal_participant;
    explicit footsall_participant(QWidget *parent = nullptr);
    ~footsall_participant();
    friend class edit_footsal_paticipant;
    bool login(footsall_participant&);
    void set(QString user,QString pass,QString teamname,QString playernames[10],QString nationalitycode[10],QString team_email);
    virtual bool sign_in(QString user, QString pass, QString teamname, QString playernames[10], QString nationalitycode[10], QString team_email);
    void edit(footsall_participant&,footsall_participant&);
    //virtual void show_competitor() = 0;//for see our competitor and theire results
    virtual void observe_login_tournoments();
    virtual void show_score_table();//we can see our competitor and they informations
    virtual void show_our_tournament();//show how much time we have untill tournoment
    virtual void shw_over_matches();
    friend QTextStream& operator << (QTextStream &out, footsall_participant &tour);
    friend QTextStream& operator >> (QTextStream &input, footsall_participant &tour);
    void operator = (footsall_participant &);
private slots:
    void on_tournoments_info_cellClicked(int row, int column);

    void on_refresh_clicked();

private:
    Ui::footsall_participant *ui;
    QString playernames[10];//we have at most ten players
    QString nationality_code[10];
};

#endif // FOOTSALL_PARTICIPANT_H
