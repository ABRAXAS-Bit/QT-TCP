#include "client_name_combobox.h"

Client_name_comboBox::Client_name_comboBox(QWidget*parent):QComboBox(parent)
{

}

void Client_name_comboBox::mousePressEvent(QMouseEvent *e)
{
    if(e->button()==Qt::LeftButton)//鼠标左键按下该按钮
    {
        emit button_signals();
    }
    QComboBox::mousePressEvent(e);
}
