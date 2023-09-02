#include "browser.h"



void MainWindow::viewSource()
{
    QTextEdit *textEdit = new QTextEdit(nullptr);
    //在该函数中，首先创建了一个QTextEdit对象textEdit，用于显示网页的源代码。

    textEdit->setAttribute(Qt::WA_DeleteOnClose);
    //设置textEdit的属性为Qt::WA_DeleteOnClose，表示在关闭窗口时删除textEdit对象。

    textEdit->adjustSize();
    //调整textEdit的大小以适应内容。

    //根据主窗口的位置和textEdit的尺寸，将textEdit移动到主窗口中心的位置。
    textEdit->setAlignment(Qt::AlignHCenter);

    textEdit->resize(1200,800);
    textEdit->show();
    //显示textEdit窗口。

    view->page()->toHtml([textEdit](const QString &html){
        textEdit->setPlainText(html);
    });
    //通过调用view对象的page()方法获取当前页面的QWebEnginePage对象，并调用该对象的toHtml()方法来获取页面的HTML源代码。
    //toHtml()方法接受一个Lambda表达式作为参数，该Lambda表达式将获取到的HTML源代码作为参数传递给textEdit的setPlainText()方法，
    //从而将源代码显示在textEdit窗口中。
}

void MainWindow::highlightAllLinks()
{
    QString code = QStringLiteral(
        "qt.jQuery('a').each(function() {"
        "   var backgroundColor = qt.jQuery(this).css('background-color');"
        "   if (backgroundColor === 'rgb(255, 255, 0)' || backgroundColor === 'yellow') {"
        "       qt.jQuery(this).css('background-color', '');"
        "   } else {"
        "       qt.jQuery(this).css('background-color', 'yellow');"
        "   }"
        "})"
    );
    view->page()->runJavaScript(code);
}
//在该函数中，首先创建了一个QString类型的变量code，用于存储要执行的JavaScript代码。这段代码使用qt.jQuery选择器选中所有的<a>标签，
// 并使用each()方法循环遍历每一个选中的元素。在循环中，使用css()方法将选中的<a>标签的背景颜色设置为黄色。
//然后，使用view对象的page()方法获取当前页面的QWebEnginePage对象，并调用runJavaScript()方法来执行存储在code变量中的JavaScript代码。

void MainWindow::rotateImages(bool invert)
{
    QString code;

    if (invert)
        code = QStringLiteral("qt.jQuery('img').each( function () { qt.jQuery(this).css('transition', 'transform 2s'); qt.jQuery(this).css('transform', 'rotate(180deg)') } )");
    else
        code = QStringLiteral("qt.jQuery('img').each( function () { qt.jQuery(this).css('transition', 'transform 2s'); qt.jQuery(this).css('transform', 'rotate(0deg)') } )");
    view->page()->runJavaScript(code);
}
//在该函数中，首先创建了一个QString类型的变量code，用于存储要执行的JavaScript代码。
//然后使用if语句来判断参数invert的值。如果invert为true，表示要反转图像，则设置code为反转图像的JavaScript代码。这段代码使用qt.jQuery选择器选
//中所有的<img>标签，并分别给它们设置过渡效果和旋转变换，使图像以2秒的过渡时间逆时针旋转180度。
//如果invert为false，表示要将图像恢复原始状态，则设置code为恢复图像的JavaScript代码。这段代码同样使用qt.jQuery选择器选中所有的<img>标签，
//并分别给它们设置过渡效果和旋转变换，将图像旋转角度设置为0度，即恢复原始状态。
//最后，使用view对象的page()方法获取当前页面的QWebEnginePage对象，并调用runJavaScript()方法来执行存储在code变量中的JavaScript代码。

void MainWindow::removeGifImages()
{
    QString code = QStringLiteral("qt.jQuery('[src*=gif]').remove()");
    view->page()->runJavaScript(code);
}
//在该函数中，首先创建了一个QString类型的变量code，用于存储要执行的JavaScript代码。
//然后，将code设置为qt.jQuery('[src*=gif]').remove()这段JavaScript代码。这段代码使用qt.jQuery选择器选中所有src属性中包含"gif"的元素，
//并使用remove()方法将这些元素从DOM中移除，即从页面中移除所有的GIF图像。
//最后，使用view对象的page()方法获取当前页面的QWebEnginePage对象，并调用runJavaScript()方法来执行存储在code变量中的JavaScript代码。

void MainWindow::removeInlineFrames()
{
    QString code = QStringLiteral("qt.jQuery('iframe').remove()");
    view->page()->runJavaScript(code);
}
//然后，将code设置为qt.jQuery('iframe').remove()这段JavaScript代码。这段代码使用qt.jQuery选择器选中所有的<iframe>元素，并使用remove()方法将这些元
//素从DOM中移除，即从当前页面中移除所有的内联框架。
//最后，使用view对象的page()方法获取当前页面的QWebEnginePage对象，并调用runJavaScript()方法来执行存储在code变量中的JavaScript代码。

void MainWindow::removeObjectElements()
{
    QString code = QStringLiteral("qt.jQuery('object').remove()");
    view->page()->runJavaScript(code);
}
//在该函数中，首先创建了一个QString类型的变量code，用于存储要执行的JavaScript代码。
//然后，将code设置为qt.jQuery('object').remove()这段JavaScript代码。这段代码使用qt.jQuery选择器选中所有的<object>元素，并使用remove()方法
//将这些元素从DOM中移除，即从当前页面中移除所有的<object>元素。
//最后，使用view对象的page()方法获取当前页面的QWebEnginePage对象，并调用runJavaScript()方法来执行存储在code变量中的JavaScript代码。

void MainWindow::removeEmbeddedElements()
{
    QString code = QStringLiteral("qt.jQuery('embed').remove()");
    view->page()->runJavaScript(code);
    //在该函数中，首先创建了一个QString类型的变量code，用于存储要执行的JavaScript代码。
    //然后，将code设置为qt.jQuery('embed').remove()这段JavaScript代码。这段代码使用qt.jQuery选择器选中所有的<embed>元素，
    //并使用remove()方法将这些元素从DOM中移除，即从当前页面中移除所有的<embed>元素。
    //最后，使用view对象的page()方法获取当前页面的QWebEnginePage对象，并调用runJavaScript()方法来执行存储在code变量中的JavaScript代码。
}

void MainWindow::giftPOP()
{

    QString imagePath = ":/rotate.png";
    QLabel* labelImage = new QLabel(this, Qt::Dialog | Qt::WindowCloseButtonHint);
    labelImage->setAttribute(Qt::WA_DeleteOnClose);
    labelImage->setWindowTitle("application icon");

    QFileInfo file(imagePath);

    if (file.exists()) {
        QImage image;
        image.load(imagePath);

        labelImage->setFixedSize(300, 300); // 设置固定大小
        labelImage->setPixmap(QPixmap::fromImage(image.scaled(labelImage->size(), Qt::KeepAspectRatio)));
        labelImage->setScaledContents(true); // 图片自适应Label大小
    } else {
        qDebug() << "未找到该图片";
    }
    labelImage->show();
}

