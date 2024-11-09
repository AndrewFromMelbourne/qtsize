//-------------------------------------------------------------------------
//
// The MIT License (MIT)
//
// Copyright (c) 2024 Andrew Duncan
//
// Permission is hereby granted, free of charge, to any person obtaining a
// copy of this software and associated documentation files (the
// "Software"), to deal in the Software without restriction, including
// without limitation the rights to use, copy, modify, merge, publish,
// distribute, sublicense, and/or sell copies of the Software, and to
// permit persons to whom the Software is furnished to do so, subject to
// the following conditions:
//
// The above copyright notice and this permission notice shall be included
// in all copies or substantial portions of the Software.
//
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS
// OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF
// MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.
// IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY
// CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT,
// TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE
// SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
//
//-------------------------------------------------------------------------

#include <QApplication>
#include <QKeyEvent>

#include "MainWindow.h"

// ------------------------------------------------------------------------

MainWindow::MainWindow(QWidget* parent)
:
    QMainWindow(parent)
{
}

// ------------------------------------------------------------------------

MainWindow::~MainWindow()
{
}

// ------------------------------------------------------------------------

void
MainWindow::keyPressEvent(QKeyEvent* event)
{
    switch (event->key())
    {
       case Qt::Key_Escape:

            QCoreApplication::quit();

            break;

        case Qt::Key_F11:

            if (windowState() == Qt::WindowFullScreen)
            {
                showNormal();
            }
            else
            {
                showFullScreen();
            }

            break;

        default:

            break;
    }
}

// ------------------------------------------------------------------------

void
MainWindow::paintEvent(QPaintEvent* event)
{
    const auto size{24};
    auto font{QFont("Quicksand", size)};
    QFontMetrics qfm{font};

    auto annotation = QString("%1 x %2").arg(QString::number(width()),
                                             QString::number(height()));

    const auto x = (width() - qfm.horizontalAdvance(annotation)) / 2;
    const auto y = (height() + qfm.height()) / 2;

    QPainter painter(this);
    painter.setPen(QPen(Qt::black));
    painter.setFont(font);
    painter.drawText(x, y, annotation);
}

