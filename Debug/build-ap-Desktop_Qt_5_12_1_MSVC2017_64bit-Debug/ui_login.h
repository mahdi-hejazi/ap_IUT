/********************************************************************************
** Form generated from reading UI file 'login.ui'
**
** Created by: Qt User Interface Compiler version 5.12.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LOGIN_H
#define UI_LOGIN_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFrame>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_login
{
public:
    QLineEdit *lineEdit;
    QLineEdit *lineEdit_2;
    QFrame *varzesh;
    QRadioButton *coshti;
    QRadioButton *footsal;
    QRadioButton *box;
    QLabel *label;
    QFrame *jayegah;
    QRadioButton *modir;
    QRadioButton *varzeshcar;
    QLabel *label_2;
    QPushButton *ok;

    void setupUi(QWidget *login)
    {
        if (login->objectName().isEmpty())
            login->setObjectName(QString::fromUtf8("login"));
        login->resize(702, 413);
        lineEdit = new QLineEdit(login);
        lineEdit->setObjectName(QString::fromUtf8("lineEdit"));
        lineEdit->setGeometry(QRect(90, 80, 111, 20));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(lineEdit->sizePolicy().hasHeightForWidth());
        lineEdit->setSizePolicy(sizePolicy);
        lineEdit->setFocusPolicy(Qt::NoFocus);
        lineEdit_2 = new QLineEdit(login);
        lineEdit_2->setObjectName(QString::fromUtf8("lineEdit_2"));
        lineEdit_2->setGeometry(QRect(90, 130, 111, 21));
        sizePolicy.setHeightForWidth(lineEdit_2->sizePolicy().hasHeightForWidth());
        lineEdit_2->setSizePolicy(sizePolicy);
        lineEdit_2->setEchoMode(QLineEdit::Password);
        varzesh = new QFrame(login);
        varzesh->setObjectName(QString::fromUtf8("varzesh"));
        varzesh->setGeometry(QRect(30, 240, 391, 151));
        sizePolicy.setHeightForWidth(varzesh->sizePolicy().hasHeightForWidth());
        varzesh->setSizePolicy(sizePolicy);
        varzesh->setFrameShape(QFrame::StyledPanel);
        varzesh->setFrameShadow(QFrame::Raised);
        coshti = new QRadioButton(varzesh);
        coshti->setObjectName(QString::fromUtf8("coshti"));
        coshti->setGeometry(QRect(150, 120, 95, 20));
        sizePolicy.setHeightForWidth(coshti->sizePolicy().hasHeightForWidth());
        coshti->setSizePolicy(sizePolicy);
        footsal = new QRadioButton(varzesh);
        footsal->setObjectName(QString::fromUtf8("footsal"));
        footsal->setGeometry(QRect(270, 120, 91, 21));
        sizePolicy.setHeightForWidth(footsal->sizePolicy().hasHeightForWidth());
        footsal->setSizePolicy(sizePolicy);
        box = new QRadioButton(varzesh);
        box->setObjectName(QString::fromUtf8("box"));
        box->setGeometry(QRect(20, 120, 95, 20));
        sizePolicy.setHeightForWidth(box->sizePolicy().hasHeightForWidth());
        box->setSizePolicy(sizePolicy);
        label = new QLabel(varzesh);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(230, 60, 101, 31));
        jayegah = new QFrame(login);
        jayegah->setObjectName(QString::fromUtf8("jayegah"));
        jayegah->setGeometry(QRect(330, 60, 241, 141));
        jayegah->setFrameShape(QFrame::StyledPanel);
        jayegah->setFrameShadow(QFrame::Raised);
        modir = new QRadioButton(jayegah);
        modir->setObjectName(QString::fromUtf8("modir"));
        modir->setGeometry(QRect(20, 60, 95, 20));
        varzeshcar = new QRadioButton(jayegah);
        varzeshcar->setObjectName(QString::fromUtf8("varzeshcar"));
        varzeshcar->setGeometry(QRect(20, 100, 95, 20));
        label_2 = new QLabel(jayegah);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(14, 10, 111, 31));
        ok = new QPushButton(login);
        ok->setObjectName(QString::fromUtf8("ok"));
        ok->setGeometry(QRect(82, 190, 121, 31));

        retranslateUi(login);

        QMetaObject::connectSlotsByName(login);
    } // setupUi

    void retranslateUi(QWidget *login)
    {
        login->setWindowTitle(QApplication::translate("login", "Form", nullptr));
        lineEdit->setText(QString());
        lineEdit->setPlaceholderText(QApplication::translate("login", "\331\206\330\247\331\205 \332\251\330\247\330\261\330\250\330\261\333\214", nullptr));
        lineEdit_2->setPlaceholderText(QApplication::translate("login", "\330\261\331\205\330\262 \330\271\330\250\331\210\330\261", nullptr));
        coshti->setText(QApplication::translate("login", "\332\251\330\264\330\252\333\214", nullptr));
        footsal->setText(QApplication::translate("login", "\331\201\331\210\330\252\330\263\330\247\331\204", nullptr));
        box->setText(QApplication::translate("login", "\330\250\331\210\332\251\330\263", nullptr));
        label->setText(QApplication::translate("login", "\332\251\330\257\331\210\331\205 \331\210\330\261\330\262\330\264\330\237", nullptr));
        modir->setText(QApplication::translate("login", "\331\205\330\257\333\214\330\261 \331\210\330\261\330\262\330\264", nullptr));
        varzeshcar->setText(QApplication::translate("login", "\331\210\330\261\330\262\330\264\332\251\330\247\330\261", nullptr));
        label_2->setText(QApplication::translate("login", "\330\254\330\247\333\214\332\257\330\247\331\207\330\237 ", nullptr));
        ok->setText(QApplication::translate("login", "\331\210\330\261\331\210\330\257", nullptr));
    } // retranslateUi

};

namespace Ui {
    class login: public Ui_login {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LOGIN_H
