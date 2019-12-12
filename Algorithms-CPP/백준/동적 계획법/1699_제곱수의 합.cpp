//
//  1699_제곱수의 합.cpp
//  Algorithms-CPP
//
//  Created by 장우진 on 2019/11/05.
//  Copyright © 2019 장우진. All rights reserved.
//
/*
 동전 문제와 비슷함.
 예를 들면, dp[43]의 경우는 43의 최소 제곱 수인 3을 갖는다. (3^2 + 3^2 + 5^2 = 43)
 */
#include <iostream>
#include <algorithm>
#include <climits>
#include <vector>
using namespace std;

int main() {
    int n;
    cin >> n;
    int *dp = new int[n + 1];
    vector<int> arr;
    
    dp[0] = 0;
    for (int i = 1; i <= n; ++i)
        dp[i] = INT_MAX;
    
    for (int i = 1; i * i <= n; ++i)
        arr.push_back(i * i);
    
    for (int i = 0; i < arr.size(); ++i)
        for (int j = arr[i]; j <= n; ++j)
            dp[j] = min(dp[j], dp[j - arr[i]] + 1);
    
    cout << dp[n] << '\n';
    
    delete []dp;
    return 0;
}
