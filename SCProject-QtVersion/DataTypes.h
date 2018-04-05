#ifndef DATATYPES_H
#define DATATYPES_H

#include <list>


class CuttingItem {
public:
    CuttingItem(int len = 0, bool sel = false) {
        length = len;
        selected = sel;
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
private:
    std::list<CuttingItem> m_lstCuttingItems;
};

#endif // DATATYPES_H