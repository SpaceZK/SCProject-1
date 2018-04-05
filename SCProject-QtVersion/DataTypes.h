#ifndef DATATYPES_H
#define DATATYPES_H

#include <list>
#define _DATA_TEST_

class CuttingItem {
public:
    CuttingItem(int len = 0, bool sel = false) {
        length = len;
        selected = sel;
    }
    bool operator == (const CuttingItem & r) {
        return length == r.length;
    }

    int length;
    bool selected;
    
};

class CuttingData {
public:
    CuttingData();
    ~CuttingData();
    
    bool AddCuttingItem(int length);
    bool RemoveCuttingItem(int length);
    bool GetCuttingItemByIndex(int index, CuttingItem & ci);
private:
    std::list<CuttingItem> m_lstCuttingItems;
};

#endif // DATATYPES_H