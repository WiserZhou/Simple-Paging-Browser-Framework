#include "browser.h"

void MainWindow::createWindow()
{
    static int name = 1;
    QDockWidget *dock = new QDockWidget(tr("New Window") + QString::number(name), this);
    name++;
    dock->setFeatures(QDockWidget::AllDockWidgetFeatures);
    dock->setAllowedAreas(Qt::AllDockWidgetAreas);

    QWidget *dockContents = new QWidget(dock);
    QVBoxLayout *layout = new QVBoxLayout(dockContents);

    te1 = new QLineEdit();
    te1->setText(tr("https://cn.bing.com/?scope=web&FORM=HDRSC1&mkt=zh-CN"));
    te1->setSizePolicy(QSizePolicy::Expanding, te1->sizePolicy().verticalPolicy());
    connect(te1, &QLineEdit::returnPressed, this, &MainWindow::changeLocation2);
    layout->addWidget(te1);

    QUrl url;
    if (te1->text().size() > 1)
        url = QUrl::fromUserInput(te1->text());
    else
        url = QUrl("https://cn.bing.com/?scope=web&FORM=HDRSC1&mkt=zh-CN");
    view2 = new QWebEngineView(dockContents);
    view2->load(url);

    QToolBar *toolBar = new QToolBar(tr("Navigation"), this);
    toolBar->addAction(view2->pageAction(QWebEnginePage::Back));
    toolBar->addAction(view2->pageAction(QWebEnginePage::Forward));
    toolBar->addAction(view2->pageAction(QWebEnginePage::Reload));
    toolBar->addAction(view2->pageAction(QWebEnginePage::Stop));
    toolBar->addWidget(te1);

    layout->addWidget(toolBar);
    layout->addWidget(view2);

    dock->setWidget(dockContents);
    this->addDockWidget(Qt::RightDockWidgetArea, dock);

    connect(view2, &QWebEngineView::titleChanged, dock ,[=]() {
        connect(view2, &QWebEngineView::loadProgress, dock, [=](int p) {
            if (p >= 0 && p < 100) {
                dock->setWindowTitle(QStringLiteral("%1 (%2%)").arg(view2->title()).arg(p));
            } else {
                dock->setWindowTitle(view2->title());
            }
        });
    });

}
