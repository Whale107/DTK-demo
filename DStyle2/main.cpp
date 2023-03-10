#include <DStyle>
#include <DApplication>
#include <DListView>
#include <DWidget>
#include <QVBoxLayout>
#include <QIcon>
DWIDGET_USE_NAMESPACE // 使用Dtk widget命名空间

int main(int argc, char *argv[]){

    DApplication app(argc, argv); //设置应用
    DWidget *widget = new DWidget; //新建一个widget窗口
    widget->setWindowTitle("标准图标"); //设置窗口名称
    widget->resize(800,600);

    //新建一个标准item模型
    QStandardItemModel *model = new QStandardItemModel(widget);
    //新建一个DListView
    DListView *listview = new DListView;
    //新建一个风格
    DStyle *style = new DStyle();
    //写一个插入新item的函数，函数可以设置每一个item的图标、名称、高度、不可被编辑
    auto insertItem = [&](const QString &name, const QIcon &icon)
        -> DStandardItem * {
        DStandardItem *item = new DStandardItem(icon, name); //新建一个item并设置图标、item名称
        item->setSizeHint(QSize(item->sizeHint().width(), 50)); //设置item的图标
        item->setEditable(false); //设置item不可被编辑
        model->appendRow(item); //将新建item添加到模型中
        return item;
    };

    //通过 QMetaEnum::fromType 实现枚举值和字符串的转化
    QMetaEnum meta = QMetaEnum::fromType<QStyle::StandardPixmap>();
    //循环写入listview的名称和图标，此处为DTK重绘QT图标
    for(int i = DStyle::SP_TitleBarMenuButton; i <= 70; i++) {
        insertItem(meta.valueToKey(i), style->standardIcon(DStyle::StandardPixmap(i)));
    }

    //此处添加DTK自设计和定义的图标，先用数组记录图标名称
    QStringList IconNameList ({
        "SP_ForkElement",                             //关闭
        "SP_DecreaseElement",                         //减少（-）
        "SP_IncreaseElement",                         //增加（+）
        "SP_MarkElement",                             //对勾
        "SP_SelectElement",                           //选择（...）
        "SP_EditElement",                             //编辑
        "SP_ExpandElement",                           //展开
        "SP_ReduceElement",                           //收缩
        "SP_LockElement",                             //锁定
        "SP_UnlockElement",                           //解锁
        "SP_MediaVolumeLowElement",                   //音量
        "SP_MediaVolumeHighElement",                  //满音量
        "SP_MediaVolumeMutedElement",                 //静音
        "SP_MediaVolumeLeftElement",                  //左声道
        "SP_MediaVolumeRightElement",                 //右声道
        "SP_ArrowEnter",                              //进入
        "SP_ArrowLeave",                              //离开
        "SP_ArrowNext",                               //下一页
        "SP_ArrowPrev",                               //上一页
        "SP_ShowPassword",                            //显示密码
        "SP_HidePassword",                            //因此密码
        "SP_CloseButton",                             //关闭按钮（X）
        "SP_IndicatorMajuscule",                      //大写标识
        "SP_IndicatorSearch",                         //搜索标识（放大镜）
        "SP_IndicatorUnchecked",                      //搜索标识（对应对勾的选中状态）
        "SP_IndicatorChecked",                        //搜索标识（对勾）
        "SP_DeleteButton",                            //删除按钮
        "SP_AddButton",                               //新增按钮
        "SP_TitleQuitFullButton",                     //标题栏(「」)
        "SP_TitleMoreButton",                         //标题栏 "更多" 按钮
        "SP_Title_SS_LeftButton",                     //标题栏左分屏按钮
        "SP_Title_SS_RightButton",                    //标题栏右分屏按钮
        "SP_Title_SS_ShowMaximizeButton",             //标题栏最大化分屏按钮
        "SP_Title_SS_ShowNormalButton",               //标题栏还原分屏按钮
    });
    //通过循环遍历上述名称数组同时添加图标
    for(int i = DStyle::SP_ForkElement; i <= DStyle::SP_Title_SS_ShowNormalButton; i++){
        insertItem(IconNameList[i - DStyle::SP_ForkElement], style->standardIcon(DStyle::StandardPixmap(i)));
    }

    listview->setModel(model); //将模型加载到listview
    QVBoxLayout *layout = new QVBoxLayout(widget); //新建一个垂直布局
    layout->addWidget(listview); //将listview所在widget添加到布局

    widget->show(); //展示主窗口
    return app.exec(); //运行程序并等待关闭

}
