/********************************************************************************
** Form generated from reading UI file 'organizer_boxing.ui'
**
** Created by: Qt User Interface Compiler version 5.11.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ORGANIZER_BOXING_H
#define UI_ORGANIZER_BOXING_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_organizer_boxing
{
public:

    void setupUi(QWidget *organizer_boxing)
    {
        if (organizer_boxing->objectName().isEmpty())
            organizer_boxing->setObjectName(QStringLiteral("organizer_boxing"));
        organizer_boxing->resize(400, 300);

        retranslateUi(organizer_boxing);

        QMetaObject::connectSlotsByName(organizer_boxing);
    } // setupUi

    void retranslateUi(QWidget *organizer_boxing)
    {
        organizer_boxing->setWindowTitle(QApplication::translate("organizer_boxing", "Form", nullptr));
    } // retranslateUi

};

namespace Ui {
    class organizer_boxing: public Ui_organizer_boxing {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ORGANIZER_BOXING_H
