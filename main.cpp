// Include header files
#include "mainwindow.h"
// QApplication handles widgets, event handling, and look of windows
#include <QApplication>

int main(int argc, char *argv[])
{
    // QApplication object a created
    QApplication a(argc, argv);
    // Create main application object w
    MainWindow w;
    // Display w to screen
    w.show();

    // Loops application events to be handled
    return a.exec();
}
