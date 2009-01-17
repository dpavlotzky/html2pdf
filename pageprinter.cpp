/*
 * Copyright 2009 onlinerapporten.nl
 *
 *  This file is part of html2pdf.
 *
 *  html2pdf is free software: you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation, either version 3 of the License, or
 *  (at your option) any later version.
 *
 *  html2pdf is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License
 *  along with html2pdf.  If not, see <http://www.gnu.org/licenses/>.
 */

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
   this->settings()->setAttribute(QWebSettings::JavascriptEnabled, false);
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
