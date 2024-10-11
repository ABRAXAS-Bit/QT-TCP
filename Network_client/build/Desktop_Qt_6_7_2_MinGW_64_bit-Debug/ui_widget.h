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
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Widget
{
public:
    QWidget *widget;
    QVBoxLayout *verticalLayout;
    QTextEdit *Receive_textEdit;
    QHBoxLayout *horizontalLayout_middle;
    QLabel *IP_address_label;
    QLineEdit *IP_address_lineEdit;
    QLabel *Port_label;
    QLineEdit *Port_lineEdit;
    QPushButton *Connect_pushButton;
    QPushButton *Disconnect_pushButton;
    QHBoxLayout *horizontalLayout_bottom;
    QTextEdit *Send_textEdit;
    QPushButton *Send_pushButton;

    void setupUi(QWidget *Widget)
    {
        if (Widget->objectName().isEmpty())
            Widget->setObjectName("Widget");
        Widget->resize(532, 416);
        widget = new QWidget(Widget);
        widget->setObjectName("widget");
        widget->setGeometry(QRect(0, 0, 531, 417));
        verticalLayout = new QVBoxLayout(widget);
        verticalLayout->setSpacing(2);
        verticalLayout->setObjectName("verticalLayout");
        verticalLayout->setContentsMargins(1, 1, 1, 1);
        Receive_textEdit = new QTextEdit(widget);
        Receive_textEdit->setObjectName("Receive_textEdit");

        verticalLayout->addWidget(Receive_textEdit);

        horizontalLayout_middle = new QHBoxLayout();
        horizontalLayout_middle->setSpacing(2);
        horizontalLayout_middle->setObjectName("horizontalLayout_middle");
        IP_address_label = new QLabel(widget);
        IP_address_label->setObjectName("IP_address_label");

        horizontalLayout_middle->addWidget(IP_address_label);

        IP_address_lineEdit = new QLineEdit(widget);
        IP_address_lineEdit->setObjectName("IP_address_lineEdit");

        horizontalLayout_middle->addWidget(IP_address_lineEdit);

        Port_label = new QLabel(widget);
        Port_label->setObjectName("Port_label");

        horizontalLayout_middle->addWidget(Port_label);

        Port_lineEdit = new QLineEdit(widget);
        Port_lineEdit->setObjectName("Port_lineEdit");

        horizontalLayout_middle->addWidget(Port_lineEdit);

        Connect_pushButton = new QPushButton(widget);
        Connect_pushButton->setObjectName("Connect_pushButton");

        horizontalLayout_middle->addWidget(Connect_pushButton);

        Disconnect_pushButton = new QPushButton(widget);
        Disconnect_pushButton->setObjectName("Disconnect_pushButton");

        horizontalLayout_middle->addWidget(Disconnect_pushButton);


        verticalLayout->addLayout(horizontalLayout_middle);

        horizontalLayout_bottom = new QHBoxLayout();
        horizontalLayout_bottom->setSpacing(2);
        horizontalLayout_bottom->setObjectName("horizontalLayout_bottom");
        Send_textEdit = new QTextEdit(widget);
        Send_textEdit->setObjectName("Send_textEdit");

        horizontalLayout_bottom->addWidget(Send_textEdit);

        Send_pushButton = new QPushButton(widget);
        Send_pushButton->setObjectName("Send_pushButton");
        QSizePolicy sizePolicy(QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(Send_pushButton->sizePolicy().hasHeightForWidth());
        Send_pushButton->setSizePolicy(sizePolicy);

        horizontalLayout_bottom->addWidget(Send_pushButton);


        verticalLayout->addLayout(horizontalLayout_bottom);

        verticalLayout->setStretch(0, 4);
        verticalLayout->setStretch(2, 2);

        retranslateUi(Widget);

        QMetaObject::connectSlotsByName(Widget);
    } // setupUi

    void retranslateUi(QWidget *Widget)
    {
        Widget->setWindowTitle(QCoreApplication::translate("Widget", "\347\275\221\347\273\234\350\260\203\350\257\225\345\256\242\346\210\267\347\253\257", nullptr));
        IP_address_label->setText(QCoreApplication::translate("Widget", "\346\234\215\345\212\241\347\253\257IP\345\234\260\345\235\200", nullptr));
        Port_label->setText(QCoreApplication::translate("Widget", "\346\234\215\345\212\241\347\253\257\347\253\257\345\217\243\345\217\267", nullptr));
        Connect_pushButton->setText(QCoreApplication::translate("Widget", "\350\277\236\346\216\245", nullptr));
        Disconnect_pushButton->setText(QCoreApplication::translate("Widget", "\346\226\255\345\274\200", nullptr));
        Send_pushButton->setText(QCoreApplication::translate("Widget", "\345\217\221\351\200\201", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Widget: public Ui_Widget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WIDGET_H
