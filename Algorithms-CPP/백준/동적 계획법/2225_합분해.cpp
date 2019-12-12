//
//  2225_합분해.cpp
//  Algorithms-CPP
//
//  Created by 장우진 on 2019/11/09.
//  Copyright © 2019 장우진. All rights reserved.
//

#include <iostream>
using namespace std;

#define integer unsigned long long

const int mod = 1000000000;
integer d[201][201]; // [k][n]

int main() {
    int n, k;
    cin >> n >> k;
    
    for (int i = 0; i <= n; ++i)
        d[1][i] = 1;
    
    for (int i = 2; i <= k; ++i) {
        for (int j = 0; j <= n; ++j) {
            for (int t = 0; t <= j; ++t) {
                d[i][j] += d[i - 1][j - t];
                d[i][j] %= mod;
            }
        }
    }
    
    cout << d[k][n] << endl;
    
    return 0;
}
