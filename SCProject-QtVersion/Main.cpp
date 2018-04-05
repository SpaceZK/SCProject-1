#include "MainWindow.h"
#include "DataTypes.h"
#include <QApplication>
#include <iostream>
using namespace std;

#ifdef _DATA_TEST_
int main(int argc, char *argv[]) {
    CuttingData cd;
    for(int i = 0; i < 10; i++) {
        cd.AddCuttingItem(i*i);
    }
    
    for(int i = 0; i < cd.GetCuttingItemCount(); i++) {
        CuttingItem ci;
        cd.GetCuttingItemByIndex(i, ci);
        cout << "the item's length is: " << ci.length << " , " << "selected : " << ci.selected << endl;
    }
    
    for(int i = 0; i < cd.GetCuttingItemCount(); ) {
        CuttingItem ci;
        cd.GetCuttingItemByIndex(i, ci);
        cout << "ci.length%10 = " << ci.length%10 <<endl;
        cout << "ci.length%10%3 = " << ci.length%10%3 <<endl;
        if((ci.length%10)%3 == 0) {
            cout << "length : " << ci.length << "  has been removed" << endl;
            cd.RemoveCuttingItem(ci.length);
        } else {
            i++;
        }
    }
    
    cout << "------------------after process---------------------->>>>" << endl;
    
    
    for(int i = 0; i < cd.GetCuttingItemCount(); i++) {
        CuttingItem ci;
        cd.GetCuttingItemByIndex(i, ci);
        cout << "the item's length is: " << ci.length << " , " << "selected : " << ci.selected << endl;
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
