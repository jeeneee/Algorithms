//
//  11728_배열 합치기.cpp
//  Algorithms-CPP
//
//  Created by 장우진 on 2019/11/19.
//  Copyright © 2019 장우진. All rights reserved.
//

#include <iostream>
#include <vector>
#include <string>
#include <cmath>
#include <climits>
#include <algorithm>
using namespace std;

int main() {
    int n, m;
    scanf("%d%d", &n, &m);
    vector<int> v1(n), v2(m);
    for (int i = 0; i < n; ++i)
        scanf("%d", &v1[i]);
    for (int i = 0; i < m; ++i)
        scanf("%d", &v2[i]);
    int i = 0, j = 0;
    while (i < n && j < m) {
        if (v1[i] <= v2[j])
            printf("%d ", v1[i++]);
        else
            printf("%d ", v2[j++]);
    }
    if (i == n)
        for (int t = j; t < m; ++t)
            printf("%d ", v2[t]);
    else
        for (int t = i; t < n; ++t)
            printf("%d ", v1[t]);
    printf("\n");
    return 0;
}
