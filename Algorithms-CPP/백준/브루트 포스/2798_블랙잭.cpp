//
//  2798_블랙잭.cpp
//  Algorithms-CPP
//
//  Created by 장우진 on 07/10/2019.
//  Copyright © 2019 장우진. All rights reserved.
//

#include <iostream>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, m = 0, sum = 0, maxSum = -1;
    
    cin >> n >> m;
    int * card = new int[n];
    for (int i = 0; i < n; ++i)
        cin >> card[i];
    
    for (int i = 0; i < n - 2; ++i) {
        for (int j = i + 1; j < n - 1; ++j) {
            for (int k = j + 1; k < n; ++k) {
                sum = card[i] + card[j] + card[k];
                if (sum <= m && sum > maxSum)
                    maxSum = sum;
            }
        }
    }
    cout << maxSum << endl;
    delete []card;
    return 0;
}
