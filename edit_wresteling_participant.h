#ifndef EDIT_WRESTELING_PARTICIPANT_H
#define EDIT_WRESTELING_PARTICIPANT_H

#include <QWidget>
#include "wresteling_participant.h"
namespace Ui {
class edit_wresteling_participant;
}

class edit_wresteling_participant : public QWidget
{
    Q_OBJECT

public:
    void set_beforeedit( wresteling_participant&);
    explicit edit_wresteling_participant(QWidget *parent = nullptr);
    ~edit_wresteling_participant();

private slots:
    void on_edit_clicked();

private:
    wresteling_participant before_edit;
    wresteling_participant after_edit;
    Ui::edit_wresteling_participant *ui;
};

#endif // EDIT_WRESTELING_PARTICIPANT_H
