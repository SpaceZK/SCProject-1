#include "CuttingFunctions.h"
#include <string.h>
#include <iostream>
using namespace std;

std::vector<CuttingItem> GeneratorCuttingStrategy(CuttingData cd, CoreDP cdp) {
    //first, change the cutting data to standard data
    vector<CoreDPItem> coreDPItems;
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
