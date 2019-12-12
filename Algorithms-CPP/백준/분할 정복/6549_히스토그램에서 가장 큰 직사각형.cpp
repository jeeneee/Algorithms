//
//  6549_히스토그램에서 가장 큰 직사각형.cpp
//  Algorithms-CPP
//
//  Created by 장우진 on 2019/10/28.
//  Copyright © 2019 장우진. All rights reserved.
//

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

long long solve(int left, int right, const vector<long long>& h) {
    // 기저 사례: 하나의 막대만 있을 경우
    if (left == right) return h[left];
    int mid = (left + right) / 2;
    // 분할
    long long ret = max(solve(left, mid, h), solve(mid + 1, right, h));
    // 부분 문제: 분할된 두 부분에 겹치는 사각형 중 가장 큰 것을 찾는다.
    int lo = mid, hi = mid + 1;
    long long height = min(h[lo], h[hi]);
    ret = max(ret, (long long)height * 2);
    while (left < lo || right > hi) {
        if (hi < right && ((lo == left) || h[lo - 1] < h[hi + 1])) {
            hi++;
            height = min(height, h[hi]);
        }
        else {
            lo--;
            height = min(height, h[lo]);
        }
        ret = max(ret, height * (hi - lo + 1));
    }
    return ret;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    while (true) {
        int n;
        cin >> n;
        if (n == 0) break;
        vector<long long> h(n);
        for (int i = 0; i < n; ++i) {
            cin >> h[i];
        }
        cout << solve(0, n - 1, h) << '\n';
    }
    return 0;
}
