#include "landwidget.h"
#include "ui_landwidget.h"
#include <QMessageBox>

LandWidget::LandWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::LandWidget)
{

    setWindowFlags(windowFlags()&~Qt::WindowMaximizeButtonHint);    // 禁止最大化按钮
    setFixedSize(405,420);                     // 禁止拖动窗口大小
    setWindowTitle("Share");
    ui->setupUi(this);
    ui->Password->setEchoMode(QLineEdit::Password); //设置密码编辑框为隐藏模式

}

LandWidget::~LandWidget()
{
    delete ui;
}
bool LandWidget::compare(QString userName, QString passWord, int VerCode)
{
    //校验密码和用户名，后期与数据库内容进行比较
    if(userName=="kid"&&passWord=="Z001221z")
    {
        return true;
    }else {
        return false;
    }
}

void LandWidget::on_LandButton_clicked()
{
    //点击登陆时
    if(compare(ui->UserName->text(),ui->Password->text(),ui->VerificationCode->text().toInt()))
    {
        //如果密码正确
        emit landSucceed(); //给主窗口发送登陆成功信号
    }
    else {
        QMessageBox::warning(this,"错误","用户名或密码错误");
    }

}
