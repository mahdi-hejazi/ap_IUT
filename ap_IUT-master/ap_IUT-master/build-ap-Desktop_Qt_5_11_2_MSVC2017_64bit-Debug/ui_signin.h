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
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_signin
{
public:
    QVBoxLayout *verticalLayout_2;
    QTabWidget *tabWidget;
    QWidget *footsal;
    QWidget *verticalLayoutWidget;
    QVBoxLayout *verticalLayout_3;
    QLineEdit *pass_3;
    QLineEdit *usename_3;
    QLineEdit *email_3;
    QLineEdit *team_name_3;
    QPushButton *sabtenam_3;
    QWidget *formLayoutWidget_3;
    QFormLayout *formLayout_3;
    QLineEdit *codemeli1;
    QLineEdit *name1;
    QLineEdit *codemeli2;
    QLineEdit *name2;
    QLineEdit *codemeli3;
    QLineEdit *name3;
    QLineEdit *codemeli4;
    QLineEdit *name4;
    QLineEdit *codemeli5;
    QLineEdit *name5;
    QLineEdit *codemeli6;
    QLineEdit *name6;
    QLineEdit *codemeli7;
    QLineEdit *name7;
    QLineEdit *codemeli8;
    QLineEdit *name8;
    QLineEdit *codemeli9;
    QLineEdit *name9;
    QLineEdit *codemeli10;
    QLineEdit *name10;
    QWidget *wresteling;
    QPushButton *sabtenam_2;
    QWidget *formLayoutWidget_2;
    QFormLayout *formLayout_2;
    QLineEdit *code_meli;
    QLineEdit *name;
    QWidget *widget;
    QVBoxLayout *verticalLayout;
    QLineEdit *usename_2;
    QLineEdit *pass_2;
    QLineEdit *email_2;
    QLineEdit *team_name_2;
    QWidget *boxing;
    QWidget *gridLayoutWidget;
    QGridLayout *gridLayout_2;
    QLineEdit *usename;
    QLineEdit *pass;
    QLineEdit *email;
    QLineEdit *team_name;
    QPushButton *sabtenam_4;
    QWidget *formLayoutWidget_7;
    QFormLayout *formLayout_8;
    QLineEdit *code_meli_2;
    QLineEdit *name_2;
    QLabel *label;

    void setupUi(QWidget *signin)
    {
        if (signin->objectName().isEmpty())
            signin->setObjectName(QStringLiteral("signin"));
        signin->resize(912, 571);
        verticalLayout_2 = new QVBoxLayout(signin);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        tabWidget = new QTabWidget(signin);
        tabWidget->setObjectName(QStringLiteral("tabWidget"));
        tabWidget->setDocumentMode(true);
        footsal = new QWidget();
        footsal->setObjectName(QStringLiteral("footsal"));
        verticalLayoutWidget = new QWidget(footsal);
        verticalLayoutWidget->setObjectName(QStringLiteral("verticalLayoutWidget"));
        verticalLayoutWidget->setGeometry(QRect(50, 30, 160, 221));
        verticalLayout_3 = new QVBoxLayout(verticalLayoutWidget);
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        verticalLayout_3->setContentsMargins(0, 0, 0, 0);
        pass_3 = new QLineEdit(verticalLayoutWidget);
        pass_3->setObjectName(QStringLiteral("pass_3"));

        verticalLayout_3->addWidget(pass_3);

        usename_3 = new QLineEdit(verticalLayoutWidget);
        usename_3->setObjectName(QStringLiteral("usename_3"));

        verticalLayout_3->addWidget(usename_3);

        email_3 = new QLineEdit(verticalLayoutWidget);
        email_3->setObjectName(QStringLiteral("email_3"));

        verticalLayout_3->addWidget(email_3);

        team_name_3 = new QLineEdit(verticalLayoutWidget);
        team_name_3->setObjectName(QStringLiteral("team_name_3"));

        verticalLayout_3->addWidget(team_name_3);

        sabtenam_3 = new QPushButton(footsal);
        sabtenam_3->setObjectName(QStringLiteral("sabtenam_3"));
        sabtenam_3->setGeometry(QRect(80, 350, 158, 28));
        formLayoutWidget_3 = new QWidget(footsal);
        formLayoutWidget_3->setObjectName(QStringLiteral("formLayoutWidget_3"));
        formLayoutWidget_3->setGeometry(QRect(350, 30, 281, 291));
        formLayout_3 = new QFormLayout(formLayoutWidget_3);
        formLayout_3->setObjectName(QStringLiteral("formLayout_3"));
        formLayout_3->setContentsMargins(0, 0, 0, 0);
        codemeli1 = new QLineEdit(formLayoutWidget_3);
        codemeli1->setObjectName(QStringLiteral("codemeli1"));

        formLayout_3->setWidget(0, QFormLayout::LabelRole, codemeli1);

        name1 = new QLineEdit(formLayoutWidget_3);
        name1->setObjectName(QStringLiteral("name1"));

        formLayout_3->setWidget(0, QFormLayout::FieldRole, name1);

        codemeli2 = new QLineEdit(formLayoutWidget_3);
        codemeli2->setObjectName(QStringLiteral("codemeli2"));

        formLayout_3->setWidget(1, QFormLayout::LabelRole, codemeli2);

        name2 = new QLineEdit(formLayoutWidget_3);
        name2->setObjectName(QStringLiteral("name2"));

        formLayout_3->setWidget(1, QFormLayout::FieldRole, name2);

        codemeli3 = new QLineEdit(formLayoutWidget_3);
        codemeli3->setObjectName(QStringLiteral("codemeli3"));

        formLayout_3->setWidget(2, QFormLayout::LabelRole, codemeli3);

        name3 = new QLineEdit(formLayoutWidget_3);
        name3->setObjectName(QStringLiteral("name3"));

        formLayout_3->setWidget(2, QFormLayout::FieldRole, name3);

        codemeli4 = new QLineEdit(formLayoutWidget_3);
        codemeli4->setObjectName(QStringLiteral("codemeli4"));

        formLayout_3->setWidget(3, QFormLayout::LabelRole, codemeli4);

        name4 = new QLineEdit(formLayoutWidget_3);
        name4->setObjectName(QStringLiteral("name4"));

        formLayout_3->setWidget(3, QFormLayout::FieldRole, name4);

        codemeli5 = new QLineEdit(formLayoutWidget_3);
        codemeli5->setObjectName(QStringLiteral("codemeli5"));

        formLayout_3->setWidget(4, QFormLayout::LabelRole, codemeli5);

        name5 = new QLineEdit(formLayoutWidget_3);
        name5->setObjectName(QStringLiteral("name5"));

        formLayout_3->setWidget(4, QFormLayout::FieldRole, name5);

        codemeli6 = new QLineEdit(formLayoutWidget_3);
        codemeli6->setObjectName(QStringLiteral("codemeli6"));

        formLayout_3->setWidget(5, QFormLayout::LabelRole, codemeli6);

        name6 = new QLineEdit(formLayoutWidget_3);
        name6->setObjectName(QStringLiteral("name6"));

        formLayout_3->setWidget(5, QFormLayout::FieldRole, name6);

        codemeli7 = new QLineEdit(formLayoutWidget_3);
        codemeli7->setObjectName(QStringLiteral("codemeli7"));

        formLayout_3->setWidget(6, QFormLayout::LabelRole, codemeli7);

        name7 = new QLineEdit(formLayoutWidget_3);
        name7->setObjectName(QStringLiteral("name7"));

        formLayout_3->setWidget(6, QFormLayout::FieldRole, name7);

        codemeli8 = new QLineEdit(formLayoutWidget_3);
        codemeli8->setObjectName(QStringLiteral("codemeli8"));

        formLayout_3->setWidget(7, QFormLayout::LabelRole, codemeli8);

        name8 = new QLineEdit(formLayoutWidget_3);
        name8->setObjectName(QStringLiteral("name8"));

        formLayout_3->setWidget(7, QFormLayout::FieldRole, name8);

        codemeli9 = new QLineEdit(formLayoutWidget_3);
        codemeli9->setObjectName(QStringLiteral("codemeli9"));

        formLayout_3->setWidget(8, QFormLayout::LabelRole, codemeli9);

        name9 = new QLineEdit(formLayoutWidget_3);
        name9->setObjectName(QStringLiteral("name9"));

        formLayout_3->setWidget(8, QFormLayout::FieldRole, name9);

        codemeli10 = new QLineEdit(formLayoutWidget_3);
        codemeli10->setObjectName(QStringLiteral("codemeli10"));

        formLayout_3->setWidget(9, QFormLayout::LabelRole, codemeli10);

        name10 = new QLineEdit(formLayoutWidget_3);
        name10->setObjectName(QStringLiteral("name10"));

        formLayout_3->setWidget(9, QFormLayout::FieldRole, name10);

        tabWidget->addTab(footsal, QString());
        wresteling = new QWidget();
        wresteling->setObjectName(QStringLiteral("wresteling"));
        sabtenam_2 = new QPushButton(wresteling);
        sabtenam_2->setObjectName(QStringLiteral("sabtenam_2"));
        sabtenam_2->setGeometry(QRect(170, 290, 137, 28));
        formLayoutWidget_2 = new QWidget(wresteling);
        formLayoutWidget_2->setObjectName(QStringLiteral("formLayoutWidget_2"));
        formLayoutWidget_2->setGeometry(QRect(350, 90, 283, 24));
        formLayout_2 = new QFormLayout(formLayoutWidget_2);
        formLayout_2->setObjectName(QStringLiteral("formLayout_2"));
        formLayout_2->setSizeConstraint(QLayout::SetDefaultConstraint);
        formLayout_2->setFieldGrowthPolicy(QFormLayout::AllNonFixedFieldsGrow);
        formLayout_2->setRowWrapPolicy(QFormLayout::DontWrapRows);
        formLayout_2->setContentsMargins(0, 0, 0, 0);
        code_meli = new QLineEdit(formLayoutWidget_2);
        code_meli->setObjectName(QStringLiteral("code_meli"));

        formLayout_2->setWidget(0, QFormLayout::LabelRole, code_meli);

        name = new QLineEdit(formLayoutWidget_2);
        name->setObjectName(QStringLiteral("name"));

        formLayout_2->setWidget(0, QFormLayout::FieldRole, name);

        widget = new QWidget(wresteling);
        widget->setObjectName(QStringLiteral("widget"));
        widget->setGeometry(QRect(30, 30, 139, 146));
        verticalLayout = new QVBoxLayout(widget);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        usename_2 = new QLineEdit(widget);
        usename_2->setObjectName(QStringLiteral("usename_2"));

        verticalLayout->addWidget(usename_2);

        pass_2 = new QLineEdit(widget);
        pass_2->setObjectName(QStringLiteral("pass_2"));

        verticalLayout->addWidget(pass_2);

        email_2 = new QLineEdit(widget);
        email_2->setObjectName(QStringLiteral("email_2"));

        verticalLayout->addWidget(email_2);

        team_name_2 = new QLineEdit(widget);
        team_name_2->setObjectName(QStringLiteral("team_name_2"));

        verticalLayout->addWidget(team_name_2);

        tabWidget->addTab(wresteling, QString());
        boxing = new QWidget();
        boxing->setObjectName(QStringLiteral("boxing"));
        gridLayoutWidget = new QWidget(boxing);
        gridLayoutWidget->setObjectName(QStringLiteral("gridLayoutWidget"));
        gridLayoutWidget->setGeometry(QRect(10, 10, 181, 241));
        gridLayout_2 = new QGridLayout(gridLayoutWidget);
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        gridLayout_2->setContentsMargins(0, 0, 0, 0);
        usename = new QLineEdit(gridLayoutWidget);
        usename->setObjectName(QStringLiteral("usename"));

        gridLayout_2->addWidget(usename, 0, 0, 1, 1);

        pass = new QLineEdit(gridLayoutWidget);
        pass->setObjectName(QStringLiteral("pass"));

        gridLayout_2->addWidget(pass, 1, 0, 1, 1);

        email = new QLineEdit(gridLayoutWidget);
        email->setObjectName(QStringLiteral("email"));

        gridLayout_2->addWidget(email, 2, 0, 1, 1);

        team_name = new QLineEdit(gridLayoutWidget);
        team_name->setObjectName(QStringLiteral("team_name"));

        gridLayout_2->addWidget(team_name, 3, 0, 1, 1);

        sabtenam_4 = new QPushButton(boxing);
        sabtenam_4->setObjectName(QStringLiteral("sabtenam_4"));
        sabtenam_4->setGeometry(QRect(220, 320, 137, 28));
        formLayoutWidget_7 = new QWidget(boxing);
        formLayoutWidget_7->setObjectName(QStringLiteral("formLayoutWidget_7"));
        formLayoutWidget_7->setGeometry(QRect(392, 70, 291, 71));
        formLayout_8 = new QFormLayout(formLayoutWidget_7);
        formLayout_8->setObjectName(QStringLiteral("formLayout_8"));
        formLayout_8->setSizeConstraint(QLayout::SetDefaultConstraint);
        formLayout_8->setFieldGrowthPolicy(QFormLayout::AllNonFixedFieldsGrow);
        formLayout_8->setRowWrapPolicy(QFormLayout::DontWrapRows);
        formLayout_8->setContentsMargins(0, 0, 0, 0);
        code_meli_2 = new QLineEdit(formLayoutWidget_7);
        code_meli_2->setObjectName(QStringLiteral("code_meli_2"));

        formLayout_8->setWidget(0, QFormLayout::LabelRole, code_meli_2);

        name_2 = new QLineEdit(formLayoutWidget_7);
        name_2->setObjectName(QStringLiteral("name_2"));

        formLayout_8->setWidget(0, QFormLayout::FieldRole, name_2);

        tabWidget->addTab(boxing, QString());

        verticalLayout_2->addWidget(tabWidget);

        label = new QLabel(signin);
        label->setObjectName(QStringLiteral("label"));

        verticalLayout_2->addWidget(label);


        retranslateUi(signin);

        tabWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(signin);
    } // setupUi

    void retranslateUi(QWidget *signin)
    {
        signin->setWindowTitle(QApplication::translate("signin", "Form", nullptr));
        pass_3->setPlaceholderText(QApplication::translate("signin", "\330\261\331\205\330\262 \330\271\330\250\331\210\330\261", nullptr));
        usename_3->setPlaceholderText(QApplication::translate("signin", "\331\206\330\247\331\205 \332\251\330\247\330\261\330\250\330\261\333\214 ", nullptr));
        email_3->setPlaceholderText(QApplication::translate("signin", "@gmail.com", nullptr));
        team_name_3->setPlaceholderText(QApplication::translate("signin", "\331\206\330\247\331\205 \330\252\333\214\331\205", nullptr));
        sabtenam_3->setText(QApplication::translate("signin", "\330\253\330\250\330\252 \331\206\330\247\331\205", nullptr));
        codemeli1->setText(QString());
        codemeli1->setPlaceholderText(QApplication::translate("signin", "\332\251\330\257 \331\205\331\204\333\214", nullptr));
        name1->setPlaceholderText(QApplication::translate("signin", "\331\206\330\247\331\205 \330\250\330\247\330\262\333\214\332\251\331\206", nullptr));
        codemeli2->setText(QString());
        codemeli2->setPlaceholderText(QApplication::translate("signin", "\332\251\330\257 \331\205\331\204\333\214", nullptr));
        name2->setPlaceholderText(QApplication::translate("signin", "\331\206\330\247\331\205 \330\250\330\247\330\262\333\214\332\251\331\206", nullptr));
        codemeli3->setText(QString());
        codemeli3->setPlaceholderText(QApplication::translate("signin", "\332\251\330\257 \331\205\331\204\333\214", nullptr));
        name3->setPlaceholderText(QApplication::translate("signin", "\331\206\330\247\331\205 \330\250\330\247\330\262\333\214\332\251\331\206", nullptr));
        codemeli4->setText(QString());
        codemeli4->setPlaceholderText(QApplication::translate("signin", "\332\251\330\257 \331\205\331\204\333\214", nullptr));
        name4->setPlaceholderText(QApplication::translate("signin", "\331\206\330\247\331\205 \330\250\330\247\330\262\333\214\332\251\331\206", nullptr));
        codemeli5->setText(QString());
        codemeli5->setPlaceholderText(QApplication::translate("signin", "\332\251\330\257 \331\205\331\204\333\214", nullptr));
        name5->setPlaceholderText(QApplication::translate("signin", "\331\206\330\247\331\205 \330\250\330\247\330\262\333\214\332\251\331\206", nullptr));
        codemeli6->setText(QString());
        codemeli6->setPlaceholderText(QApplication::translate("signin", "\332\251\330\257 \331\205\331\204\333\214", nullptr));
        name6->setPlaceholderText(QApplication::translate("signin", "\331\206\330\247\331\205 \330\250\330\247\330\262\333\214\332\251\331\206", nullptr));
        codemeli7->setText(QString());
        codemeli7->setPlaceholderText(QApplication::translate("signin", "\332\251\330\257 \331\205\331\204\333\214", nullptr));
        name7->setPlaceholderText(QApplication::translate("signin", "\331\206\330\247\331\205 \330\250\330\247\330\262\333\214\332\251\331\206", nullptr));
        codemeli8->setText(QString());
        codemeli8->setPlaceholderText(QApplication::translate("signin", "\332\251\330\257 \331\205\331\204\333\214", nullptr));
        name8->setPlaceholderText(QApplication::translate("signin", "\331\206\330\247\331\205 \330\250\330\247\330\262\333\214\332\251\331\206", nullptr));
        codemeli9->setText(QString());
        codemeli9->setPlaceholderText(QApplication::translate("signin", "\332\251\330\257 \331\205\331\204\333\214", nullptr));
        name9->setPlaceholderText(QApplication::translate("signin", "\331\206\330\247\331\205 \330\250\330\247\330\262\333\214\332\251\331\206", nullptr));
        codemeli10->setText(QString());
        codemeli10->setPlaceholderText(QApplication::translate("signin", "\332\251\330\257 \331\205\331\204\333\214", nullptr));
        name10->setPlaceholderText(QApplication::translate("signin", "\331\206\330\247\331\205 \330\250\330\247\330\262\333\214\332\251\331\206", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(footsal), QApplication::translate("signin", "\331\201\331\210\330\252\330\263\330\247\331\204", nullptr));
        sabtenam_2->setText(QApplication::translate("signin", "\330\253\330\250\330\252 \331\206\330\247\331\205", nullptr));
        code_meli->setText(QString());
        code_meli->setPlaceholderText(QApplication::translate("signin", "\332\251\330\257 \331\205\331\204\333\214", nullptr));
        name->setPlaceholderText(QApplication::translate("signin", "\331\206\330\247\331\205 \331\210\330\261\330\262\330\264\332\251\330\247\330\261", nullptr));
        usename_2->setPlaceholderText(QApplication::translate("signin", "\331\206\330\247\331\205 \332\251\330\247\330\261\330\250\330\261\333\214 ", nullptr));
        pass_2->setPlaceholderText(QApplication::translate("signin", "\330\261\331\205\330\262 \330\271\330\250\331\210\330\261", nullptr));
        email_2->setPlaceholderText(QApplication::translate("signin", "@gmail.com", nullptr));
        team_name_2->setPlaceholderText(QApplication::translate("signin", "\331\206\330\247\331\205 \330\252\333\214\331\205", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(wresteling), QApplication::translate("signin", "\332\251\330\264\330\252\333\214", nullptr));
        usename->setPlaceholderText(QApplication::translate("signin", "\331\206\330\247\331\205 \332\251\330\247\330\261\330\250\330\261\333\214 ", nullptr));
        pass->setPlaceholderText(QApplication::translate("signin", "\330\261\331\205\330\262 \330\271\330\250\331\210\330\261", nullptr));
        email->setPlaceholderText(QApplication::translate("signin", "@gmail.com", nullptr));
        team_name->setPlaceholderText(QApplication::translate("signin", "\331\206\330\247\331\205 \330\252\333\214\331\205", nullptr));
        sabtenam_4->setText(QApplication::translate("signin", "\330\253\330\250\330\252 \331\206\330\247\331\205", nullptr));
        code_meli_2->setText(QString());
        code_meli_2->setPlaceholderText(QApplication::translate("signin", "\332\251\330\257 \331\205\331\204\333\214", nullptr));
        name_2->setPlaceholderText(QApplication::translate("signin", "\331\206\330\247\331\205 \331\210\330\261\330\262\330\264\332\251\330\247\330\261", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(boxing), QApplication::translate("signin", "\330\250\331\210\332\251\330\263", nullptr));
        label->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class signin: public Ui_signin {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SIGNIN_H
