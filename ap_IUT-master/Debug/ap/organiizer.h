#ifndef ORGANIIZER_H
#define ORGANIIZER_H

#include <QWidget>

namespace Ui {
class organiizer;
}

class organiizer : public QWidget
{
    Q_OBJECT

public:
    explicit organiizer(QWidget *parent = nullptr);
    ~organiizer();

private:
    Ui::organiizer *ui;
};

#endif // ORGANIIZER_H
