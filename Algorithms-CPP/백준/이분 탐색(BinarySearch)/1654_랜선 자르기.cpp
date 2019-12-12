//
//  1654_랜선 자르기.cpp
//  Algorithms-CPP
//
//  Created by 장우진 on 2019/10/18.
//  Copyright © 2019 장우진. All rights reserved.
//

#include <iostream>
using namespace std;

int main() {
    int k, n;
    long long int lo = 0, hi = 0;
    scanf("%d %d", &k, &n);
    int* wire = new int[k];
    
    for (int i = 0; i < k; ++i) {
        scanf("%d", &wire[i]);
        hi += wire[i];
    }
    
    bool flag = false;
    if (hi / n == 0) {
        printf("0\n");
        flag = true;
    }
    hi = hi / n + 1; // 반열린구간
    while (lo < hi && !flag) {
        long long int mid = (lo + hi) / 2;
        int cnt = 0;
        for (int i = 0; i < k; ++i)
            cnt += wire[i] / mid;
        if (cnt < n)
            hi = mid;
        else
            lo = mid + 1;
    }
    if (!flag)
        printf("%lld\n", lo - 1);
    
    delete []wire;
    return 0;
}
