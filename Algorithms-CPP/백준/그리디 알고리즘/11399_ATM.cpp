//
//  11399_ATM.cpp
//  Algorithms-CPP
//
//  Created by 장우진 on 2019/11/21.
//  Copyright © 2019 장우진. All rights reserved.
//

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int n;
    scanf("%d", &n);
    int *p = new int[n];
    for (int i = 0; i < n; ++i)
        scanf("%d", &p[i]);
    sort(p, p + n);
    
    int time = 0, ans = 0;
    for (int i = 0; i < n; ++i) {
        time += p[i];
        ans += time;
    }
    printf("%d\n", ans);
    
    return 0;
}
