#include <DApplication>
#include <DMainWindow> 
#include <DPushButton> 
#include <DMessageManager>
DWIDGET_USE_NAMESPACE //使用DWidget命名空间

int main(int argc, char *argv[]){
	DApplication app(argc, argv); //设置一个应用
	DMainWindow dmw; //设置一个主窗口
	dmw.resize(400,300); //重新设置主窗口大小
	DPushButton *btn1 = new DPushButton("自动消失信息",&dmw); //新建一个按钮
	btn1->move(0,50); //移动按钮
	DPushButton *btn2 = new DPushButton("点击消失信息",&dmw); 
	btn2->move(0,100);

	QObject::connect(btn1, &DPushButton::clicked, &dmw, [&dmw](){ //建立第一个按钮的连接
		//点击按钮后发出消息，消息的父亲设为主窗口，使用standardIcon（）设置样式并添加提示信息
    	DMessageManager::instance()->sendMessage(&dmw, QApplication::style()->standardIcon(QStyle::SP_MessageBoxWarning), "这是自动消失的信息");
    });

    QObject::connect(btn2, &DPushButton::clicked, [&dmw](){ //建立第二个按钮的连接
        DFloatingMessage *message = new DFloatingMessage(DFloatingMessage::ResidentType); //新建一个指向新消息的指针，指定消息类型为ResidentType
        message->setIcon(QApplication::style()->standardIcon(QStyle::SP_MessageBoxWarning)); //使用standardIcon（）设置样式
        message->setMessage("这是不会自动消失的提示消息"); //设置提示信息
        message->setWidget(new DPushButton("确认")); //在消息对话框上添加一个新按钮，并设置按钮信息
        DMessageManager::instance()->sendMessage(&dmw, message); //发送信息，父亲设为主窗口
    });

	dmw.show(); //显示主窗口
	return app.exec(); //运行应用
}
