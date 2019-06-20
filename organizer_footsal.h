#ifndef ORGANIZER_FOOTSAL_H
#define ORGANIZER_FOOTSAL_H

#include <QWidget>
#include "organizer.h"
#include "tournoment.h"
namespace Ui {
class organizer_footsal;
}

class organizer_footsal : public QWidget//,public organizer
{
    Q_OBJECT

public:
    explicit organizer_footsal(QWidget *parent = nullptr);
    ~organizer_footsal();
     void show_participant();
     void show_tournament();//and show matches in every tournament
     void show_score_table();
     bool add_tournoment(tournoment *tour);
     void manage_matches();//define matches in a tournoment
     void update_results();
     void edit_match();
     void cancel_match();
private slots:
     void on_add_tour_clicked();

     void on_refresh_clicked();

     void on_tournoments_info_cellClicked(int row, int column);

private:
    Ui::organizer_footsal *ui;
};

#endif // ORGANIZER_FOOTSAL_H
