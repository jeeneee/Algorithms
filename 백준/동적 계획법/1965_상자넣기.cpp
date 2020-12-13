//
//  1965_상자넣기.cpp
//  Algorithms-CPP
//
//  Created by 장우진 on 2020/01/06.
//  Copyright © 2020 장우진. All rights reserved.
//
/*
 LIS
 */
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL);
    
    int n;
    cin >> n;
    vector<int> arr(n);
    vector<int> dp(n, 1);
    
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }
    
    int ans = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = i-1; j >= 0; --j) {
            if (arr[i] > arr[j])
                dp[i] = max(dp[i], dp[j] + 1);
        }
        ans = max(ans, dp[i]);
    }
    cout << ans << endl;
    
    return 0;
}
