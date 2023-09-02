#include <QtWidgets>
#include <QtWebEngineWidgets>
#include "browser.h"

//引入了Qt Widgets模块和Qt WebEngineWidgets模块，以及自定义的mainwindow.h头文件。

#include <QDialog>
#include <QLabel>
#include <QVBoxLayout>


MainWindow::MainWindow(const QUrl& url)
{
    setAttribute(Qt::WA_DeleteOnClose, true);
    progress = 0;

    QFile file(":/jquery.min.js");
    if (file.open(QIODevice::ReadOnly)) {
        jQuery = file.readAll();
        jQuery.append("\nvar qt = { 'jQuery': jQuery.noConflict(true) };");
        file.close();

        view = new QWebEngineView(this);
        view->load(url);
        connect(view, &QWebEngineView::loadFinished, this, &MainWindow::adjustLocation);
        connect(view, &QWebEngineView::titleChanged, this, &MainWindow::adjustTitle);
        connect(view, &QWebEngineView::loadProgress, this, &MainWindow::setProgress);
        connect(view, &QWebEngineView::loadFinished, this, &MainWindow::finishLoading);

        locationEdit = new QLineEdit(this);
        locationEdit->setSizePolicy(QSizePolicy::Expanding, locationEdit->sizePolicy().verticalPolicy());

        connect(locationEdit, &QLineEdit::returnPressed, this, &MainWindow::changeLocation);
        //回车键与链接更改相对应

        QToolBar *toolBar = addToolBar(tr("Navigation"));
        toolBar->addAction(view->pageAction(QWebEnginePage::Back));
        toolBar->addAction(view->pageAction(QWebEnginePage::Forward));
        toolBar->addAction(view->pageAction(QWebEnginePage::Reload));
        toolBar->addAction(view->pageAction(QWebEnginePage::Stop));
        toolBar->addWidget(locationEdit);

        QMenu *viewMenu = menuBar()->addMenu(tr("&View"));
        QAction *viewSourceAction = new QAction(tr("Page Source"), this);
        connect(viewSourceAction, &QAction::triggered, this, &MainWindow::viewSource);
        viewMenu->addAction(viewSourceAction);

        QMenu *effectMenu = menuBar()->addMenu(tr("&Effect"));
        effectMenu->addAction(tr("Highlight all links"), this, &MainWindow::highlightAllLinks);

        rotateAction = new QAction(this);
        rotateAction->setIcon(style()->standardIcon(QStyle::SP_FileDialogDetailedView));
        rotateAction->setCheckable(true);
        rotateAction->setText(tr("Turn images upside down"));
        connect(rotateAction, &QAction::toggled, this, &MainWindow::rotateImages);
        effectMenu->addAction(rotateAction);

        QMenu *toolsMenu = menuBar()->addMenu(tr("&Tools"));
        toolsMenu->addAction(tr("Remove GIF images"), this, &MainWindow::removeGifImages);
        toolsMenu->addAction(tr("Remove all inline frames"), this, &MainWindow::removeInlineFrames);
        toolsMenu->addAction(tr("Remove all object elements"), this, &MainWindow::removeObjectElements);
        toolsMenu->addAction(tr("Remove all embedded elements"), this, &MainWindow::removeEmbeddedElements);

        QMenu *giftMenu = menuBar()->addMenu(tr("Gift"));
        QAction *giftAction = new QAction(tr("Pop Window"), this);
        QAction *dialogueAction = new QAction(tr("Create New Page"), this);
        giftMenu->addAction(giftAction);
        giftMenu->addAction(dialogueAction);
        connect(giftAction, &QAction::triggered, this, &MainWindow::giftPOP);
        connect(dialogueAction, &QAction::triggered, this, &MainWindow::createWindow);

        QMenu *bookmarkMenu = menuBar()->addMenu(tr("Bookmark"));
        QAction *addMarkAction = new QAction(tr("Add Mark"), this);
        bookmarkMenu->addAction(addMarkAction);
        connect(addMarkAction, &QAction::triggered, this, &MainWindow::addMarkWindowx);

        setCentralWidget(view);
    }
}


