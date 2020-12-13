//
//  2133_타일 채우기.cpp
//  Algorithms-CPP
//
//  Created by 장우진 on 2019/11/08.
//  Copyright © 2019 장우진. All rights reserved.
//
/*
 점화식을 만들어야 풀 수 있는 문제.
 알고보면 쉽다.
 참조: https://www.algorithmist.com/index.php/UVa_10918#Summary
 */
#include <iostream>
#include <algorithm>
#include <climits>
#include <vector>
#include <cstring>
using namespace std;

#define integer unsigned long long

int main() {
    int n;
    integer T[31];
    T[0] = 1;
    cin >> n;
    
    if (n & 1) {
        cout << 0 << endl;
        return 0;
    }
    
    for (int i = 2; i <= n; i += 2) {
        T[i] = 3 * T[i - 2];
        for (int j = i - 4; j >= 0; j -= 2) {
            T[i] += (T[j] << 1);
        }
    }
    
    cout << T[n] << endl;
    
    return 0;
}
