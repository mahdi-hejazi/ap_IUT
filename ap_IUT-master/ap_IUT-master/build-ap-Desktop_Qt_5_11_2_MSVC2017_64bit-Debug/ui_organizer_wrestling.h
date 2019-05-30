/********************************************************************************
** Form generated from reading UI file 'organizer_wrestling.ui'
**
** Created by: Qt User Interface Compiler version 5.11.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ORGANIZER_WRESTLING_H
#define UI_ORGANIZER_WRESTLING_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_organizer_wrestling
{
public:

    void setupUi(QWidget *organizer_wrestling)
    {
        if (organizer_wrestling->objectName().isEmpty())
            organizer_wrestling->setObjectName(QStringLiteral("organizer_wrestling"));
        organizer_wrestling->resize(400, 300);

        retranslateUi(organizer_wrestling);

        QMetaObject::connectSlotsByName(organizer_wrestling);
    } // setupUi

    void retranslateUi(QWidget *organizer_wrestling)
    {
        organizer_wrestling->setWindowTitle(QApplication::translate("organizer_wrestling", "Form", nullptr));
    } // retranslateUi

};

namespace Ui {
    class organizer_wrestling: public Ui_organizer_wrestling {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ORGANIZER_WRESTLING_H
