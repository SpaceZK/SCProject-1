#include "CuttingFunctions.h"
using namespace std;

CuttingFunctions::CuttingFunctions(int totalLength) {
    m_iTotalLength = totalLength;
}

CuttingData CuttingFunctions::GenerateStatge() {
    /************ DATA PREPROCESS *************/
    
}

int CuttingFunctions::GetTotalLength() {
    return m_iTotalLength;
}

void CuttingFunctions::SetTotalLength(int len) {
    m_iTotalLength = len;
}

list<ProtoType> CuttingFunctions::DynamicProcessCuttingData(std::list<ProtoType> data) {
    //data check
    if(m_iTotalLength <= 0) {
        return ans
    }
    
    list<ProtoType> ans;
}
