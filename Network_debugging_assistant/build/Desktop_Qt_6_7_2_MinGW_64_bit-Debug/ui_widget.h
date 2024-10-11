/********************************************************************************
** Form generated from reading UI file 'widget.ui'
**
** Created by: Qt User Interface Compiler version 6.7.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WIDGET_H
#define UI_WIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include <client_name_combobox.h>

QT_BEGIN_NAMESPACE

class Ui_Widget
{
public:
    QWidget *layoutWidget;
    QVBoxLayout *verticalLayout_1;
    QTextEdit *Main_Edit;
    QHBoxLayout *horizontalLayout_1;
    QLabel *Telecom_Label;
    QComboBox *Telecom_comboBox;
    QLabel *IP_address_Label;
    QComboBox *IP_address_comboBox;
    QLabel *Port_number_Lavel;
    QLineEdit *Port_number_Edit;
    QHBoxLayout *horizontalLayout_2;
    QPushButton *Listening_pushButton;
    QPushButton *Stop_listening_pushButton;
    QPushButton *Disconnection_pushButton;
    Client_name_comboBox *Client_comboBox;
    QHBoxLayout *horizontalLayout;
    QTextEdit *Send_textEdit;
    QPushButton *Send_pushButton;

    void setupUi(QWidget *Widget)
    {
        if (Widget->objectName().isEmpty())
            Widget->setObjectName("Widget");
        Widget->resize(515, 418);
        layoutWidget = new QWidget(Widget);
        layoutWidget->setObjectName("layoutWidget");
        layoutWidget->setGeometry(QRect(0, 0, 514, 418));
        verticalLayout_1 = new QVBoxLayout(layoutWidget);
        verticalLayout_1->setSpacing(3);
        verticalLayout_1->setObjectName("verticalLayout_1");
        verticalLayout_1->setSizeConstraint(QLayout::SizeConstraint::SetDefaultConstraint);
        verticalLayout_1->setContentsMargins(3, 3, 3, 3);
        Main_Edit = new QTextEdit(layoutWidget);
        Main_Edit->setObjectName("Main_Edit");
        Main_Edit->setTabStopDistance(80.000000000000000);

        verticalLayout_1->addWidget(Main_Edit);

        horizontalLayout_1 = new QHBoxLayout();
        horizontalLayout_1->setSpacing(0);
        horizontalLayout_1->setObjectName("horizontalLayout_1");
        horizontalLayout_1->setContentsMargins(0, -1, -1, -1);
        Telecom_Label = new QLabel(layoutWidget);
        Telecom_Label->setObjectName("Telecom_Label");
        Telecom_Label->setAlignment(Qt::AlignmentFlag::AlignCenter);

        horizontalLayout_1->addWidget(Telecom_Label);

        Telecom_comboBox = new QComboBox(layoutWidget);
        Telecom_comboBox->addItem(QString());
        Telecom_comboBox->addItem(QString());
        Telecom_comboBox->setObjectName("Telecom_comboBox");

        horizontalLayout_1->addWidget(Telecom_comboBox);

        IP_address_Label = new QLabel(layoutWidget);
        IP_address_Label->setObjectName("IP_address_Label");
        IP_address_Label->setAlignment(Qt::AlignmentFlag::AlignCenter);

        horizontalLayout_1->addWidget(IP_address_Label);

        IP_address_comboBox = new QComboBox(layoutWidget);
        IP_address_comboBox->setObjectName("IP_address_comboBox");

        horizontalLayout_1->addWidget(IP_address_comboBox);

        Port_number_Lavel = new QLabel(layoutWidget);
        Port_number_Lavel->setObjectName("Port_number_Lavel");
        Port_number_Lavel->setAlignment(Qt::AlignmentFlag::AlignCenter);

        horizontalLayout_1->addWidget(Port_number_Lavel);

        Port_number_Edit = new QLineEdit(layoutWidget);
        Port_number_Edit->setObjectName("Port_number_Edit");
        QSizePolicy sizePolicy(QSizePolicy::Policy::Preferred, QSizePolicy::Policy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(Port_number_Edit->sizePolicy().hasHeightForWidth());
        Port_number_Edit->setSizePolicy(sizePolicy);

        horizontalLayout_1->addWidget(Port_number_Edit);


        verticalLayout_1->addLayout(horizontalLayout_1);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(0);
        horizontalLayout_2->setObjectName("horizontalLayout_2");
        Listening_pushButton = new QPushButton(layoutWidget);
        Listening_pushButton->setObjectName("Listening_pushButton");
        Listening_pushButton->setCheckable(true);

        horizontalLayout_2->addWidget(Listening_pushButton);

        Stop_listening_pushButton = new QPushButton(layoutWidget);
        Stop_listening_pushButton->setObjectName("Stop_listening_pushButton");

        horizontalLayout_2->addWidget(Stop_listening_pushButton);

        Disconnection_pushButton = new QPushButton(layoutWidget);
        Disconnection_pushButton->setObjectName("Disconnection_pushButton");

        horizontalLayout_2->addWidget(Disconnection_pushButton);


        verticalLayout_1->addLayout(horizontalLayout_2);

        Client_comboBox = new Client_name_comboBox(layoutWidget);
        Client_comboBox->setObjectName("Client_comboBox");

        verticalLayout_1->addWidget(Client_comboBox);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(0);
        horizontalLayout->setObjectName("horizontalLayout");
        Send_textEdit = new QTextEdit(layoutWidget);
        Send_textEdit->setObjectName("Send_textEdit");

        horizontalLayout->addWidget(Send_textEdit);

        Send_pushButton = new QPushButton(layoutWidget);
        Send_pushButton->setObjectName("Send_pushButton");
        Send_pushButton->setEnabled(true);
        QSizePolicy sizePolicy1(QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Minimum);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(Send_pushButton->sizePolicy().hasHeightForWidth());
        Send_pushButton->setSizePolicy(sizePolicy1);
        Send_pushButton->setIconSize(QSize(10, 10));

        horizontalLayout->addWidget(Send_pushButton);


        verticalLayout_1->addLayout(horizontalLayout);

        verticalLayout_1->setStretch(0, 6);
        verticalLayout_1->setStretch(1, 1);
        verticalLayout_1->setStretch(2, 1);
        verticalLayout_1->setStretch(4, 3);

        retranslateUi(Widget);

        QMetaObject::connectSlotsByName(Widget);
    } // setupUi

    void retranslateUi(QWidget *Widget)
    {
        Widget->setWindowTitle(QCoreApplication::translate("Widget", "\347\275\221\347\273\234\350\260\203\350\257\225\346\234\215\345\212\241\347\253\257", nullptr));
        Telecom_Label->setText(QCoreApplication::translate("Widget", "\351\200\232\344\277\241\345\215\217\350\256\256", nullptr));
        Telecom_comboBox->setItemText(0, QCoreApplication::translate("Widget", "TCP", nullptr));
        Telecom_comboBox->setItemText(1, QCoreApplication::translate("Widget", "UDP", nullptr));

        IP_address_Label->setText(QCoreApplication::translate("Widget", "\346\234\215\345\212\241\345\231\250IP\345\234\260\345\235\200", nullptr));
        Port_number_Lavel->setText(QCoreApplication::translate("Widget", "\347\253\257\345\217\243\345\217\267", nullptr));
        Listening_pushButton->setText(QCoreApplication::translate("Widget", "\347\233\221\345\220\254", nullptr));
        Stop_listening_pushButton->setText(QCoreApplication::translate("Widget", "\345\201\234\346\255\242\347\233\221\345\220\254", nullptr));
        Disconnection_pushButton->setText(QCoreApplication::translate("Widget", "\346\226\255\345\274\200", nullptr));
        Send_pushButton->setText(QCoreApplication::translate("Widget", "\345\217\221\351\200\201", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Widget: public Ui_Widget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WIDGET_H
