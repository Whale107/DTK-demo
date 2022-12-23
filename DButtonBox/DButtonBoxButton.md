## DButtonBoxButton类

`Dtk::Widget::DButtonBox`类提提供了修改了样式的按钮，提供了设置图标的按钮的函数。

通过DButtonBox类实例化一个box对象，对象父亲设置为box显示的窗口地址；由于是一个按钮组，所以它由多个按钮组成。通过`DButtonBoxButton`实例化单个按钮的指针，这里设置两个按钮，将单个按钮的父亲设置为按钮组box的地址。

```c++
DButtonBox box(&win);
DButtonBoxButton *btn1 = new DButtonBoxButton("BTN1", &box);
DButtonBoxButton *btn2 = new DButtonBoxButton("BTN2", &box);
```

通过`setIcon`设置按钮的风格；<br>
通过`setButtonList`将按钮进添加到组中,QList中存储checkable按钮是否可选中。
```c++
btn1->setIcon(QStyle::StandardPixmap::SP_ArrowUp);
box.setButtonList({btn1, btn2}, true);
```




