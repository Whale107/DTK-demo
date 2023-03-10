#include <DStyle>
#include <DApplication>
#include <DListView>
#include <DWidget>
#include <QVBoxLayout>
#include <QLabel>
#include <QStringListModel>
#include <QIcon>

DWIDGET_USE_NAMESPACE // 使用Dtk widget命名空间



int main(int argc, char *argv[]){

    DApplication app(argc, argv); //设置应用
    DWidget *widget = new DWidget; //新建一个widget窗口
    widget->setWindowTitle("DTK自带图标"); //设置窗口名称
    widget->resize(800,600);

    QStringList stringlist({ //设置展示在ListView中的内容List,包含DStyle中所有图标的名称
        "SP_TitleBarMenuButton",
        "SP_TitleBarMinButton",
        "SP_TitleBarMaxButton",
        "SP_TitleBarCloseButton",
        "SP_TitleBarNormalButton",
        "SP_TitleBarShadeButton",
        "SP_TitleBarUnshadeButton",
        "SP_TitleBarContextHelpButton",
        "SP_DockWidgetCloseButton",
        "SP_MessageBoxInformation",
        "SP_MessageBoxWarning",
        "SP_MessageBoxCritical",
        "SP_MessageBoxQuestion",
        "SP_DesktopIcon",
        "SP_TrashIcon",
        "SP_ComputerIcon",
        "SP_DriveFDIcon",
        "SP_DriveHDIcon",
        "SP_DriveCDIcon",
        "SP_DriveDVDIcon",
        "SP_DriveNetIcon",
        "SP_DirOpenIcon",
        "SP_DirClosedIcon",
        "SP_DirLinkIcon",
        "SP_DirLinkOpenIcon",
        "SP_FileIcon",
        "SP_FileLinkIcon",
        "SP_ToolBarHorizontalExtensionButton",
        "SP_ToolBarVerticalExtensionButton",
        "SP_FileDialogStart",
        "SP_FileDialogEnd",
        "SP_FileDialogToParent",
        "SP_FileDialogNewFolder",
        "SP_FileDialogDetailedView",
        "SP_FileDialogInfoView",
        "SP_FileDialogContentsView",
        "SP_FileDialogListView",
        "SP_FileDialogBack",
        "SP_DirIcon",
        "SP_DialogOkButton",
        "SP_DialogCancelButton",
        "SP_DialogHelpButton",
        "SP_DialogOpenButton",
        "SP_DialogSaveButton",
        "SP_DialogCloseButton",
        "SP_DialogApplyButton",
        "SP_DialogResetButton",
        "SP_DialogDiscardButton",
        "SP_DialogYesButton",
        "SP_DialogNoButton",
        "SP_ArrowUp",
        "SP_ArrowDown",
        "SP_ArrowLeft",
        "SP_ArrowRight",
        "SP_ArrowBack",
        "SP_ArrowForward",
        "SP_DirHomeIcon",
        "SP_CommandLink",
        "SP_VistaShield",
        "SP_BrowserReload",
        "SP_BrowserStop",
        "SP_MediaPlay",
        "SP_MediaStop",
        "SP_MediaPause",
        "SP_MediaSkipForward",
        "SP_MediaSkipBackward",
        "SP_MediaSeekForward",
        "SP_MediaSeekBackward",
        "SP_MediaVolume",
        "SP_MediaVolumeMuted",
        "SP_LineEditClearButton",
        "SP_DialogYesToAllButton",
        "SP_DialogNoToAllButton",
        "SP_DialogSaveAllButton",
        "SP_DialogAbortButton",
        "SP_DialogRetryButton",
        "SP_DialogIgnoreButton",
        "SP_RestoreDefaultsButton",
    });
    //设置模型为文本展示列表QStringListModel
    QAbstractItemModel *listModel = new QStringListModel(stringlist, &app);
    //新建一个指向DListView的指针
    DListView *listview = new DListView;
    listview->setModel(listModel); //将模型设置到listview中

    //新建一个样式
    DStyle *style = new DStyle();
    //设置垂直布局，并设置父亲为展示的窗口widget
    QVBoxLayout *layout = new QVBoxLayout(widget);
    layout->addWidget(listview); //将listview所在widget添加到布局
    QLabel *label = new QLabel(); //新建一个展示图标的label
    QIcon icon; //声明一个icon

    //绑定点击listview展示对应的图标，通过listview->currentIndex()找到具体list索引
    QObject::connect(listview, &DListView::clicked, [&](){
        switch (listview->currentIndex().row()) { //使用选择结构设定不同点击对应的不同响应，响应是设置icon的风格
            case 0:
                icon = style->standardIcon(DStyle::SP_TitleBarMenuButton);
                break;
            case 1:
                icon = style->standardIcon(DStyle::SP_TitleBarMinButton);
                break;
            case 2:
                icon = style->standardIcon(DStyle::SP_TitleBarMaxButton);
                break;
            case 3:
                icon = style->standardIcon(DStyle::SP_TitleBarCloseButton);
                break;
            case 4:
                icon = style->standardIcon(DStyle::SP_TitleBarNormalButton);
                break;
            case 5:
                icon = style->standardIcon(DStyle::SP_TitleBarShadeButton);
                break;
            case 6:
                icon = style->standardIcon(DStyle::SP_TitleBarUnshadeButton);
                break;
            case 7:
                icon = style->standardIcon(DStyle::SP_TitleBarContextHelpButton);
                break;
            case 8:
                icon = style->standardIcon(DStyle::SP_DockWidgetCloseButton);
                break;
            case 9:
                icon = style->standardIcon(DStyle::SP_MessageBoxInformation);
                break;
            case 10:
                icon = style->standardIcon(DStyle::SP_MessageBoxWarning);
                break;
            case 11:
                icon = style->standardIcon(DStyle::SP_MessageBoxCritical);
                break;
            case 12:
                icon = style->standardIcon(DStyle::SP_MessageBoxQuestion);
                break;
            case 13:
                icon = style->standardIcon(DStyle::SP_DesktopIcon);
                break;
            case 14:
                icon = style->standardIcon(DStyle::SP_TrashIcon);
                break;
            case 15:
                icon = style->standardIcon(DStyle::SP_ComputerIcon);
                break;
            case 16:
                icon = style->standardIcon(DStyle::SP_DriveFDIcon);
                break;
            case 17:
                icon = style->standardIcon(DStyle::SP_DriveHDIcon);
                break;
            case 18:
                icon = style->standardIcon(DStyle::SP_DriveCDIcon);
                break;
            case 19:
                icon = style->standardIcon(DStyle::SP_DriveDVDIcon);
                break;
            case 20:
                icon = style->standardIcon(DStyle::SP_DriveNetIcon);
                break;
            case 21:
                icon = style->standardIcon(DStyle::SP_DirOpenIcon);
                break;
            case 22:
                icon = style->standardIcon(DStyle::SP_DirClosedIcon);
                break;
            case 23:
                icon = style->standardIcon(DStyle::SP_DirLinkIcon);
                break;
            case 24:
                icon = style->standardIcon(DStyle::SP_DirLinkOpenIcon);
                break;
            case 25:
                icon = style->standardIcon(DStyle::SP_FileIcon);
                break;
            case 26:
                icon = style->standardIcon(DStyle::SP_FileLinkIcon);
                break;
            case 27:
                icon = style->standardIcon(DStyle::SP_ToolBarHorizontalExtensionButton);
                break;
            case 28:
                icon = style->standardIcon(DStyle::SP_ToolBarVerticalExtensionButton);
                break;
            case 29:
                icon = style->standardIcon(DStyle::SP_FileDialogStart);
                break;
            case 30:
                icon = style->standardIcon(DStyle::SP_FileDialogEnd);
                break;
            case 31:
                icon = style->standardIcon(DStyle::SP_FileDialogToParent);
                break;
            case 32:
                icon = style->standardIcon(DStyle::SP_FileDialogNewFolder);
                break;
            case 33:
                icon = style->standardIcon(DStyle::SP_FileDialogDetailedView);
                break;
            case 34:
                icon = style->standardIcon(DStyle::SP_FileDialogInfoView);
                break;
            case 35:
                icon = style->standardIcon(DStyle::SP_FileDialogContentsView);
                break;
            case 36:
                icon = style->standardIcon(DStyle::SP_FileDialogListView);
                break;
            case 37:
                icon = style->standardIcon(DStyle::SP_FileDialogBack);
                break;
            case 38:
                icon = style->standardIcon(DStyle::SP_DirIcon);
                break;
            case 39:
                icon = style->standardIcon(DStyle::SP_DialogOkButton);
                break;
            case 40:
                icon = style->standardIcon(DStyle::SP_DialogCancelButton);
                break;
            case 41:
                icon = style->standardIcon(DStyle::SP_DialogHelpButton);
                break;
            case 42:
                icon = style->standardIcon(DStyle::SP_DialogOpenButton);
                break;
            case 43:
                icon = style->standardIcon(DStyle::SP_DialogSaveButton);
                break;
            case 44:
                icon = style->standardIcon(DStyle::SP_DialogCloseButton);
                break;
            case 45:
                icon = style->standardIcon(DStyle::SP_DialogApplyButton);
                break;
            case 46:
                icon = style->standardIcon(DStyle::SP_DialogResetButton);
                break;
            case 47:
                icon = style->standardIcon(DStyle::SP_DialogDiscardButton);
                break;
            case 48:
                icon = style->standardIcon(DStyle::SP_DialogYesButton);
                break;
            case 49:
                icon = style->standardIcon(DStyle::SP_DialogNoButton);
                break;
            case 50:
                icon = style->standardIcon(DStyle::SP_ArrowUp);
                break;
            case 51:
                icon = style->standardIcon(DStyle::SP_ArrowDown);
                break;
            case 52:
                icon = style->standardIcon(DStyle::SP_ArrowLeft);
                break;
            case 53:
                icon = style->standardIcon(DStyle::SP_ArrowRight);
                break;
            case 54:
                icon = style->standardIcon(DStyle::SP_ArrowBack);
                break;
            case 55:
                icon = style->standardIcon(DStyle::SP_ArrowForward);
                break;
            case 56:
                icon = style->standardIcon(DStyle::SP_DirHomeIcon);
                break;
            case 57:
                icon = style->standardIcon(DStyle::SP_CommandLink);
                break;
            case 58:
                icon = style->standardIcon(DStyle::SP_VistaShield);
                break;
            case 59:
                icon = style->standardIcon(DStyle::SP_BrowserReload);
                break;
            case 60:
                icon = style->standardIcon(DStyle::SP_BrowserStop);
                break;
            case 61:
                icon = style->standardIcon(DStyle::SP_MediaPlay);
                break;
            case 62:
                icon = style->standardIcon(DStyle::SP_MediaStop);
                break;
            case 63:
                icon = style->standardIcon(DStyle::SP_MediaPause);
                break;
            case 64:
                icon = style->standardIcon(DStyle::SP_MediaSkipForward);
                break;
            case 65:
                icon = style->standardIcon(DStyle::SP_MediaSkipBackward);
                break;
            case 66:
                icon = style->standardIcon(DStyle::SP_MediaSeekForward);
                break;
            case 67:
                icon = style->standardIcon(DStyle::SP_MediaSeekBackward);
                break;
            case 68:
                icon = style->standardIcon(DStyle::SP_MediaVolume);
                break;
            case 69:
                icon = style->standardIcon(DStyle::SP_MediaVolumeMuted);
                break;
            case 70:
                icon = style->standardIcon(DStyle::SP_LineEditClearButton);
                break;
            case 71:
                icon = style->standardIcon(DStyle::SP_DialogYesToAllButton);
                break;
            case 72:
                icon = style->standardIcon(DStyle::SP_DialogNoToAllButton);
                break;
            case 73:
                icon = style->standardIcon(DStyle::SP_DialogSaveAllButton);
                break;
            case 74:
                icon = style->standardIcon(DStyle::SP_DialogAbortButton);
                break;
            case 75:
                icon = style->standardIcon(DStyle::SP_DialogRetryButton);
                break;
            case 76:
                icon = style->standardIcon(DStyle::SP_DialogIgnoreButton);
                break;
            case 77:
                icon = style->standardIcon(DStyle::SP_RestoreDefaultsButton);
                break;
        }
        //将设置完风格的图标添加到label，通过pixmap()转换类型并改变图标大小
        label->setPixmap(icon.pixmap(50,50));
        layout->addWidget(label); //将标签对应的widget添加到布局
    });

    widget->show(); //展示主窗口
    return app.exec(); //运行程序并等待关闭

}
