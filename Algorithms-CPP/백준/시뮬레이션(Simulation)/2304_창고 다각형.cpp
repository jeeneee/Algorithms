//
//  2304_창고 다각형.cpp
//  Algorithms-CPP
//
//  Created by 장우진 on 2020/10/25.
//  Copyright © 2020 장우진. All rights reserved.
//

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int A[1005];

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int n, left = 1000, right = 0, highest = 0;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        int l, h;
        cin >> l >> h;
        A[l] = h;
        left = min(left, l);
        right = max(right, l);
        highest = max(highest, h);
    }
    int lo, hi;
    for (lo = left; A[lo] != highest; ++lo)
    if (A[lo+1] < A[lo])
        A[lo+1] = A[lo];
    for (hi = right; A[hi] != highest; --hi)
    if (A[hi-1] < A[hi])
        A[hi-1] = A[hi];
    for (int i = lo + 1; i < hi; ++i)
    A[i] = highest;
    
    int answer = 0;
    for (int i = left; i <= right; ++i)
    answer += A[i];
    cout << answer << endl;
    return 0;
}
