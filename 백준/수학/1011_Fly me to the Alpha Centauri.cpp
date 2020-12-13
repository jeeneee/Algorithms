//
//  1011_Fly me to the Alpha Centauri.cpp
//  Algorithms-CPP
//
//  Created by 장우진 on 10/10/2019.
//  Copyright © 2019 장우진. All rights reserved.
//

#include <iostream>
#include <cmath>
using namespace std;

long long int jumping (long long int n) {
    long long int cntJump, res;
    for (cntJump = (int)sqrt((double)n); n > cntJump * (cntJump + 1); ++cntJump);
    long long int prev_n = cntJump * cntJump + 1;
    if (n < prev_n && n != 0)
        res = cntJump * 2 - 1;
    else
        res = cntJump * 2;
    return res;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--) {
        long long int a, b;
        cin >> a >> b;
        long long int n = b - a;
        printf("%lld\n", jumping(n));
    }
    
    return 0;
}
