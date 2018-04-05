#include "DataTypes.h"
using namespace std;

bool CuttingData::AddCuttingItem(int length)
{
    list<CuttingItem>::iterator it = m_lstCuttingItems.begin();
    for( ; it != m_lstCuttingItems.end(); it++) {
        if((*it).length == length) {
            return false;
        }
    }
    CuttingItem ci(length, true);
    m_lstCuttingItem.push_back(ci);
    return true;
}

bool CuttingData::RemoveCuttingItem(int length)
{
    list<CuttingItem>::iterator it = m_lstCuttingItems.begin();
    for( ; it != m_lstCuttingItems.end(); it++) {
        if((*it).length == ci.length) {
            return false;
        }
    }
    m_lstCuttingItem.push_back(ci);
    return true;
}
