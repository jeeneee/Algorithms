//
//  2312_수 복원하기.cpp
//  Algorithms-CPP
//
//  Created by 장우진 on 2019/12/20.
//  Copyright © 2019 장우진. All rights reserved.
//
/*
 소인수분해
 */
#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int sqrtn = int(sqrt(n));
        for (int div = 2; div <= sqrtn; ++div) {
            int cnt = 0;
            while (n % div == 0) {
                n /= div;
                ++cnt;
            }
            if (cnt)
                cout << div << ' ' << cnt << '\n';
        }
        if (n > 1)
            cout << n << ' ' << 1 << '\n';
    }
    return 0;
}
