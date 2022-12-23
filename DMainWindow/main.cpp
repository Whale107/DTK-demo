#include <DApplication>
#include <DMainWindow>
#include <DApplicationSettings>
DWIDGET_USE_NAMESPACE;

int main(int argc, char *argv[]){
    DApplication app(argc, argv); //设置一个应用
        
    app.setApplicationName("这是应用名称"); //设置应用名称
    app.setOrganizationName("deepin"); //设置关于信息中的系统信息
    app.setApplicationVersion("2.0"); //设置关于信息中的版本号
        
    DApplicationSettings as;
    Q_UNUSED(as) //设置记住应用主题
    
    DMainWindow dwm;    //使用DMainWindow类实例化一个窗口
    dwm.resize(400,250); //可使用resize()对窗口大小进行调整
    dwm.show(); //显示这个窗口
        
    return app.exec(); //运行应用
}