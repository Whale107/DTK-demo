#include <DApplication>
#include <DListView>
#include <DMainWindow>
#include <DWidget>
#include <DStyle>
#include <DHeaderView>
#include <QStyle>
#include <QLabel>

DWIDGET_USE_NAMESPACE

int main(int argc, char *argv[]){
    DApplication app(argc, argv);
    DMainWindow win;

    //新建一个标准模型
    QStandardItemModel *model = new QStandardItemModel();

    //写一个函数，函数的功能是新建显示在窗口中的条目，条目内容，设置不可编辑以及将条目添加到model中
    auto AddItems = [&win, &model](QIcon icon, QString name){
        DStandardItem *item = new DStandardItem(icon, name); //条目包含图标和名称
        item->setEditable(false); //设置条目不可被编辑
        model->appendRow(item); //将条目添加到model中
        return item;
    };

    //调用函数新建四个条目
    auto item0 = AddItems(win.style()->standardIcon(DStyle::SP_ComputerIcon), "电脑");
    auto item1 = AddItems(win.style()->standardIcon(DStyle::SP_DirIcon), "文件");
    auto item2 = AddItems(win.style()->standardIcon(DStyle::SP_DriveCDIcon), "媒体");
    auto item3 = AddItems(win.style()->standardIcon(DStyle::SP_TrashIcon), "回收站");

    //增加一个条目中的action， 可用作标识、与其他条目区别开，设置位置、大小、是否可点击
    DViewItemAction *action = new DViewItemAction(Qt::AlignCenter, QSize(), QSize(), true);
    //将QStyle转为DStyle
    DStyle *style = qobject_cast<DStyle *>(win.style());
    //给action设置图标
    action->setIcon(style->standardIcon(DStyle::SP_IndicatorChecked));
    //设置显示到哪个条目上，这里设置到item1
    item1->setActionList(Qt::Edge::RightEdge, {action});

    //新建一个 dlistview
    DListView *listview = new DListView();
    //将上面设置好的模型加载到listview中
    listview->setModel(model);
    //设置 listview 背景颜色的样式
    listview->setBackgroundType(DStyledItemDelegate::BackgroundType::RoundedBackground);

    //新建一个header模型
    QStandardItemModel *hmodel = new QStandardItemModel();
    //设置header内容
    hmodel->setHorizontalHeaderLabels({"功能", "最后打开时间"});
    //新建一个headerview
    DHeaderView *headerview = new DHeaderView(Qt::Horizontal);
    //将模型加载到headerview
    headerview->setModel(hmodel);
    //设置headerview高度最大值
    headerview->setMaximumHeight(36);
    //设置 headerview 调整尺寸方式，此处设为随窗口尺寸变化
    headerview->setSectionResizeMode(DHeaderView::Stretch);
    //将headerview添加到listview
    listview->addHeaderWidget(headerview);

    //为footer设置一个标签
    QLabel *label = new QLabel("共四项内容"); 
    //设置标签居中显示
    label->setAlignment(Qt::AlignCenter);
    //将标签添加到footer
    listview->addFooterWidget(label);

    //将 listview 放入主窗口
    win.setCentralWidget(listview);

    win.resize(500,350);
    win.show();
    return app.exec();
}