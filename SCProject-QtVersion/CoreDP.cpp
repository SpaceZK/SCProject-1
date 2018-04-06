#include "CoreDP.h"
#include <string.h>
#include <iostream>
#include <algorithm>
using namespace std;


CoreDP::CoreDP() {
    m_pDPData = new int *[COREDP_MAX_ITEMS];
    for(int i = 0; i < COREDP_MAX_ITEMS; i++) {
        m_pDPData[i] = new int[COREDP_MAX_CAPACITY_SIZE];
        memset(m_pDPData[i], 0, COREDP_MAX_CAPACITY_SIZE * sizeof(int));
    }
    
    m_pSelections = new bool[COREDP_MAX_ITEMS];
    memset(m_pSelections, 0, COREDP_MAX_ITEMS * sizeof(bool));
}

CoreDP::~CoreDP() {
    for(int i = 0; i < COREDP_MAX_ITEMS; i++) {
        delete m_pDPData[i];
    }
    delete [] m_pDPData;
    
    delete [] m_pSelections;
}

int CoreDP::GetMaxCapacity() {
    return m_iMaxCapacity;
}

void CoreDP::SetMaxCapacity(int cap) {
    m_iMaxCapacity = (cap >= COREDP_MAX_CAPACITY_SIZE)?(COREDP_MAX_CAPACITY_SIZE - 1):cap;
}

void CoreDP::ClearDPData() {
    for(int i = 0; i < COREDP_MAX_ITEMS; i++) {
        memset(m_pDPData[i], 0, COREDP_MAX_CAPACITY_SIZE * sizeof(int));
    }    
    memset(m_pSelections, 0, COREDP_MAX_ITEMS * sizeof(bool));
}

void CoreDP::GenerateResults(vector<CoreDPItem> data) {
    cout << "max capacity: " << m_iMaxCapacity << endl;
    cout << "item count: " << data.size() << endl;
    for(int i = 0; i < data.size(); i++) {
        for(int j = 0; j <= m_iMaxCapacity; j++) {
            if(j >= data[i].cost) {
                m_pDPData[i + 1][j] = max(m_pDPData[i][j], m_pDPData[i][j - data[i].cost] + data[i].value);
            } else {
                m_pDPData[i + 1][j] = m_pDPData[i][j];
            }
        }
    }
    cout << "The best result is : " << m_pDPData[data.size()][m_iMaxCapacity] << endl;
    
    int maxCap = m_iMaxCapacity;
    for(int i = data.size(); i >= 1; i--) {
        if(m_pDPData[i][maxCap] != m_pDPData[i - 1][maxCap]) {
            m_pSelections[i - 1] = true;
            maxCap -= data[i - 1].cost;
        }
    }
    
    vector<CoreDPItem> ans;
    for(int i = 0 ; i < data.size(); i++) {
        if(m_pSelections[i]) {
            cout << "the item: " << i << "  Has been selected." << endl; 
        }
    }
}

