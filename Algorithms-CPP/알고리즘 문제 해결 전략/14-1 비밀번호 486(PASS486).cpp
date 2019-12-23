//
//  14-1 비밀번호 486(PASS486).cpp
//  Algorithms-CPP
//
//  Created by 장우진 on 2019/12/20.
//  Copyright © 2019 장우진. All rights reserved.
//

#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;

const int MAX = 10000000 + 1;
// i의 가장 작은 소인수(i가 소수인 경우 자기 자신)
int minFactor[MAX];
// i의 소인수 분해에는 minFactor[i]의 몇 승이 포함되어 있는가?
int minFactorPower[MAX];
// i가 가진 약수의 수
int factors[MAX];

void eratosthenes(int n) {
    minFactor[0] = minFactor[1] = -1;
    for (int i = 2; i < n; ++i) {
        minFactor[i] = i;
    }
    int sqrtn = int(sqrt(n));
    for (int i = 2; i <= sqrtn; ++i) {
        if (minFactor[i] == i) {
            for (int j = i*i; j <= MAX; j += i)
                if (minFactor[j] == j)
                    minFactor[j] = i;
        }
    }
}

void getFactors(int n) {
    factors[1] = 1;
    for (int i = 2; i < MAX; ++i) {
        // 소수인 경우 약수 두 개
        if (minFactor[i] == i) {
            minFactorPower[i] = 1;
            factors[i] = 2;
        }
        // 소수가 아닌 경우, 가장 작은 소인수로 나눈 수(m)의
        // 약수의 수를 응용해 i의 약수의 수를 찾는다.
        else {
            int p = minFactor[i];
            int m = i / p;
            // m이 p로 더이상 나누어지지 않는 경우
            if (p != minFactor[m])
                minFactorPower[i] = 1;
            else
                minFactorPower[i] = minFactorPower[m] + 1;
            int a = minFactorPower[i];
            factors[i] = (factors[m] / a) * (a + 1);
        }
    }
}

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    
    eratosthenes(MAX);
    getFactors(MAX);
    
    int t;
    cin >> t;
    while (t--) {
        int n, lo, hi, ans = 0;
        cin >> n >> lo >> hi;
        for (int i = lo; i <= hi; ++i) {
            if (factors[i] == n)
                ++ans;
        }
        cout << ans << '\n';
    }
    return 0;
}
