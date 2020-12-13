//
//  9613_GCD 합.cpp
//  Algorithms-CPP
//
//  Created by 장우진 on 2019/11/12.
//  Copyright © 2019 장우진. All rights reserved.
//

#include <iostream>
using namespace std;

#define ull unsigned long long

int gcd(int a, int b) {
    if (a % b == 0) return b;
    return gcd(b, a % b);
}

int main() {
    int t, n;
    cin >> t;
    while (t--) {
        ull res = 0;
        cin >> n;
        int *arr = new int[n];
        for (int i = 0; i < n; ++i) {
            cin >> arr[i];
        }
        for (int i = 0; i < n-1; ++i) {
            for (int j = i + 1; j < n; ++j) {
                res += gcd(arr[i], arr[j]);
            }
        }
        cout << res << '\n';
        delete []arr;
    }
    
    return 0;
}
