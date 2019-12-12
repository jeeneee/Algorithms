//
//  1744_수 묶기.cpp
//  Algorithms-CPP
//
//  Created by 장우진 on 2019/11/21.
//  Copyright © 2019 장우진. All rights reserved.
//

#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
using namespace std;

int main() {
    vector<int> pos;
    vector<int> neg;
    int n, num;
    bool hasZero = false;
    scanf("%d", &n);
    
    for (int i = 0; i < n; ++i) {
        scanf("%d", &num);
        if (num < 0) neg.push_back(num);
        else if (num > 0) pos.push_back(num);
        else hasZero = true;
    }
    
    sort(neg.begin(), neg.end());
    sort(pos.begin(), pos.end());
    
    int ans = 0;
    int neg_sz = (int)neg.size();
    int pos_sz = (int)pos.size();
    
    /* 음수 처리 */
    if (neg_sz % 2 == 1) {
        neg_sz--;
        if (!hasZero)
            ans += neg[neg_sz];
    }
    for (int i = 0; i < neg_sz / 2; ++i)
        ans += neg[2 * i] * neg[2 * i + 1];
    
    /* 양수 처리 */
    int j = pos_sz - 1;
    while(j > 0) {
        ans += max(pos[j] * pos[j-1], pos[j] + pos[j-1]);
        j -= 2;
    }
    if (j == 0)
        ans += pos[j];
    printf("%d\n", ans);
    
    return 0;
}
