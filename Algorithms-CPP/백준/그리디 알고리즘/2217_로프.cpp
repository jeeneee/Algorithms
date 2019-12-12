//
//  2217_로프.cpp
//  Algorithms-CPP
//
//  Created by 장우진 on 10/10/2019.
//  Copyright © 2019 장우진. All rights reserved.
//

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int n;
    cin >> n;
    int * w = new int[n];
    
    for (int i = 0; i < n; ++i) {
        cin >> w[i];
    }
    
    sort(w, w + n);
    
    int maxWeight = 0;
    for (int i = 0; i < n; ++i) {
        if (w[i] * (n - i) > maxWeight) {
            maxWeight = w[i] * (n - i);
        }
    }
    
    cout << maxWeight << endl;
    
    delete []w;
    return 0;
}
