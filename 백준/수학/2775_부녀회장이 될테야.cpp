//
//  2775_부녀회장이 될테야.cpp
//  Algorithms-CPP
//
//  Created by 장우진 on 11/10/2019.
//  Copyright © 2019 장우진. All rights reserved.
//

#include <iostream>
using namespace std;

int main() {
    int a[15][14];
    for (int i = 0; i < 15; ++i) {
        int temp = 0;
        for (int j = 0; j < 14; ++j) {
            if (i == 0) {
                a[i][j] = j + 1;
            }
            else {
                temp += a[i - 1][j];
                a[i][j] = temp;
            }
        }
    }
    
    int t, k, n;
    cin >> t;
    while (t--) {
        cin >> k >> n;
        cout << a[k][n-1] << endl;
    }
    
    return 0;
}
