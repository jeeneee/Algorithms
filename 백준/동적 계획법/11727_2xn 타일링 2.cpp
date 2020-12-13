//
//  11727_2xn 타일링 2.cpp
//  Algorithms-CPP
//
//  Created by 장우진 on 2019/11/02.
//  Copyright © 2019 장우진. All rights reserved.
//

#include <iostream>
#define MAX 1001
using namespace std;

int memo[MAX] = {1, 1, };

int main() {
    int n;
    cin >> n;
    
    for (int i = 2; i <= n; ++i)
        memo[i] = (memo[i - 2] * 2 + memo[i - 1]) % 10007;
    cout << memo[n] << endl;
    
    return 0;
}
