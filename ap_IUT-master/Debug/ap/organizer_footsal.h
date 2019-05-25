#ifndef ORGANIZER_FOOTSAL_H
#define ORGANIZER_FOOTSAL_H

#include <QWidget>

namespace Ui {
class organizer_footsal;
}

class organizer_footsal : public QWidget
{
    Q_OBJECT

public:
    explicit organizer_footsal(QWidget *parent = nullptr);
    ~organizer_footsal();

private:
    Ui::organizer_footsal *ui;
};

#endif // ORGANIZER_FOOTSAL_H
