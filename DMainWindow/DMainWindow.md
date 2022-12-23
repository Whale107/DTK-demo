## DMainWindow类
类似于Qt中的QMainWindow，可对窗口设置更多美观的样式。

使用如下代码显示一个最简单的DMainWindow窗口：
```cpp
#include <DApplication>
#include <DMainWindow> //导入DMainWindow依赖包
DWIDGET_USE_NAMESPACE //使用DTK Widget命名空间
int main(int argc, char *argv[]){
	DApplication app(argc, argv); //设置一个应用
	DMainWindow dwm;    //使用DMainWindow类实例化一个窗口
    dwm.resize(400,250); //可使用resize()对窗口大小进行调整
    // dwm.setWindowRadius(10); //使用setWindowRadius()对窗口圆角值进行调整
	// dmw.setShadowRadius(10); //设定阴影区域的圆角 shadowRadius　阴影区域圆角大小
	dwm.show(); //显示这个窗口
	return app.exec(); //运行应用
}

```
以上是个简单的例子，运行结果如下：
[example](/docs/images/dmainwindow_example.png)
