//
//  코드 16.cpp
//  Algorithms-CPP
//
//  Created by 장우진 on 2019/12/27.
//  Copyright © 2019 장우진. All rights reserved.
//

#include <iostream>
#include <algorithm>
#include <cmath>
#include <cstring>
using namespace std;

const int MAX_N = 1000 * 1000 * 100;
unsigned char sieve[MAX_N + 7];

inline bool isPrime(int k) {
    // k >> 3 = k / 8
    // 1 << (k & 7) = k % 8
    return sieve[k >> 3] & (1 << (k & 7));
}

inline void setComposite(int k) {
    sieve[k >> 3] &= ~(1 << (k & 7));
}

int main() {
    memset(sieve, 255, sizeof(sieve));
    setComposite(0);
    setComposite(1);
    int sqrtn = int(sqrt(MAX_N));
    for (int i = 2; i <= sqrtn; ++i) {
        if (isPrime(i))
            for (int j = i * i; j <= MAX_N; j += i)
                setComposite(j);
    }
    for (int i = 0; i <= 100; ++i) {
        printf("%3d : %d\n", i, bool(sieve[i >> 3] & (1 << (i & 7))));
    }
    return 0;
}
