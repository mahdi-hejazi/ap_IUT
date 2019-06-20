#ifndef TOURNOMENT_H
#define TOURNOMENT_H
#include "QString"
#include "qstringlist.h"
#include "string.h"
#include "iostream"
#include "QDate"
#include "QTime"
#include "QTextStream"
//#include "file.h"
using namespace std;
#include <QWidget>

namespace Ui {
class tournoment;
}

class tournoment : public QWidget
{
    Q_OBJECT

public:
    explicit tournoment(QWidget *parent = nullptr);
    tournoment(const tournoment &tour);
    ~tournoment();
    bool add_team_names(QString);
    int type;
    QString tournoment_name;
    QDate start_date;
    QTime start_time;
    int teame_number;
    //QString *team_names;
    QStringList team_names;
    QString tournoment_id;//bara zakhire kardan to file
    QString about;
    void setID();
    friend QTextStream& operator << (QTextStream &out, tournoment &tour);
    friend QTextStream& operator >> (QTextStream &input, tournoment &tour);
    void operator =(tournoment tour);
private:
    Ui::tournoment *ui;
    //if 1: footsal     if 2: wresteling   if 3:box

};

#endif // TOURNOMENT_H
