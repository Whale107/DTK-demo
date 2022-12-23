#include <DArrowRectangle> //导入DArrowRectangle依赖包
#include <DApplication>
#include <DMainWindow>
#include <DWidget>
#include <DPushButton>
DWIDGET_USE_NAMESPACE //使用DTK widget命名空间

int main(int argc, char *argv[]){
    DApplication app(argc, argv);
    DMainWindow win; //实例化一个 mainwindow 作为主窗口
    win.resize(400,250); //设置窗口大小

    //实例化一个 DArrowRectangle 控件， 第一个参数指定方向，第二个参数指定浮动方式，第三个参数指定父控件地址
    DArrowRectangle *arrRec = new DArrowRectangle(DArrowRectangle::ArrowTop, DArrowRectangle::FloatWidget, &win);
    DWidget widget; //新建一个 widget 作为DArrowRectangle中的显示内容
    DPushButton *btn = new DPushButton("按钮", &widget); //新建一个按钮放到上面新建的widget中
    btn->move(20,25);

    widget.resize(100,70); //设置 widget 大小，注意 DArrowRectangle 会根据其内容 widget 的大小改变其本身大小
    arrRec->setContent(&widget); //将 widget 放置到 DArrowRectangle 里
    arrRec->setArrowX(50); //设置 DArrowRectangle 的箭头位置
    arrRec->setRadiusArrowStyleEnable(true); //可通过此函数设置 DArrowRectangle 箭头是否为圆角风格
    arrRec->setRadius(8); //设置 DArrowRectangle 圆角值
    arrRec->move(200, 50); //移动 DArrowRectangle 的位置

    win.show(); //展示主窗口
    return app.exec(); //运行程序并等待响应
}