/********************************************************************************
** Form generated from reading UI file 'signin.ui'
**
** Created by: Qt User Interface Compiler version 5.11.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SIGNIN_H
#define UI_SIGNIN_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFrame>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_signin
{
public:
    QLineEdit *lineEdit;
    QLineEdit *lineEdit_2;
    QLineEdit *lineEdit_3;
    QLineEdit *lineEdit_4;
    QFrame *frame;
    QRadioButton *footsal;
    QRadioButton *koshti;
    QRadioButton *box;
    QLabel *label;

    void setupUi(QWidget *signin)
    {
        if (signin->objectName().isEmpty())
            signin->setObjectName(QStringLiteral("signin"));
        signin->resize(400, 300);
        lineEdit = new QLineEdit(signin);
        lineEdit->setObjectName(QStringLiteral("lineEdit"));
        lineEdit->setGeometry(QRect(50, 40, 113, 20));
        lineEdit_2 = new QLineEdit(signin);
        lineEdit_2->setObjectName(QStringLiteral("lineEdit_2"));
        lineEdit_2->setGeometry(QRect(50, 70, 113, 20));
        lineEdit_3 = new QLineEdit(signin);
        lineEdit_3->setObjectName(QStringLiteral("lineEdit_3"));
        lineEdit_3->setGeometry(QRect(50, 100, 113, 20));
        lineEdit_4 = new QLineEdit(signin);
        lineEdit_4->setObjectName(QStringLiteral("lineEdit_4"));
        lineEdit_4->setGeometry(QRect(50, 130, 113, 20));
        frame = new QFrame(signin);
        frame->setObjectName(QStringLiteral("frame"));
        frame->setGeometry(QRect(260, 60, 120, 80));
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setFrameShadow(QFrame::Raised);
        footsal = new QRadioButton(frame);
        footsal->setObjectName(QStringLiteral("footsal"));
        footsal->setGeometry(QRect(20, 10, 82, 17));
        koshti = new QRadioButton(frame);
        koshti->setObjectName(QStringLiteral("koshti"));
        koshti->setGeometry(QRect(20, 30, 82, 17));
        box = new QRadioButton(frame);
        box->setObjectName(QStringLiteral("box"));
        box->setGeometry(QRect(20, 50, 82, 17));
        label = new QLabel(signin);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(270, 20, 101, 31));

        retranslateUi(signin);

        QMetaObject::connectSlotsByName(signin);
    } // setupUi

    void retranslateUi(QWidget *signin)
    {
        signin->setWindowTitle(QApplication::translate("signin", "Form", nullptr));
        lineEdit->setPlaceholderText(QApplication::translate("signin", "\331\206\330\247\331\205 \332\251\330\247\330\261\330\250\330\261\333\214 ", nullptr));
        lineEdit_2->setPlaceholderText(QApplication::translate("signin", "\330\261\331\205\330\262 \330\271\330\250\331\210\330\261", nullptr));
        lineEdit_3->setPlaceholderText(QApplication::translate("signin", "@gmail.com", nullptr));
        lineEdit_4->setPlaceholderText(QApplication::translate("signin", "\331\206\330\247\331\205 \330\252\333\214\331\205", nullptr));
        footsal->setText(QApplication::translate("signin", "\331\201\331\210\330\252\330\263\330\247\331\204", nullptr));
        koshti->setText(QApplication::translate("signin", "\332\251\330\264\330\252\333\214 ", nullptr));
        box->setText(QApplication::translate("signin", "\330\250\331\210\332\251\330\263", nullptr));
        label->setText(QApplication::translate("signin", "\330\252\333\214\331\205\330\237", nullptr));
    } // retranslateUi

};

namespace Ui {
    class signin: public Ui_signin {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SIGNIN_H
