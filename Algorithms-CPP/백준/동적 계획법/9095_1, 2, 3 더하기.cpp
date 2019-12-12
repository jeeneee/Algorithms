//
//  9095_1, 2, 3 더하기.cpp
//  Algorithms-CPP
//
//  Created by 장우진 on 2019/11/02.
//  Copyright © 2019 장우진. All rights reserved.
//

#include <iostream>
#define MAX 11
using namespace std;

int memo[MAX] = {1, 1, 2};

int main() {
    for (int i = 3; i <= MAX; ++i)
        memo[i] = memo[i - 3] + memo[i - 2] + memo[i - 1];
    
    int t, n;
    cin >> t;
    
    while (t--) {
        cin >> n;
        cout << memo[n] << '\n';
    }
    
    return 0;
}
