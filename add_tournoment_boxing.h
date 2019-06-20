#ifndef ADD_TOURNOMENT_BOXING_H
#define ADD_TOURNOMENT_BOXING_H

#include <QWidget>

namespace Ui {
class add_tournoment_boxing;
}

class add_tournoment_boxing : public QWidget
{
    Q_OBJECT

public:
    explicit add_tournoment_boxing(QWidget *parent = nullptr);
    ~add_tournoment_boxing();

private slots:
    void on_add_tournoment_butten_clicked();

private:
    Ui::add_tournoment_boxing *ui;
};

#endif // ADD_TOURNOMENT_BOXING_H
