//
//  2110_공유기 설치.cpp
//  Algorithms-CPP
//
//  Created by 장우진 on 2019/10/20.
//  Copyright © 2019 장우진. All rights reserved.
//

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int n, c;
    scanf("%d %d", &n, &c);
    vector<int> v(n);
    
    for (int i = 0; i < n; ++i)
        scanf("%d", &v[i]);
    
    sort(v.begin(), v.end());
    
    int lo = 1; // 최소 거리
    int hi = v[n - 1] - v[0]; // 최대 거리
    
    while (lo <= hi) {
        int mid = (lo + hi) / 2;
        int start = v[0];
        int cnt = 1;
        for (int i = 1; i < n; ++i) {
            if (v[i] - start >= mid) {
                cnt++;
                start = v[i];
            }
        }
        if (cnt >= c)
            lo = mid + 1;
        else
            hi = mid - 1;
    }
    printf("%d\n", hi);
    return 0;
}
