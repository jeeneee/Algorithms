//
//  2352_반도체 설계.cpp
//  Algorithms-CPP
//
//  Created by 장우진 on 2020/01/06.
//  Copyright © 2020 장우진. All rights reserved.
//
/*
 LIS
 dp 배열의 원소는 LIS요소와 관계가 없다. 추적 불가.
 추적이 가능하게 하기 위해선 인덱스 트리를 이용해야 한다.
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
    vector<int> dp;
    
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }
    
    dp.push_back(arr[0]);
    for (int i = 1; i < n; ++i) {
        if (dp.back() < arr[i]) {
            dp.push_back(arr[i]);
            continue;
        }
        auto it = lower_bound(dp.begin(), dp.end(), arr[i]);
        *it = arr[i];
    }
    cout << (int)dp.size() << endl;
    
    return 0;
}
