#include "CuttingFunctions.h"
using namespace std;

CuttingFunctions::CuttingFunctions() {
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

int CuttingFunctions::GetWasteLength() {
    return m_iCuttingWaste;
}

void CuttingFunctions::SetWasteLength(int len) {
    m_iCuttingWaste = len;
}

bool CuttingFunctions::DynamicProcessCuttingData() {
    //data check
    if(m_CuttingData.GetOriginalLength() <= 0) {
        return false;
    }
    if(m_CuttingData.GetCuttingItemCount() <= 0) {
        return false;
    }
    
    //check data finished
    list<ProtoType> ans;
    
    //construct cutting data to proto data
    
    return true;
}
