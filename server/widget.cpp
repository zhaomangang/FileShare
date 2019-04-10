#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
}

Widget::~Widget()
{
    delete ui;
}

void Widget::on_button_clicked()
{
    serve = new Server(this,ui->port->text().toInt());
    connect(serve,SIGNAL(updateServer(QString,int)),this,SLOT(updateServer(QString,int)));
    ui->button->setEnabled(false);
}

void Widget::updateServer(QString msg,int length)
{
    ui->listWidget->addItem(msg.left(length));

}
