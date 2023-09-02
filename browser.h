#include <QtWidgets>
#include <QtWebEngineWidgets>
//该行包含了 Qt 的 QtWidgets 模块，其中包含创建用户界面所需的类。


QT_BEGIN_NAMESPACE
class QWebEngineView;
class QLineEdit;
QT_END_NAMESPACE
//这是使用了前置声明来声明 QWebEngineView 和 QLineEdit 类，它们是属于 Qt 的子模块 QWebEngine 的类。这些类用于显示网页内容和处理用户交互。


class MainWindow : public QMainWindow//这是一个自定义的类 MainWindow，继承自 QMainWindow 类。该类代表了整个应用程序的主窗口。
{
    Q_OBJECT//这是一个宏，用于启用 Qt 的元对象系统 (Meta-Object System)，以便进行信号与槽的连接和其他元对象功能的支持。

public:
    MainWindow(const QUrl& url);//这是 MainWindow 类的构造函数声明，它接受一个 QUrl 类型的参数，并用于创建 MainWindow 的实例。

protected slots:

    void adjustLocation();
    void changeLocation();
    void changeLocation2();
    void adjustTitle();
    void setProgress(int p);
    void finishLoading(bool);
    void viewSource();
    void highlightAllLinks();
    void rotateImages(bool invert);
    void removeGifImages();
    void removeInlineFrames();
    void removeObjectElements();
    void removeEmbeddedElements();
    void giftPOP();
    void createWindow();
    void addMarkWindowx();

    // 声明了一系列的槽函数，用于响应不同的信号事件

private:
    QString jQuery;
    QString message;
    QWebEngineView *view;
    QWebEngineView *view2;
    QLineEdit *locationEdit;
    QLineEdit * te1;
    QAction *rotateAction;
    int progress;
    QListWidget* list;
    QStackedWidget* stack;
    QTextEdit* text1;
    QTextEdit* text2;
    QTextEdit* text3;
    // 定义了一些私有成员变量，用于保存窗口中的各种控件和数据
};
