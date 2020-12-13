//
//  11047_동전0.cpp
//  Algorithms-CPP
//
//  Created by 장우진 on 09/10/2019.
//  Copyright © 2019 장우진. All rights reserved.
//

#include <iostream>
using namespace std;

int coinCnt (int arr[], int n, int change, int coinNum) {
    if (change == 0)
        return coinNum;
    for (int i = n - 1; i >= 0; --i) {
        if (change / arr[i] >= 1) {
            coinNum += change / arr[i];
            change %= arr[i];
        }
    }
    return coinCnt(arr, n, change, coinNum);
}

int main() {
    int n, k;
    cin >> n >> k;
    int * a = new int[n];
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    
    cout << coinCnt(a, n, k, 0) << endl;
    
    delete []a;
    
    return 0;
}
