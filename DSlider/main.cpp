#include <DApplication>
#include <DMainWindow>
#include <DSlider>
#include <DPushButton>
DWIDGET_USE_NAMESPACE //使用Dtk widget的命名空间

int main(int argc, char *argv[]){
    DApplication app(argc, argv);
    DMainWindow win;
    win.resize(800, 500);

    DSlider *dslider = new DSlider(Qt::Horizontal, &win); //新建一个水平方向的DSlider，父亲设置为主窗口
    dslider->move(0, 50);
    dslider->setLeftIcon(win.style()->standardIcon(DStyle::SP_ArrowLeft)); //给滑块设置一个左图标，这里使用一个自带的左箭头
    dslider->setRightIcon(win.style()->standardIcon(DStyle::SP_ArrowRight)); //给滑块设置一个右图标，这里使用自带的右箭头
    dslider->setFixedWidth(400);

    DPushButton *btn = new DPushButton("按钮", &win); //设置一个按钮
    btn->move(0, 100); //移动按钮的位置

    //建立一个滑块与按钮的连接，滑块滑动发出信号，按钮接收，lambda函数中设置按钮的移动，并且打印出滑块的当前数值
    QObject::connect(dslider, &DSlider::valueChanged, btn, [dslider, btn](){
        int sliderValue = dslider->value();
        qDebug() << sliderValue;
        btn->move(sliderValue * 5, 100);
    });

    win.show();
    return app.exec();
}