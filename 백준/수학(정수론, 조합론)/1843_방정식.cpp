//
//  1843_방정식.cpp
//  Algorithms-CPP
//
//  Created by 장우진 on 2019/12/13.
//  Copyright © 2019 장우진. All rights reserved.
//

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

typedef long long ll;

int main() {
    int n;
    ll ans;
    cin >> n;
    
    // -----condition 1
    ans = 0;
    if (n & 1) ans = (ll)(n / 2) * (n / 2);
    else ans = (ll)(n / 2) * (n / 2) - (n / 2);
    cout << ans << endl;
    
    // -----condition 2
    ans = 0;
    vector<int> factors;
    bool *chk = new bool[n+1];
    fill_n(chk, n+1, false);
    
    // n의 약수 저장
    for (int i = 1; i <= n/2; ++i) {
        if (n % i == 0) {
            factors.push_back(i);
            chk[i] = true;
        }
    }
    chk[n] = true;
    
    for (unsigned long i = 0; i < factors.size(); ++i) {
        for (unsigned long j = i; j < factors.size(); ++j) {
            int x = factors[i];
            int y = factors[j];
            if (chk[x+y])
                ++ans;
        }
    }
    cout << ans << endl;
            
    // -----condition 3
    // 에라스토테네스의 체를 이용한다.
    ans = 0;
    bool *prime = new bool[n+1];
    fill_n(prime, n+1, true);
    prime[0] = prime[1] = false;
    
    for (int i = 2; i*i <= n; ++i) {
        if (prime[i])
            for (int j = i*i; j <= n; j += i)
                prime[j] = false;
    }
    // 소수 + 2 = 소수 인지 판별한다.
    for (int i = 0; i <= n-2; ++i) {
        if (prime[i] && prime[i+2])
            ++ans;
    }
    cout << ans << endl;
    
    delete []chk;
    delete []prime;
    return 0;
}
