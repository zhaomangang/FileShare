#include "mainwidget.h"
#include "landwidget.h"
#include <QApplication>
#include <QHostAddress>



int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    MainWidget w;
    //w.show();
   // LandWidget land;
    //land.setParent(&w);
    //land.show();
    return a.exec();
}
