//
//  11054_가장 긴 바이토닉 부분 수열.cpp
//  Algorithms-CPP
//
//  Created by 장우진 on 2019/11/05.
//  Copyright © 2019 장우진. All rights reserved.
//
/*
 왼쪽에서 오른쪽으로 증가 부분 수열 검사 dp1
 오른쪽에서 왼쪽으로 증가 부분 수열 검사 dp2
 */
#include <iostream>
#include <cstring>
#include <algorithm>
#define MAX 1000
using namespace std;

int dp1[MAX];
int dp2[MAX];
int arr[MAX];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int n;
    cin >> n;
    
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }
    
    for (int i = 0; i < n; ++i) {
        dp1[i] = 1;
        dp2[i] = 1;
    }
    
    for (int i = 0; i < n; ++i) {
        for (int j = i - 1; j >= 0; --j) {
            if (arr[j] < arr[i] && dp1[j] + 1 > dp1[i])
                dp1[i] = dp1[j] + 1;
        }
    }

    for (int i = n - 1; i >= 0; --i) {
        for (int j = i + 1; j < n; ++j) {
            if (arr[j] < arr[i] && dp2[j] + 1 > dp2[i])
                dp2[i] = dp2[j] + 1;
        }
    }
    
    int ans = 0;
    for (int i = 0; i < n; ++i) {
        ans = max(ans, dp1[i] + dp2[i]);
    }
    
    cout << ans - 1 << '\n';
    
    return 0;
}
