//
//  2011_암호코드.cpp
//  Algorithms-CPP
//
//  Created by 장우진 on 2019/12/12.
//  Copyright © 2019 장우진. All rights reserved.
//

#include <iostream>
#include <vector>
#include <climits>
#include <cmath>
#include <cstring>
#include <algorithm>

using namespace std;

const int mod = 1'000'000;
const int MAX = 5010;

int main() {
    char s[MAX];
    int dp[MAX] = {};
    scanf("%s", s);
    if (s[0] == '0') {
        printf("0\n");
        return 0;
    }
    dp[0] = dp[1] = 1;
    int i;
    for (i = 2; s[i-1] != 0; ++i) {
        if (s[i-1] > '0') dp[i] = dp[i-1] % mod;
        int x = (s[i-2] - '0') * 10 + (s[i-1] - '0');
        if (10 <= x && x <= 26)
            dp[i] = (dp[i] + dp[i-2]) % mod;
    }
    printf("%d\n", dp[i-1]);
    
    return 0;
}
