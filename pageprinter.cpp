#include <QPrinterInfo>

#include "pageprinter.h"

#include <iostream>

PagePrinter::PagePrinter(QWidget *parent) : QWebView(parent)
{
   QObject::connect(this, SIGNAL(loadFinished(bool)), this, SLOT(doPrint(bool)));
}

void PagePrinter::doPrint(bool ok)
{
   if (! ok)
   {
       std::cout << "Page could not be loaded" ;
       QCoreApplication::exit(1);
   }

   this->settings()->setAttribute(QWebSettings::PrintBackgrounds, true);
   //this->settings()->setAttribute(QWebSettings::AutoLoadImages, true);
   QPrinter *printer = new QPrinter(QPrinterInfo::defaultPrinter(), QPrinter::ScreenResolution);
   printer->setFontEmbeddingEnabled(true);
   printer->setOutputFormat(QPrinter::PdfFormat);
   printer->setFullPage(true);
   QTemporaryFile file;
   if (! file.open())
      exit(1);
   QString output = file.fileName().append(".pdf");
   printer->setOutputFileName(output);
   print(printer);
   std::cout << output.toLatin1().data();
   QCoreApplication::exit(0);
}
