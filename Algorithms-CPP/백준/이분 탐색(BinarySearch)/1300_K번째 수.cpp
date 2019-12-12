//
//  1300_K번째 수.cpp
//  Algorithms-CPP
//
//  Created by 장우진 on 2019/12/11.
//  Copyright © 2019 장우진. All rights reserved.
//

#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int n, k;
    cin >> n >> k;
    
    int lo = 1, hi = k;
    int ans = 0;
    while (lo <= hi) {
        int mid = (lo + hi) / 2;
        long long cnt = 0;
        for (int i = 1; i <= n; ++i)
            cnt += min(mid / i, n);
        if (cnt < k)
            lo = mid + 1;
        else {
            hi = mid - 1;
            ans = mid;
        }
    }
    cout << ans << endl;
    return 0;
}
