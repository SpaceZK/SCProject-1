#ifndef COREDP_H
#define COREDP_H
#include <vector>

//#define _COREDP_DEBUG_

struct CoreDPItem {
    int cost;
    int value;
};

#define COREDP_MAX_CAPACITY_SIZE   2048
#define COREDP_MAX_ITEMS   1024

class CoreDP {
public:
    CoreDP();
    ~CoreDP();
    
    std::vector<CoreDPItem> GenerateResults(std::vector<CoreDPItem> data);
    
    int GetMaxCapacity();
    void SetMaxCapacity(int cap);
    
    void ClearDPData();
    
private:
    
    int m_iMaxCapacity;
    int **m_pDPData;
    bool *m_pSelections;
};

#endif // COREDP_H