#ifndef FOOTSALL_ARRANGE_H
#define FOOTSALL_ARRANGE_H

#include <QWidget>

namespace Ui {
class footsall_arrange;
}

class footsall_arrange : public QWidget
{
    Q_OBJECT

public:
    explicit footsall_arrange(QWidget *parent = nullptr);
    ~footsall_arrange();
    void set_current_tournoment(QString);
private slots:
    void on_tournoments_activated(const QString &arg1);

    void on_addgame_clicked();

    void on_our_games_cellDoubleClicked(int row, int column);


private:
    Ui::footsall_arrange *ui;
};

#endif // FOOTSALL_ARRANGE_H
