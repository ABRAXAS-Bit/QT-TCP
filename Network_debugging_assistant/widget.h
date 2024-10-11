#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QTcpServer>
#include <QDebug>
#include <QTcpSocket>
#include <QHostAddress>
#include <QTextEdit>
#include <QString>
#include <QList>
#include <QNetworkInterface>
#include <QVector>
#include <QComboBox>
#include <QAbstractSocket>
#include <QIODevice>
#include <QByteArray>
#include <QMessageBox>
#include "client_name_combobox.h"
#include <QTextCharFormat>
#include <QBrush>
#include <QColor>
#include <QTextCursor>

QT_BEGIN_NAMESPACE
namespace Ui { class Widget; }
QT_END_NAMESPACE

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();
    QTcpServer*server;

public slots:
    void on_newconnection();
    void on_readyread(QTcpSocket* connection);
    void on_disconnected();
    void on_statechanged(QAbstractSocket::SocketState socketState);
    void on_clientnamecombobox();

private slots:
    void on_Listening_pushButton_clicked(bool checked);

    void on_Send_pushButton_clicked();

    void on_Client_comboBox_activated(int index);

    void on_Stop_listening_pushButton_clicked();

    void on_Disconnection_pushButton_clicked();

private:
    Ui::Widget *ui;
    int ClientcomboBox_index=NULL;
};
#endif // WIDGET_H
