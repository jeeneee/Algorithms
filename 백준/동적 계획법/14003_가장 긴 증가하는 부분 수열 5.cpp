//
//  14003_가장 긴 증가하는 부분 수열 5.cpp
//  Algorithms-CPP
//
//  Created by 장우진 on 2020/01/28.
//  Copyright © 2020 장우진. All rights reserved.
//

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int lowerBound(int x, const vector<int>& v) {
    int lo = 0;
    int hi = static_cast<int>(v.size() - 1);
    while (lo <= hi) {
        int mid = (lo + hi) / 2;
        if (v[mid] >= x)
            hi = mid - 1;
        else
            lo = mid + 1;
    }
    return lo;
}

int main() {
    int n;
    scanf("%d", &n);
    vector<int> arr(n);
    vector<int> dp(n);
    vector<int> v;
    
    int k = 0;
    for (int i = 0; i < n; ++i) {
        scanf("%d", &arr[i]);
        if (v.empty() || arr[i] > v.back()) {
            v.push_back(arr[i]);
            dp[i] = k++;
        } else {
            int lb = lowerBound(arr[i], v);
            v[lb] = arr[i];
            dp[i] = lb;
        }
    }
    printf("%d\n", k);
    
    vector<int> ans;
    for (int i = n-1; i >= 0; --i) {
        if (dp[i] == k - 1) {
            ans.push_back(arr[i]);
            --k;
        }
    }
    
    for (auto it = ans.rbegin(); it != ans.rend(); ++it)
        printf("%d ", *it);
    printf("\n");
    
    return 0;
}
