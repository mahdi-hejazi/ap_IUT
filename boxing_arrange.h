#ifndef BOXING_ARRANGE_H
#define BOXING_ARRANGE_H

#include <QWidget>

namespace Ui {
class boxing_arrange;
}

class boxing_arrange : public QWidget
{
    Q_OBJECT

public:
    explicit boxing_arrange(QWidget *parent = nullptr);
    ~boxing_arrange();
    void set_current_tournoment(QString);
private slots:
    void on_tournoments_activated(const QString &arg1);

    void on_addgame_clicked();

    void on_our_games_cellDoubleClicked(int row, int column);

private:
    Ui::boxing_arrange *ui;
};

#endif // BOXING_ARRANGE_H
