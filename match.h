#ifndef MATCH_H
#define MATCH_H
#include "iostream"
#include "string"
#include "QDate"
#include "QTime"
#include "QFile"
#include "QTextStream"

using namespace std;
#include <QWidget>

namespace Ui {
class match;
}

class match : public QWidget
{
    Q_OBJECT

public:
    explicit match(QWidget *parent = nullptr);
    ~match();
    int type;// 1:footsall 2:wrestling 3:boxing
    QString tourmonet_name;
    QDate start_date;
    QTime start_time;
    QString team_name[2];
    int score[2];
    void delete_match_from_file();
    void add_match_to_file();
    bool operator ==(match &mat);
    friend QTextStream& operator << (QTextStream &out, match &tour);
    friend QTextStream& operator >> (QTextStream &input, match &tour);
private:
    Ui::match *ui;

};

#endif // MATCH_H
