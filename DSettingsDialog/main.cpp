#include <DApplication>
#include <DMainWindow>
#include <DSettingsDialog>
#include <QTemporaryFile>
#include <DPushButton>
#include <QObject>
#include <DSettingsWidgetFactory>
#include <DSettingsOption>
#include <DIconButton>
#include "dtkcore_global.h"
#include <qsettingbackend.h>
DWIDGET_USE_NAMESPACE
DCORE_USE_NAMESPACE

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
        QSettingBackend backend(tmpFile.fileName());

        //从json中初始化配置
        auto settings = DSettings::fromJsonFile(":/settingsData/settings.json");
        settings->setBackend(&backend);

        //初始化一个设置显示窗口
        DSettingsDialog dsd(&win);
        //如果自带控件不能满足需求，可自行注册控件，此处以一个Icon button为例
        dsd.widgetFactory()->registerWidget("icon-button", [&win](QObject *obj){
            DSettingsOption *option = qobject_cast<DSettingsOption *>(obj);
            DIconButton *iconBtn = new DIconButton(DStyle::SP_DriveCDIcon);//新建一个icon button
            return iconBtn;
        });
        dsd.updateSettings(settings); //将设置加载到设置窗口
        dsd.exec(); //设置窗口显示并等待响应
    });

    win.show();
    return app.exec();
}