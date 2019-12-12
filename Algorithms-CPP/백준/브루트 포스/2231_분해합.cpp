//
//  2231_분해합.cpp
//  Algorithms-CPP
//
//  Created by 장우진 on 08/10/2019.
//  Copyright © 2019 장우진. All rights reserved.
//

#include <iostream>
#include <cmath>
using namespace std;

int main() {
    int n;
    cin >> n;
    for (int i = n - 54; i < n; ++i) {
        int sum = i, current_num = i;
        while (current_num) {
            sum += current_num % 10;
            current_num /= 10;
        }
        if (sum == n) {
            cout << i << endl;
            return 0;
        }
    }
    cout << 0 << endl;
    return 0;
}
