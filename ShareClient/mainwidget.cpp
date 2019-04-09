#include "mainwidget.h"
#include "ui_mainwidget.h"

MainWidget::MainWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::MainWidget)
{
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

MainWidget::~MainWidget()
{
    delete ui;
}
