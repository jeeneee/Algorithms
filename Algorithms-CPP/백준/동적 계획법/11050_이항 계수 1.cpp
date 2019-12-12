//
//  11050_이항 계수 1.cpp
//  Algorithms-CPP
//
//  Created by 장우진 on 2019/10/28.
//  Copyright © 2019 장우진. All rights reserved.
//

#include <iostream>
#include <cstring>
#define MAX 11
using namespace std;

int cache[MAX][MAX];

int bino(int n, int r) {
    if (r == 0 || n == r) return 1;
    if (cache[n][r] != -1) return cache[n][r];
    return cache[n][r] = bino(n - 1, r - 1) + bino(n - 1, r);
}

int main() {
    memset(cache, -1, sizeof(cache));
    int n, k;
    cin >> n >> k;
    cout << bino(n, k) << endl;
    
    return 0;
}
