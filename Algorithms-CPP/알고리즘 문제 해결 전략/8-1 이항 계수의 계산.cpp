//
//  8-1 이항 계수의 계산.cpp
//  Algorithms-CPP
//
//  Created by 장우진 on 2019/10/28.
//  Copyright © 2019 장우진. All rights reserved.
//

#include <iostream>
using namespace std;
int cache[30][30];
int cnt1 = 0;
int cnt2 = 0;

/* 코드 8.1 재귀 호출을 이용한 이항 계수의 계산 */
int bino(int n, int r) {
    ++cnt1;
    if (r == 0 || n == r) return 1;
    return bino(n - 1, r - 1) + bino(n - 1, r);
}

/* 코드 8.2 메모이제이션(memoization)을 이용한 이항 계수의 계산 */
int bino2(int n, int r) {
    ++cnt2;
    if (r == 0 || n == r) return 1;
    if (cache[n][r] != -1)
        return cache[n][r];
    return cache[n][r] = bino2(n - 1, r - 1) + bino2(n - 1, r);
}

int main() {
    for (int i = 0; i < 30; ++i) {
        for (int j = 0; j < 30; ++j) {
            cache[i][j] = -1;
        }
    }
    cout << bino(12, 4) << " cnt1: " << cnt1 << endl;
    cout << bino2(12, 4) << " cnt2: " << cnt2 << endl;
    
    return 0;
}
