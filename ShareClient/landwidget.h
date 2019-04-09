#ifndef LANDWIDGET_H
#define LANDWIDGET_H

#include <QWidget>

namespace Ui {
class LandWidget;
}

class LandWidget : public QWidget
{
    Q_OBJECT

public:
    explicit LandWidget(QWidget *parent = nullptr);
    ~LandWidget();
    bool compare(QString userName,QString passWord,int VerCode);    //比较数据库里是否存在该用户以及用户名、密码、验证码是否正确

signals:
    void landSucceed(); //登陆成功信号
private slots:
    void on_LandButton_clicked();

private:
    Ui::LandWidget *ui;
};

#endif // LANDWIDGET_H
