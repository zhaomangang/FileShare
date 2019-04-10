#include "mainwidget.h"
#include "ui_mainwidget.h"
#include <QHostAddress>
#include <QMessageBox>
MainWidget::MainWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::MainWidget)
{
    connectToServer();
    landW.setSocket(tcpsocket); //将套接字传给登陆界面
    ui->setupUi(this);
    landW.show();
    connect(&landW,&LandWidget::landSucceed,
            [=]()
            {
                //当接收到登陆窗口传来的登陆成功信号时
                landW.hide();   //隐藏登陆窗口
                this->show();   //显示主窗口
            }
            );
}

void MainWidget::connectToServer()
{
    //分配空间指定父对象
    tcpsocket = new QTcpSocket(this);
    //获取服务器IP和端口
    QString ip = "172.20.10.10";
    qint16 port = 8888;

    //主动和服务器建立连接
    tcpsocket->connectToHost(QHostAddress(ip),port);

}

MainWidget::~MainWidget()
{
    delete ui;
}
