#ifndef ADD_TOURNAMENT_WRESTLING_H
#define ADD_TOURNAMENT_WRESTLING_H

#include <QWidget>

namespace Ui {
class add_tournament_wrestling;
}

class add_tournament_wrestling : public QWidget
{
    Q_OBJECT

public:
    explicit add_tournament_wrestling(QWidget *parent = nullptr);
    ~add_tournament_wrestling();

private slots:
    void on_add_tournoment_butten_clicked();

private:
    Ui::add_tournament_wrestling *ui;
};

#endif // ADD_TOURNAMENT_WRESTLING_H
