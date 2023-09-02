#include <QtWidgets>
//该行包含了 Qt 的 QtWidgets 模块，其中包含创建用户界面所需的类。
#include "browser.h"

//该行导入了自定义的 MainWindow 类的头文件。
#include <qtwebenginewidgetsglobal.h>
//该行导入了 Qt 的 qtwebenginewidgetsglobal.h 头文件，其中包含了 Qt WebEngine 模块的全局宏定义。

int main(int argc, char * argv[])
{
    QCoreApplication::setOrganizationName("QtExamples");//该行设置了应用程序的组织名称为 "QtExamples"，这将影响一些配置文件的保存路径等。
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);//该行启用了高 DPI 缩放支持，以便在高 DPI 显示屏上正确缩放应用程序的界面。
    QApplication app(argc, argv);//创建了一个 QApplication 对象 app，它表示整个应用程序。

    QUrl url;
    if (argc > 1)
        url = QUrl::fromUserInput(argv[1]);
    else
        url = QUrl("https://cn.bing.com/?scope=web&FORM=HDRSC1&mkt=zh-CN");
    //这段代码用于解析命令行参数或设置默认的网页链接。如果命令行参数数量大于 1，那么将使用第
    //一个命令行参数作为初始的网页链接，否则默认使用 "https://cn.bing.com/?scope=web&FORM=HDRSC1&mkt=zh-CN"。

    MainWindow *browser = new MainWindow(url);//创建了一个 MainWindow 对象 browser，并传入初始的网页链接。
    browser->resize(1536, 864);
    browser->show();
    //设置 browser 窗口的大小，并显示出来。

    return app.exec();
    //进入 Qt 应用程序的事件循环，等待事件的触发和处理。当用户关闭窗口或退出应用程序时，app.exec() 函数会返回并结束程序的运行。
}
