#include "browser.h"

void MainWindow::addMarkWindowx()
{
    QWidget* widgetx = new QWidget();
    widgetx->setWindowTitle(tr("bookmark"));

    QPushButton* pushButton = new QPushButton(tr("add"));
    QPushButton* deleteButton = new QPushButton(tr("delete"));
    QListWidget* list = new QListWidget();
    QStackedWidget* stack = new QStackedWidget();

    static int num = 0;

    connect(pushButton, &QPushButton::clicked, [=]() {
        QString windowTitle = tr("mark") + QString::number(num+1);
        QListWidgetItem* listItem = new QListWidgetItem(windowTitle);
        list->addItem(listItem);

        QTextEdit* textEdit = new QTextEdit();
        textEdit->setText("Please edit here to store your website!\n"
                          "At the same time you can state the traits of "
                          "the website you like. ");
        stack->addWidget(textEdit);

        connect(textEdit, &QTextEdit::textChanged, widgetx, [=]() {
            if (list->count() > 0) {
                QListWidgetItem* currentItem = list->currentItem();
                if (currentItem != nullptr)
                    currentItem->setText(textEdit->toPlainText());
            }
        });

        list->setCurrentItem(listItem);
        num++;
    });

    connect(deleteButton, &QPushButton::clicked, [=]() {
        int currentIndex = list->currentRow();
        if (currentIndex >= 0) {
            list->takeItem(currentIndex);
            stack->removeWidget(stack->currentWidget());
        }
    });

    QSplitter* splitter = new QSplitter();
    splitter->addWidget(list);
    splitter->addWidget(stack);

    QVBoxLayout* buttonLayout = new QVBoxLayout();
    buttonLayout->addWidget(pushButton);
    buttonLayout->addWidget(deleteButton);
    QWidget* buttonsContainer = new QWidget();
    buttonsContainer->setLayout(buttonLayout);

    QHBoxLayout* mainLayout = new QHBoxLayout(widgetx);
    mainLayout->setMargin(5);
    mainLayout->setSpacing(5);
    mainLayout->addWidget(splitter);
    mainLayout->addWidget(buttonsContainer);

    connect(list, &QListWidget::currentRowChanged, stack, &QStackedWidget::setCurrentIndex);

    widgetx->resize(800, 600);
    widgetx->show();
}
