#ifndef SIGNIN_H
#define SIGNIN_H
#include <QWidget>

namespace Ui {
class signin;
}

class signin : public QWidget
{
    Q_OBJECT

public:
    explicit signin(QWidget *parent = nullptr);
    ~signin();

private slots:
    void on_sabtenam_clicked();

    void on_sabtenam_3_clicked();

    void on_sabtenam_2_clicked();

    void on_sabtenam_4_clicked();

private:
    Ui::signin *ui;
};

#endif // SIGNIN_H
