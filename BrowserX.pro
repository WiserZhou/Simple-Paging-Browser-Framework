QT      +=  webenginewidgets

#这一行指示项目使用 Qt 的 WebEngineWidgets 模块，该模块提供了在应用程序中显示和操作网络内容（如网页）的功能。

HEADERS =   \
    browser.h

SOURCES =   main.cpp\
           JSfunction.cpp \
           WebFunction.cpp \
           addMark.cpp \
           browser.cpp \
           createNew.cpp

#这两行指定项目中需要编译的头文件（.h 文件）和源文件（.cpp 文件）。在这个例子中，mainwindow.h 是主窗口类的头文件，main.cpp 和 mainwindow.cpp 是对应的源文件。

RESOURCES = jquery.qrc

#这一行指定项目中使用的资源文件。在这个例子中，jquery.qrc 是一个资源文件，其中包含了应用程序中使用的 jQuery 库。资源文件会在编译时被嵌入到应用程序中，
#以便在运行时访问其中的内容。

# Disable Qt Quick compiler because the example doesn't use QML, but more importantly so that
# the source code of the .js files is not removed from the embedded qrc file.
CONFIG -= qtquickcompiler
#这一行禁用了 Qt Quick 编译器，因为这个例子不使用 QML（Qt 快速创建语言），同时它也确保嵌入到 qrc 文件中的 .js 文件的源代码不会被移除。

# install
target.path = C:/Users/86186/Desktop
INSTALLS += target
#这两行指示在安装构建后的目标文件时，将其复制到指定的文件夹中。target.path 是目标文件的安装路径，INSTALLS += target 将 target 添加到安装阶段的操作列表中。


#使用DISTFILES变量将文件添加到项目中进行分发

RC_ICONS = favicon.ico
#设置软件的图标
