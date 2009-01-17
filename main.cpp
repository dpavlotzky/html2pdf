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

#include <QApplication>
#include <QString>
#include <QUrl>

#include <iostream>

#include "pageprinter.h"

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    PagePrinter *view = new PagePrinter();
    view->settings()->setAttribute(QWebSettings::AutoLoadImages, true);
    view->load(QUrl(argv[1]));

    view->show();

    return app.exec();
}
