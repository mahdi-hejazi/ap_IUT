#ifndef WRESTELING_PARTICIPANT_H
#define WRESTELING_PARTICIPANT_H

#include <QWidget>
#include "QTextStream"
#include "participant.h"
#include "QString"
namespace Ui {
class wresteling_participant;
}

class wresteling_participant : public QWidget , public participant
{
    Q_OBJECT

public:
    explicit wresteling_participant(QWidget *parent = nullptr);
    ~wresteling_participant();

    wresteling_participant:: wresteling_participant(const wresteling_participant &boxi);
    wresteling_participant login(QString , QString );
    void set(QString , QString , QString, QString, QString, QString);
    virtual bool sign_in(QString , QString , QString, QString, QString, QString);
    virtual void edit();
    //virtual void show_competitor() = 0;//for see our competitor and theire results
    virtual void observe_login_tournoments();
    virtual void show_score_table();//we can see our competitor and they informations
    virtual void show_our_tournament();//show how much time we have untill tournoment
    virtual void shw_over_matches();
    friend QTextStream& operator << (QTextStream &out, wresteling_participant &tour);
    friend QTextStream& operator >> (QTextStream &input, wresteling_participant &tour);

private:
    Ui::wresteling_participant *ui;
    QString playername;
    QString nationality_code;
};

#endif // WRESTELING_PARTICIPANT_H
