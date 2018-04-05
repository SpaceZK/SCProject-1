#include "MainWindow.h"
#include "DataTypes.h"
#include <QApplication>

#ifdef _DATA_TEST_
int main(int argc, char *argv[]) {
    CuttingData cd;
    for(int i = 0; i < 10; i++) {
        cd.AddCuttingItem(i*i);
    }
    return 0;
}

#else
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    
    return a.exec();
}
#endif
