#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    this->setLayout(ui->verticalLayout);
    connection = new QTcpSocket(this);
    timer = new QTimer(this);
    connect(connection,SIGNAL(readyRead()),this,SLOT(Read_all()));
    connect(connection,SIGNAL(disconnected()),this,SLOT(on_Disconnected()));
    connect(timer,&QTimer::timeout,this,&Widget::on_Time_out);
    connect(connection,&QTcpSocket::connected,this,&Widget::on_Connected_success);
    connect(connection,&QTcpSocket::errorOccurred,this,&Widget::on_Error);
    ui->Disconnect_pushButton->setEnabled(false);
    ui->Send_pushButton->setEnabled(false);
    ui->Send_textEdit->setEnabled(false);
    ui->Receive_textEdit->setReadOnly(true);
}

Widget::~Widget()
{
    delete ui;
}

void Widget::on_Connect_pushButton_clicked()
{
    qDebug()<<"Connect ready";
    timer->setSingleShot(true);
    timer->setInterval(5000);
    QHostAddress ip_address(ui->IP_address_lineEdit->text());
    connection->QAbstractSocket::connectToHost(ip_address,ui->Port_lineEdit->text().toUShort());
    this->setEnabled(false);
    timer->start();
}


void Widget::on_Disconnect_pushButton_clicked()
{
    qDebug()<<"Disconnect ready";
    connection->disconnectFromHost();
    ui->Receive_textEdit->insertPlainText("断开连接\n");
    ui->Connect_pushButton->setEnabled(true);
    ui->Disconnect_pushButton->setEnabled(false);
    ui->Send_textEdit->setEnabled(false);
    ui->Send_pushButton->setEnabled(false);
    ui->IP_address_lineEdit->setEnabled(true);
    ui->Port_lineEdit->setEnabled(true);
}


void Widget::on_Send_pushButton_clicked()
{
    qDebug()<<"Send ready";
    connection->write(ui->Send_textEdit->toPlainText().toStdString().c_str());
}

void Widget::Read_all()
{
    qDebug()<<"Read_all ready";
    QTextCharFormat read_brush=QTextCharFormat();
    read_brush.setForeground(QBrush(QColor(Qt::blue)));
    ui->Receive_textEdit->setCurrentCharFormat(read_brush);
    ui->Receive_textEdit->insertPlainText(connection->readAll()+"\n");
    ui->Receive_textEdit->moveCursor(QTextCursor::End);
    read_brush.setForeground(QBrush(QColor(Qt::black)));
    ui->Receive_textEdit->setCurrentCharFormat(read_brush);
}

void Widget::on_Disconnected()
{
    qDebug()<<"disconnected";
    ui->Receive_textEdit->insertPlainText("服务端断开\n");
    ui->Connect_pushButton->setEnabled(true);
    ui->Disconnect_pushButton->setEnabled(false);
    ui->Send_pushButton->setEnabled(false);
}

void Widget::on_Connected_success()
{
    timer->stop();
    this->setEnabled(true);
    ui->Receive_textEdit->insertPlainText("连接成功\n");
    ui->Connect_pushButton->setEnabled(false);
    ui->Disconnect_pushButton->setEnabled(true);
    ui->Send_textEdit->setEnabled(true);
    ui->Send_pushButton->setEnabled(true);
    ui->IP_address_lineEdit->setEnabled(false);
    ui->Port_lineEdit->setEnabled(false);
}

void Widget::on_Error(QAbstractSocket::SocketError socketError)
{
    qDebug()<<"连接失败"<<socketError;
    ui->Receive_textEdit->insertPlainText("连接失败\n");
}

void Widget::on_Time_out()
{
    connection->abort();
    this->setEnabled(true);
    qDebug()<<"连接超时";
    ui->Receive_textEdit->insertPlainText("连接超时\n");
}

