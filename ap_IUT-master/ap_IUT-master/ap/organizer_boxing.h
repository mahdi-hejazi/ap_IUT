#ifndef ORGANIZER_BOXING_H
#define ORGANIZER_BOXING_H

#include <QWidget>

namespace Ui {
class organizer_boxing;
}

class organizer_boxing : public QWidget
{
    Q_OBJECT

public:
    explicit organizer_boxing(QWidget *parent = nullptr);
    ~organizer_boxing();
    void show_participant();
    void show_tournament();//and show matches in every tournament
    void show_score_table();
    bool add_tournament();
    void manage_matches();//define matches in a tournoment
    void update_results();
    void edit_match();
    void cancel_match();
   // friend ostream& operator << (ostream &out, organizer &tour);
    //friend istream& operator >> (istream &input, organizer &tour);
private:
    Ui::organizer_boxing *ui;
};

#endif // ORGANIZER_BOXING_H
