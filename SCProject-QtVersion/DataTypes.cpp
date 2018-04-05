#include "DataTypes.h"
using namespace std;

CuttingData::CuttingData() {
    
}

CuttingData::~CuttingData() {
    
}

bool CuttingData::AddCuttingItem(int length) {
    list<CuttingItem>::iterator it = m_lstCuttingItems.begin();
    for( ; it != m_lstCuttingItems.end(); it++) {
        if((*it).length == length) {
            return false;
        }
    }
    CuttingItem ci(length, true);
    m_lstCuttingItems.push_back(ci);
    return true;
}

bool CuttingData::RemoveCuttingItem(int length) {
    list<CuttingItem>::iterator it = m_lstCuttingItems.begin();
    for( ; it != m_lstCuttingItems.end(); it++) {
        if((*it).length == length) {
            m_lstCuttingItems.remove(*it);
            return true;
        }
    }
    return false;
}

bool CuttingData::GetCuttingItemByIndex(int index, CuttingItem & ci) {
    if(index >= m_lstCuttingItems.size() || index < 0)
        return false;
    
    list<CuttingItem>::iterator it = m_lstCuttingItems.begin();
    for(int i = 0;i < index; i++) {
        it++;
    }
    ci = *it;
    return true;
}
