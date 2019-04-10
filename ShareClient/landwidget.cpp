#include "landwidget.h"
#include "ui_landwidget.h"
#include <QMessageBox>
#include <QDebug>


LandWidget::LandWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::LandWidget)
{
    setWindowFlags(windowFlags()&~Qt::WindowMaximizeButtonHint);    // 禁止最大化按钮
    setFixedSize(405,420);                     // 禁止拖动窗口大小
    setWindowTitle("Share");
    ui->setupUi(this);

    ui->Password->setEchoMode(QLineEdit::Password); //设置密码编辑框为隐藏模式
  //  ui->UserName->setEchoMode(QLineEdit::Normal);


}

void LandWidget::setSocket(QTcpSocket *socket)
{
    tcpsocket = socket;
    connect(tcpsocket,SIGNAL(readyRead()),this,SLOT(slotRecv()));
}

LandWidget::~LandWidget()
{
    delete ui;
}
void LandWidget::slotRecv()
{
    //获取对方发送的内容
    QByteArray array = tcpsocket->readAll();
    qDebug()<<"recv"<<array.toInt();


    if(array.toInt() == 1)
    {
        //如果密码正确
        emit landSucceed(); //给主窗口发送登陆成功信号
    }
    else {
        QMessageBox::warning(this,"错误","用户名或密码错误");
    }
}
void LandWidget::compare(QString userName, QString passWord, int VerCode)
{
    //校验密码和用户名，后期与数据库内容进行比较
    QString landInfo = QString("land %1 %2").arg(userName).arg(passWord);

    //发送数据

    tcpsocket->write(landInfo.toUtf8().data());
    //while(land==-1);


}


void LandWidget::on_LandButton_clicked()
{
    compare(ui->UserName->text(),ui->Password->text(),ui->VerificationCode->text().toInt());
}
