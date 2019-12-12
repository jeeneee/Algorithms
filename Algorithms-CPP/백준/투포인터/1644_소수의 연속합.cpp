//
//  1644_소수의 연속합.cpp
//  Algorithms-CPP
//
//  Created by 장우진 on 2019/11/27.
//  Copyright © 2019 장우진. All rights reserved.
//

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int n;
    cin >> n;
    bool *isPrime = new bool[n+1];
    vector<int> primeArray;
    
    fill(isPrime, isPrime + n + 1, true);
    for (int i = 2; i * i <= n; ++i)
        if (isPrime[i])
            for (int j = i * i; j <= n; j += i)
                isPrime[j] = false;
    
    for (int i = 2; i <= n; ++i) {
        if (isPrime[i])
            primeArray.push_back(i);
    }
    
    int left = 0;
    int right = 0;
    int sum = 0;
    int ans = 0;
    while (1) {
        if (sum >= n) sum -= primeArray[left++];
        else if (right == primeArray.size()) break;
        else sum += primeArray[right++];
        if (sum == n) ans++;
    }
    
    cout << ans << endl;
    
    delete []isPrime;
    return 0;
}
