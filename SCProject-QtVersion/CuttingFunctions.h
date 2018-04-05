#ifndef CUTTINGFUNCTIONS_H
#define CUTTINGFUNCTIONS_H

#include <DataTypes.h>

std::list<int> DynamicProcessProtoData(std::list<int> data);

class CuttingFunctions
{
public:
    CuttingFunctions();
    CuttingData GenerateStatge();
private:
    CuttingData m_CuttingData;
};

#endif // CUTTINGFUNCTIONS_H