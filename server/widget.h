#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include "serve.h"

namespace Ui {
class Widget;
}

class Widget : public QWidget
{
    Q_OBJECT

public:
    explicit Widget(QWidget *parent = nullptr);
    ~Widget();

private slots:
    void on_button_clicked();
public slots:
    void updateServer(QString,int);
private:
    Ui::Widget *ui;
    Server *serve;
};

#endif // WIDGET_H
