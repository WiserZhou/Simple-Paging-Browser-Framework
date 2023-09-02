#include "browser.h"

void MainWindow::changeLocation2()
{
    QUrl url = QUrl::fromUserInput(te1->text());
    //在该函数中，首先通过调用fromUserInput()方法将用户在地址栏输入的文本转换为QUrl对象。此方法会自动处理用户输入的文本，
    //例如添加协议前缀(http://或https://)等。
    view2->load(url);//使用view对象的load()方法将浏览器视图加载到由用户输入的URL对应的网页上。
    view2->setFocus();//将焦点设置到浏览器视图上，以便用户可以与网页进行交互。
}

void MainWindow::adjustLocation()
{
    locationEdit->setText(view->url().toString());
    //在该函数中，首先通过调用view对象的url()方法获取当前页面的URL，然后将URL转换为字符串形式，
    //并使用setText()方法将其设置为locationEdit小部件的文本。这样，每当页面加载完成或导航到新的URL时，
    //adjustLocation函数将被调用以更新locationEdit中显示的URL。
}

void MainWindow::changeLocation()
{
    QUrl url = QUrl::fromUserInput(locationEdit->text());
    //在该函数中，首先通过调用fromUserInput()方法将用户在地址栏输入的文本转换为QUrl对象。此方法会自动处理用户输入的文本，
    //例如添加协议前缀(http://或https://)等。
    view->load(url);//使用view对象的load()方法将浏览器视图加载到由用户输入的URL对应的网页上。
    view->setFocus();//将焦点设置到浏览器视图上，以便用户可以与网页进行交互。
}

void MainWindow::adjustTitle()
{
    if (progress <= 0 || progress >= 100)
        setWindowTitle(view->title());
    else
        setWindowTitle(QStringLiteral("%1 (%2%)").arg(view->title()).arg(progress));

    //这段代码使用了arg()函数来替换字符串中的占位符 %1 和 %2。arg() 函数是 QString 类的成员函数，用于将参数的值插入到字符串中对应的占位符位置。

}
//在该函数中，首先判断progress变量的值是否小于等于0或大于等于100。
//如果progress的值小于等于0或大于等于100，表示加载进度未知或已完成，那么使用view对象的title()方法获取当前页面的标题，
//并将其设置为主窗口的标题（通过调用setWindowTitle()方法）。如果progress的值在0和100之间，表示加载进度正在进行中，
//那么使用view对象的title()方法获取当前页面的标题，并使用QStringLiteral、arg()等方法构建一个带有加载进度的标题字符串，然后将该字符串设置为主窗口的标题。

void MainWindow::setProgress(int p)
{
    progress = p;
    adjustTitle();
    //在该函数中，首先将参数p的值赋给成员变量progress，以更新当前页面的加载进度。
    //然后调用adjustTitle()函数，根据新的加载进度progress来调整主窗口的标题。adjustTitle()函数会根据加载进度的不同情况，更新主窗口的标题显示。
}

void MainWindow::finishLoading(bool)
{
    progress = 100;
    adjustTitle();
    view->page()->runJavaScript(jQuery);
    rotateImages(rotateAction->isChecked());
}
//在该函数中，首先将进度progress设置为100，表示页面加载已完成。然后调用adjustTitle()函数，根据加载进度更新主窗口的标题。
//接下来，使用view对象的page()方法获取当前页面的QWebEnginePage对象，并调用runJavaScript()方法来执行JavaScript代码。在这里，传入了变量jQuery作
//为要执行的JavaScript代码。这可能是用于操作和处理页面元素的特定JavaScript代码。
//最后，调用rotateImages()函数并传入rotateAction->isChecked()作为参数，来根据旋转动作的选中状态决定是否旋转页面中的图像。


