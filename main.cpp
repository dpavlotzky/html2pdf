#include <QApplication>
#include <QString>
#include <QUrl>

#include <iostream>

#include "pageprinter.h"

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    //QPrinterInfo printerInfo = QPrinterInfo::defaultPriner
    //QPrinter *printer = new QPrinter(QPrinterInfo::defaultPrinter());

    PagePrinter *view = new PagePrinter();
//    QWebView *view = new QWebView();
    view->settings()->setAttribute(QWebSettings::AutoLoadImages, true);
    view->load(QUrl(argv[1]));

    view->show();

    return app.exec();
}
