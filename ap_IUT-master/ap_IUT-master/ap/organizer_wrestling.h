#ifndef ORGANIZER_WRESTLING_H
#define ORGANIZER_WRESTLING_H

#include <QWidget>

namespace Ui {
class organizer_wrestling;
}

class organizer_wrestling : public QWidget
{
    Q_OBJECT

public:
    explicit organizer_wrestling(QWidget *parent = nullptr);
    ~organizer_wrestling();
    void show_participant();
    void show_tournament();//and show matches in every tournament
    void show_score_table();
    bool add_tournament();
    void manage_matches();//define matches in a tournoment
    void update_results();
    void edit_match();
    void cancel_match();

private:
    Ui::organizer_wrestling *ui;
};

#endif // ORGANIZER_WRESTLING_H
