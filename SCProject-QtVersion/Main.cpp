#include "MainWindow.h"
#include "DataTypes.h"
#include "CoreDP.h"
#include <QApplication>
#include <iostream>
#include <vector>
using namespace std;

void GeneratorCuttingStrategy(CuttingData cd, CoreDP & cdp) {
    //first, change the cutting data to standard data
    
    vector<CoreDPItem> coreDPItems;
    cdp.ClearDPData();
    cdp.SetMaxCapacity(cd.GetOriginalLength() + cd.GetWasteLength());
    
    for(int i = 0; i < cd.GetCuttingItemCount(); i++) {
        CoreDPItem item;
        CuttingItem ci;
        item.cost = cd.GetCuttingItemByIndex(i, ci);
        item.value = item.cost = ci.length;
        coreDPItems.push_back(item);
    }
    
    cdp.GenerateResults(coreDPItems);
    
}

#if 1
int main(int argc, char *argv[]) {
    /*
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
    */
    int dd[] = {6, 7, 9, 8, 3};
    CuttingData cd;
    CoreDP cdp;
    
    for(int i = 0; i < 5; i++) {
        cd.AddCuttingItem(dd[i]);
    }
    cd.SetOriginalLength(10);
    cd.SetWasteLength(0);
    cdp.ClearDPData();
    
    GeneratorCuttingStrategy(cd, cdp);
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
