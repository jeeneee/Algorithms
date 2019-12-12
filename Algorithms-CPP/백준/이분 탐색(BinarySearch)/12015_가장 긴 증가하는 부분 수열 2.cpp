//
//  12015_가장 긴 증가하는 부분 수열 2.cpp
//  Algorithms-CPP
//
//  Created by 장우진 on 2019/12/11.
//  Copyright © 2019 장우진. All rights reserved.
//

/*
 정렬되어있고 수의 크기에 맞는 위치 찾을 때는 이분 탐색을 꼭 떠올려야 한다.
 */

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int lowerBound(int x, const vector<int>& v) {
    int lo = 0;
    int hi = (int)v.size() - 1;
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
    int n, x;
    scanf("%d", &n);
    vector<int> v;
    for (int i = 0; i < n; ++i) {
        scanf("%d", &x);
        if (v.empty() || x > v.back())
            v.push_back(x);
        else
            v[lowerBound(x, v)] = x;
//        else {
//            auto it = lower_bound(v.begin(), v.end(), x);
//            *it = x;
//        }
    }
    printf("%d\n", (int)v.size());
    return 0;
}
