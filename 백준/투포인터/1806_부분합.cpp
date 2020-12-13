//
//  1806_부분합.cpp
//  Algorithms-CPP
//
//  Created by 장우진 on 2019/11/27.
//  Copyright © 2019 장우진. All rights reserved.
//

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int n, s;
    scanf("%d%d", &n, &s);
    int *arr = new int[n];
    for (int i = 0; i < n; ++i)
        scanf("%d", &arr[i]);
    
    int left = 0;
    int right = 0;
    int sum = 0;
    int ans = 1234567890;
    bool flag = false;
    while (1) {
        if (sum >= s) {
            ans = min(ans, right - left);
            sum -= arr[left++];
            flag = true;
        }
        else if (right == n) break;
        else sum += arr[right++];
    }
    
    if (!flag) ans = 0;
    printf("%d\n", ans);
    
    delete []arr;
    return 0;
}
