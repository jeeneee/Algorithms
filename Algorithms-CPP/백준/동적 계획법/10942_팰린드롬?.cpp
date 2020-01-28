//
//  10942_팰린드롬?.cpp
//  Algorithms-CPP
//
//  Created by 장우진 on 2020/01/24.
//  Copyright © 2020 장우진. All rights reserved.
//

#include <iostream>
using namespace std;

const int MAX = 2000 + 1;

int arr[MAX];
bool dp[MAX][MAX];

int main() {
    int n;
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i) {
        scanf("%d", &arr[i]);
        dp[i][i] = true;
        if (arr[i] == arr[i-1])
            dp[i-1][i] = true;
    }
    
    for (int i = 2; i < n; ++i) {
        for (int j = 1; j+i <= n; ++j) {
            if (arr[j] == arr[i+j] && dp[j+1][i+j-1])
                dp[j][i+j] = true;
        }
    }
    
    int m, s, e;
    scanf("%d", &m);
    while (m--) {
        scanf("%d %d", &s, &e);
        printf("%d\n", dp[s][e]);
    }
    
    return 0;
}
