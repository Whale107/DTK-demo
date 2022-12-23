#include <DApplication>
#include <DMainWindow>
#include <DSettingsDialog>
#include <QTemporaryFile>
#include <QDebug>
#include <DPushButton>
#include <QObject>
#include <qsettingbackend.h>
DWIDGET_USE_NAMESPACE

int main(int argc, char *argv[]){
    DApplication app(argc, argv);
    DMainWindow win;
    DPushButton *btn = new DPushButton("设置", &win); //初始化一个设置按钮
    win.resize(800,600);
    btn->move(0, 50);

    //建立设置按钮的连接，点击按钮弹出设置页面
    QObject::connect(btn, &QPushButton::clicked, &win, [&win](){
        //初始化一个存储后端
        QTemporaryFile tmpFile;
        tmpFile.open();
        Dtk::Core::QSettingBackend backend(tmpFile.fileName());

        //从json中初始化配置
        auto settings = Dtk::Core::DSettings::fromJsonFile(":/settingsData/settings2.json");
        settings->setBackend(&backend);

        //初始化一个设置显示窗口
        DSettingsDialog dsd(&win);
        dsd.updateSettings(settings); //将设置加载到设置窗口
        dsd.exec(); //设置窗口显示并等待响应
    });

    win.show();
    return app.exec();
}