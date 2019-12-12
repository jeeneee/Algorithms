//
//  11653_소인수분해.cpp
//  Algorithms-CPP
//
//  Created by 장우진 on 2019/10/28.
//  Copyright © 2019 장우진. All rights reserved.
//

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int n;
    cin >> n;
    if (n == 1) {
        cout << '\n';
        return 0;
    }
    while (n > 1) {
        vector<bool> primeArray(n + 1);
        fill(primeArray.begin(), primeArray.end(), true);
        for (int i = 2; i * i <= n; ++i)
            if (primeArray[i])
                for (int j = i * i; j <= n; j += i)
                    primeArray[j] = false;
        for (int i = 2; i <= n; ++i) {
            if (primeArray[i] && (n % i == 0)) {
                cout << i << '\n';
                n /= i;
                break;
            }
        }
    }
    return 0;
}
