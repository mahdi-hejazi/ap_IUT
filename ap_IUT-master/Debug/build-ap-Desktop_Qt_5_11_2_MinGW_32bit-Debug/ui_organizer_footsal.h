/********************************************************************************
** Form generated from reading UI file 'organizer_footsal.ui'
**
** Created by: Qt User Interface Compiler version 5.11.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ORGANIZER_FOOTSAL_H
#define UI_ORGANIZER_FOOTSAL_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_organizer_footsal
{
public:

    void setupUi(QWidget *organizer_footsal)
    {
        if (organizer_footsal->objectName().isEmpty())
            organizer_footsal->setObjectName(QStringLiteral("organizer_footsal"));
        organizer_footsal->resize(400, 300);

        retranslateUi(organizer_footsal);

        QMetaObject::connectSlotsByName(organizer_footsal);
    } // setupUi

    void retranslateUi(QWidget *organizer_footsal)
    {
        organizer_footsal->setWindowTitle(QApplication::translate("organizer_footsal", "Form", nullptr));
    } // retranslateUi

};

namespace Ui {
    class organizer_footsal: public Ui_organizer_footsal {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ORGANIZER_FOOTSAL_H
