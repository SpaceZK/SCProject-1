#include "CuttingFunctions.h"
#include <string.h>
#include <iostream>
using namespace std;

list<int> DynamicProcessProtoData(list<int> data, int originalLength) {
    int *result = new int[originalLength + 1];
    memset(result, 0, (originalLength + 1)*sizeof(int));
    for(list<int> ::iterator it = data.begin(); it != data.end(); it++) {
        for(int i = *it; i <= originalLength; i++) {
            if(result[i] < result[i - (*it)] + (*it)) {
                result[i] = result[i - (*it)] + (*it);
            }
        }
    }
    //print the best result
    list<int> ans;
    cout << "the best result is : " << result[originalLength] << endl;
    return ans;
}

CuttingFunctions::CuttingFunctions() {
}

CuttingData CuttingFunctions::GenerateStatge() {
    /************ DATA PREPROCESS *************/
    
}
