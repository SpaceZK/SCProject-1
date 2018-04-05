#ifndef CUTTINGFUNCTIONS_H
#define CUTTINGFUNCTIONS_H

#include <DataTypes.h>

struct ProtoType {
    ProtoType(int c = 0, int v = 0) {
        cost = c;
        value = v;
    }

    int cost;
    int value;
};

class CuttingFunctions
{
public:
    CuttingFunctions();
    CuttingData GenerateStatge();
private:
    CuttingData m_CuttingData;
    bool DynamicProcessProtoData();
};

#endif // CUTTINGFUNCTIONS_H