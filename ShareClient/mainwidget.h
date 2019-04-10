#ifndef MAINWIDGET_H
#define MAINWIDGET_H

#include <QWidget>
#include "landwidget.h"
#include <QTcpSocket>

namespace Ui {
class MainWidget;
}

class MainWidget : public QWidget
{
    Q_OBJECT

public:
    explicit MainWidget(QWidget *parent = nullptr);
    ~MainWidget();
    void connectToServer(); //连接服务器
private:
    Ui::MainWidget *ui;
    LandWidget landW;   //创建登陆窗口
    QTcpSocket *tcpsocket;  //创建通信套接字

};

#endif // MAINWIDGET_H
