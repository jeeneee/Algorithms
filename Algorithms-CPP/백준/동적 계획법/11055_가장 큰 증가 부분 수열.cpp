//
//  11055_가장 큰 증가 부분 수열.cpp
//  Algorithms-CPP
//
//  Created by 장우진 on 2019/11/03.
//  Copyright © 2019 장우진. All rights reserved.
//

#include <iostream>
#include <cstring>
#include <algorithm>
#define MAX 1000
using namespace std;

int dp[MAX];
int arr[MAX];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int n;
    cin >> n;
    
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }
    
    dp[0] = arr[0];
    for (int i = 0; i < n; ++i) {
        bool flag = false;
        for (int j = i - 1; j >= 0; --j) {
            if (arr[j] < arr[i] && dp[j] + arr[i] > dp[i]) {
                dp[i] = dp[j] + arr[i];
                flag = true;
            }
        }
        if (!flag) dp[i] = arr[i];
    }
    
    int ans = 0;
    for (int i = 0; i < n; ++i) {
        ans = max(ans, dp[i]);
    }
    cout << ans << '\n';
    
    return 0;
}

