#ifndef EDIT_BOXING_PARTICIPANT_H
#define EDIT_BOXING_PARTICIPANT_H

#include <QWidget>
#include "boxing_participant.h"
namespace Ui {
class edit_boxing_participant;
}

class edit_boxing_participant : public QWidget
{
    Q_OBJECT

public:
    explicit edit_boxing_participant(QWidget *parent = nullptr);
    ~edit_boxing_participant();
    void set_beforeedit(boxing_participant &);

private slots:
    void on_edit_clicked();

private:
    boxing_participant before_edit;
    boxing_participant after_edit;

    Ui::edit_boxing_participant *ui;
};

#endif // EDIT_BOXING_PARTICIPANT_H
