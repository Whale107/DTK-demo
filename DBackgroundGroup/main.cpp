#include <DApplication>
#include <DWidget>
#include <DBackgroundGroup>
#include <QVBoxLayout>
#include <QPushButton>
#include <QFrame>

DWIDGET_USE_NAMESPACE

int main(int argc, char *argv[]){
    DApplication app(argc, argv);
    DWidget win;

    //新建一个水平的主布局
    QHBoxLayout* mainlayout = new QHBoxLayout(&win);
    //在新建的主布局上添加一个按钮
    mainlayout->addWidget(new QPushButton("按钮"));

    //再新建一个水平布局
    QHBoxLayout *hlayout = new QHBoxLayout;
    
    //新建一个 DBackgroundGroup 组， 将布局 hlayout 放入组中
    DBackgroundGroup *group = new DBackgroundGroup(hlayout,&win);
    //将新建组添加到主布局中， 由于主布局上已有一个按钮，且为水平布局，这个 DBackgroundGroup 组会紧靠按钮右方
    mainlayout->addWidget(group);
    //给布局 hlayout 添加内容控件，此处为两个空QFrame
    hlayout->addWidget(new QFrame);
    hlayout->addWidget(new QFrame);

    win.resize(800,500);
    win.show();
    return app.exec();
}
