//
//  1016_제곱 ㄴㄴ 수.cpp
//  Algorithms-CPP
//
//  Created by 장우진 on 2019/12/12.
//  Copyright © 2019 장우진. All rights reserved.
//
/*
 에라토스테네스의 체
 */
#include <iostream>
#include <vector>
#include <climits>
#include <cmath>
#include <algorithm>

using namespace std;

typedef long long ll;

bool check[1000001];

int main() {
    ll min, max;
    cin >> min >> max;
    for (ll i = 2; i*i <= max; ++i) {
        ll x = min / (i * i);
        if (min % (i * i) != 0) ++x;
        while (x * i * i <= max) {
            check[x * i * i - min] = true;
            ++x;
        }
    }
    int ans = 0;
    for (int i = 0; i <= max-min; ++i) {
        if (!check[i]) ++ans;
    }
    cout << ans << endl;
    
    return 0;
}
