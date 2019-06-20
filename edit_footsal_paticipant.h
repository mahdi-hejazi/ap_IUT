#ifndef EDIT_FOOTSAL_PATICIPANT_H
#define EDIT_FOOTSAL_PATICIPANT_H

#include <QWidget>
#include "footsall_participant.h"
namespace Ui {
class edit_footsal_paticipant;
}

class edit_footsal_paticipant : public QWidget
{
    Q_OBJECT

public:
    explicit edit_footsal_paticipant(QWidget *parent = nullptr);
    ~edit_footsal_paticipant();

private slots:
    void on_edit_clicked();

private:
    footsall_participant before_edit;
    footsall_participant after_edit;
    Ui::edit_footsal_paticipant *ui;
};

#endif // EDIT_FOOTSAL_PATICIPANT_H
