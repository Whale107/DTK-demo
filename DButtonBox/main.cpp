#include "dbuttonbox.h"
#include "dmainwindow.h"
#include <DApplication>
#include <DMainWindow>
#include <DTitlebar>
#include <DButtonBox>
#include <QObject>
#include <qobject.h>
#include <QPushButton>
#include <qpushbutton.h>
#include <QDebug>
DWIDGET_USE_NAMESPACE // using dtkwidget namespace

int main(int argc, char *argv[]){
    DApplication app(argc, argv);
    QIcon icon = QIcon::fromTheme("face-smile");
    app.setApplicationVersion("1.0.0");// 设置(关于中显示)版本号
    app.setProductName("dtk-dialog-demo");// 设置(关于中显示)产品名称
    app.setProductIcon(icon); // 设置(关于中显示)产品icon
    DMainWindow win;
    win.resize(800,400);
    DButtonBoxButton *btn = new DButtonBoxButton("按钮", &win);
    btn->move(400,200);
    btn->setIcon(QStyle::StandardPixmap::SP_ArrowUp);
    QObject::connect(btn, &QPushButton::clicked, [=](){
        qDebug() << "按钮按下了！";
    });

    DButtonBox box(&win);
    DButtonBoxButton *btn1 = new DButtonBoxButton("BTN1", &box);
    DButtonBoxButton *btn2 = new DButtonBoxButton("BTN2", &box);
    btn1->setIcon(QStyle::StandardPixmap::SP_ArrowUp);
    box.setButtonList({btn1, btn2}, true);

    box.move(400,300);
    
    win.show();


    return app.exec();
}