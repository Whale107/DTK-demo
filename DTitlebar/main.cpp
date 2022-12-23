#include <DApplication>
#include <DTitlebar>
#include <DMainWindow>
#include <DMenu>
#include <DStyle>
DWIDGET_USE_NAMESPACE //使用DTK widget命名空间


int main(int argc, char *argv[]){
    DApplication app(argc, argv);
    DMainWindow win;
    win.resize(400,250);

    DTitlebar *bar = win.titlebar(); //窗口会自带一个titlebar，直接调用
    DMenu *menu =  bar->menu()->addMenu("文件"); //新建一个文件菜单，并用一个 menu 指针来接收这个菜单并管理
    bar->menu()->addSeparator(); //添加一个分隔符
    menu->addAction("新建");  //menu菜单下添加可选项 “新建”
    menu->addAction("打开");
    menu->addAction("关闭");
    menu->setIcon(menu->style()->standardIcon(DStyle::SP_DirIcon)); //给文件菜单添加一个自带图标

    bar->setQuitMenuDisabled(true);  //设置退出菜单为不可用
    bar->setSwitchThemeMenuVisible(false); //设置主题更换菜单为不可见

    win.show();
    return app.exec();
}