#ifndef CUTTINGFUNCTIONS_H
#define CUTTINGFUNCTIONS_H

#include <DataTypes.h>

class CuttingFunctions
{
public:
    CuttingFunctions();
    
private:
    CuttingData m_CuttingData;
    void __PreprocessCuttingData();
};

#endif // CUTTINGFUNCTIONS_H