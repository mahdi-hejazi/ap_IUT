#ifndef ADD_TOURNAMENT_FOOTSAL_H
#define ADD_TOURNAMENT_FOOTSAL_H

#include <QWidget>

namespace Ui {
class add_tournament_footsal;
}

class add_tournament_footsal : public QWidget
{
    Q_OBJECT

public:
    explicit add_tournament_footsal(QWidget *parent = nullptr);
    ~add_tournament_footsal();

private slots:
    void on_add_tournoment_butten_clicked();

private:
    Ui::add_tournament_footsal *ui;
};

#endif // ADD_TOURNAMENT_FOOTSAL_H
