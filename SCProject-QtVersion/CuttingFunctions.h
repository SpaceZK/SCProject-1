#ifndef CUTTINGFUNCTIONS_H
#define CUTTINGFUNCTIONS_H

#include <vector>

class CuttingFunctions
{
public:
    CuttingFunctions();
    
    bool AddCuttingLength(int len);
private:
    std::vector<int> m_tDataList;
    int m_iTotalLength;
};

#endif // CUTTINGFUNCTIONS_H