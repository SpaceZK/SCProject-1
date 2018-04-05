#include "MainWindow.h"
#include "DataTypes.h"
#include <QApplication>

#ifdef _DATA_TEST_

#else
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    
    return a.exec();
}
#endif
