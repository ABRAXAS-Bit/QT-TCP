#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QTcpSocket>
#include <QAbstractSocket>
#include <QHostAddress>
#include <QString>
#include <QIODeviceBase>
#include <QDebug>
#include <QTimer>

QT_BEGIN_NAMESPACE
namespace Ui {
class Widget;
}
QT_END_NAMESPACE

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();

private slots:
    void on_Connect_pushButton_clicked();

    void on_Disconnect_pushButton_clicked();

    void on_Send_pushButton_clicked();

    void Read_all();

    void on_Disconnected();

    void on_Connected_success();

    void on_Error(QAbstractSocket::SocketError socketError);

    void on_Time_out();

private:
    Ui::Widget *ui;
    QTcpSocket*connection;
    QTimer*timer;
};
#endif // WIDGET_H
