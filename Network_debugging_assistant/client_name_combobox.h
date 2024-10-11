#ifndef CLIENT_NAME_COMBOBOX_H
#define CLIENT_NAME_COMBOBOX_H

#include <QComboBox>
#include <QWidget>
#include <QMouseEvent>

class Client_name_comboBox : public QComboBox
{

    Q_OBJECT

public:
    Client_name_comboBox(QWidget*parent);
protected:
    void mousePressEvent(QMouseEvent*e)override;
signals:
    void button_signals();
};

#endif // CLIENT_NAME_COMBOBOX_H
