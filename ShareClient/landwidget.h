#ifndef LANDWIDGET_H
#define LANDWIDGET_H

#include <QWidget>
#include <QTcpSocket>

namespace Ui {
class LandWidget;
}

class LandWidget : public QWidget
{
    Q_OBJECT

public:
    explicit LandWidget(QWidget *parent = nullptr);
    ~LandWidget();
    void compare(QString userName,QString passWord,int VerCode);    //比较数据库里是否存在该用户以及用户名、密码、验证码是否正确
    void setSocket(QTcpSocket *socket); //设置通信套接字
signals:
    void landSucceed(); //登陆成功信号
private slots:
    void on_LandButton_clicked();

public slots:
    void slotRecv();

private:
    Ui::LandWidget *ui;
    QTcpSocket *tcpsocket;  //创建通信套接字

};

#endif // LANDWIDGET_H
