#include "MainWindow.h"
#include "DataTypes.h"
#include "CoreDP.h"
#include <QApplication>
#include <iostream>
#include <vector>
using namespace std;

#ifdef _COREDP_DEBUG_
int main(int argc, char *argv[]) {
    
    CoreDP cdp;
    cdp.ClearDPData();
    cdp.SetMaxCapacity(10);
    int c[] = {2, 2, 6, 5, 4};
    int v[] = {6, 3, 5, 4, 6};
    vector<CoreDPItem> dpItems;
    CoreDPItem cdpi;
    for(int i = 0; i < 5; i++) {
        cdpi.cost = c[i];
        cdpi.value = v[i];
        dpItems.push_back(cdpi);
    }
    cdp.GenerateResults(dpItems);
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
