//
//  2805_나무 자르기.cpp
//  Algorithms-CPP
//
//  Created by 장우진 on 2019/10/18.
//  Copyright © 2019 장우진. All rights reserved.
//

#include <iostream>
using namespace std;

int main() {
    int n, m, lo = 0, hi = 0;   // n: 나무의 수, m: 필요한 나무의 길이
    scanf("%d %d", &n, &m);
    int * tree = new int[n];
    for (int i = 0; i < n; ++i) {
        scanf("%d", &tree[i]);
        if (tree[i] > hi)
            hi = tree[i];
    }
    hi++;   // 반열린구간
    while (lo < hi) {
        int mid = (int)((long long int)lo + hi) / 2;
        long long int len = 0;
        for (int i = 0; i < n; ++i)
            if (tree[i] > mid)
                len += tree[i] - mid;
        if (len < m)
            hi = mid;
        else
            lo = mid + 1;
    }
    printf("%d\n", hi - 1);
    
    delete []tree;
    return 0;
}
