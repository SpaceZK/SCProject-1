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
    
    int GetOriginalLength();
    void SetOriginalLength(int len);
    
    int GetWasteLength();
    void SetWasteLength(int len);
    
    bool AddCuttingItem(int length);
    bool RemoveCuttingItem(int length);
    bool GetCuttingItemByIndex(int index, CuttingItem & ci);
    int GetCuttingItemCount(void);
private:
    std::list<CuttingItem> m_lstCuttingItems;
    int m_iOriginalLength;
    int m_iCuttingWaste;
};

#endif // DATATYPES_H