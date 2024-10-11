#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    this->setLayout(ui->verticalLayout_1);
    ui->Stop_listening_pushButton->setEnabled(false);
    ui->Main_Edit->setReadOnly(true);
    server = new QTcpServer(this);
    QList<QHostAddress>address = QNetworkInterface::allAddresses();
    for(QHostAddress temp_address:address)//获取IP_address
    {
        if(temp_address.protocol() == QAbstractSocket::IPv4Protocol)
        {
            ui->IP_address_comboBox->addItem(temp_address.toString());
        }
    }
    connect(server,&QTcpServer::newConnection,this,[=]()
            {
                on_newconnection();
            });
    connect(ui->Client_comboBox,&Client_name_comboBox::button_signals,this,[=]
            {
                on_clientnamecombobox();
            });
}

Widget::~Widget()
{
    delete ui;
}

void Widget::on_newconnection()
{
    qDebug()<<"on_newconnection ready";
    if(server->hasPendingConnections())//查看是否有待处理的连接
    {
        qDebug()<<"has pendingconnection";
        QTcpSocket *next_connection = server->QTcpServer::nextPendingConnection();
        qDebug()<<"connected"<<next_connection->peerAddress().toString()<<
            "port:"<<QString::number(next_connection->peerPort());
        ui->Main_Edit->insertPlainText("客户端地址:"+next_connection->peerAddress().toString()+
                                       "\n客户端端口号:"+QString::number(next_connection->peerPort())+"\n");
        connect(next_connection,&QIODevice::readyRead,this,[=]
                {
                    on_readyread(next_connection);
                });//接受数据
        connect(next_connection,&QAbstractSocket::disconnected,this,&Widget::on_disconnected);//连接失败
        connect(next_connection, &QAbstractSocket::stateChanged, this, &Widget::on_statechanged);
        ui->Client_comboBox->addItem(QString::number(next_connection->peerPort()));
    }
    else{
        qDebug()<<"not pendingconnection";
    }
}

void Widget::on_readyread(QTcpSocket* connection)
{
    qDebug()<<"ready_read success!!!";
    QTextCharFormat read_brush = QTextCharFormat();
    read_brush.setForeground(QBrush(QColor(Qt::blue)));
    ui->Main_Edit->setCurrentCharFormat(read_brush);
    QByteArray be_read = connection->QIODevice::readAll();
    ui->Main_Edit->insertPlainText(be_read+"\n");
    ui->Main_Edit->moveCursor(QTextCursor::End);
    read_brush.setForeground(QBrush(QColor(Qt::black)));
    ui->Main_Edit->setCurrentCharFormat(read_brush);
}

void Widget::on_disconnected()
{
    qDebug()<<"disconnected";
    QTcpSocket*disconnected_connection = qobject_cast<QTcpSocket*>(sender());
    ui->Main_Edit->insertPlainText("客户端断开连接!\n");
    disconnected_connection->deleteLater();//删除(异步操作，在这个事件结束前，这个删除不会进行)
    ui->Client_comboBox->removeItem(ui->Client_comboBox->currentIndex());
    QList<QTcpSocket*>socket_total=server->findChildren<QTcpSocket*>();
    if(socket_total.size()==1)
    {
        ui->Client_comboBox->clear();
    }
}

void Widget::on_statechanged(QAbstractSocket::SocketState socketState)
{
    qDebug()<<"statechange is "<<socketState;//输出状态变化信息
}

void Widget::on_clientnamecombobox()
{
    qDebug()<<"on_clientnamecombox_slots run";
    ui->Client_comboBox->clear();
    QList<QTcpSocket*>socket_total=server->findChildren<QTcpSocket*>();
    qDebug()<<"socket_total_size is "<<socket_total.size();
    if(socket_total.isEmpty())
    {
        qDebug()<<"on_clientnamecombobox return";
        QMessageBox messageBox;
        messageBox.setWindowTitle("Warning");
        messageBox.setText("NO SOCKET CONNECTED!!!");
        messageBox.exec();
        return;
    }
    for(QTcpSocket*temp_socket:socket_total)
    {
        ui->Client_comboBox->addItem(QString::number(temp_socket->peerPort()));//添加某个客户端
    }
    ui->Client_comboBox->addItem("all");
}

void Widget::on_Listening_pushButton_clicked(bool checked)
{
    if(checked)
    {
        QHostAddress myhost_address(ui->IP_address_comboBox->currentText());
        int port =ui->Port_number_Edit->text().toUShort();
        if(!server->listen(myhost_address,port))//8888为端口号
        {
            qDebug()<<"Listening error";
            QMessageBox listening_error;
            listening_error.setWindowTitle("Listening error");
            listening_error.setInformativeText("端口号已被占用");
            listening_error.exec();
        }
        else{
            qDebug()<<"Listening success!!!";
            ui->Listening_pushButton->setEnabled(false);
            ui->Stop_listening_pushButton->setEnabled(true);
            ui->IP_address_comboBox->setEnabled(false);
            ui->Port_number_Edit->setEnabled(false);
        }
    }
}

void Widget::on_Send_pushButton_clicked()
{
    QList<QTcpSocket*>socket_total = server->findChildren<QTcpSocket*>();
    if(socket_total==QList<QTcpSocket*>(NULL))
    {
        qDebug()<<"on_Send_pushButton return";
        QMessageBox messageBox;
        messageBox.setWindowTitle("Warning");
        messageBox.setText("NO SOCKET CONNECTED!!!");
        messageBox.exec();
        return;
    }
    qDebug()<<"on_Send_pushButton ready";
    if(ui->Client_comboBox->currentText()!="all")
    {
        socket_total[ClientcomboBox_index]->write(ui->Send_textEdit->toPlainText().toStdString().c_str());
    }
    else
    {
        for(QTcpSocket*temp_socket:socket_total)
        {
            temp_socket->write(ui->Send_textEdit->toPlainText().toStdString().c_str());
        }
    }
}

void Widget::on_Client_comboBox_activated(int index)
{
    ClientcomboBox_index=index;
}

void Widget::on_Stop_listening_pushButton_clicked()
{
    qDebug()<<"listening_close ready";
    server->close();//不再监听，即不再接受新的连接
    ui->Listening_pushButton->setEnabled(true);
    ui->Stop_listening_pushButton->setEnabled(false);
    ui->Client_comboBox->setEnabled(true);
    ui->IP_address_comboBox->setEnabled(true);
    ui->Port_number_Edit->setEnabled(true);
}

void Widget::on_Disconnection_pushButton_clicked()
{
    QList<QTcpSocket*>socket_total = server->findChildren<QTcpSocket*>();
    if(socket_total==QList<QTcpSocket*>(NULL))
    {
        qDebug()<<"on_Disconnection_pushButton return";
        QMessageBox messageBox;
        messageBox.setWindowTitle("Warning");
        messageBox.setText("NO SOCKET CONNECTED!!!");
        messageBox.exec();
        return;
    }
    else
    {
        qDebug()<<"disconnection ready";
        socket_total[ClientcomboBox_index]->close();//关闭该套接字
        socket_total[ClientcomboBox_index]->deleteLater();//删除该套接字
        ui->Client_comboBox->removeItem(ClientcomboBox_index);
    }
}

