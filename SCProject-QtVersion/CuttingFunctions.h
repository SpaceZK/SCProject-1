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
    CuttingFunctions(int totalLength = 0);
    CuttingData GenerateStatge();
    int GetTotalLength(void);
    void SetTotalLength(int len);
private:
    int m_iTotalLength;
    CuttingData m_CuttingData;
    bool DynamicProcessProtoData(std::list<ProtoType> data);
};

#endif // CUTTINGFUNCTIONS_H