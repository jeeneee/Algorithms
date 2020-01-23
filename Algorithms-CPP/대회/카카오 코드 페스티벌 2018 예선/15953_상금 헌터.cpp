//
//  15953_상금 헌터.cpp
//  Algorithms-CPP
//
//  Created by 장우진 on 2020/01/23.
//  Copyright © 2020 장우진. All rights reserved.
//

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

const int prize1[] = {
    0,
    5000000,
    3000000,
    2000000,
    500000,
    300000,
    100000
};
const int prize2[] = {
    0,
    5120000,
    2560000,
    1280000,
    640000,
    320000
};
const int psum1[] = {0, 1, 3, 6, 10, 15, 21};
const int psum2[] = {0, 1, 3, 7, 15, 31};
int main() {
    int n, a, b;
    cin >> n;
    while (n--) {
        cin >> a >> b;
        int total = 0;
        for (int i = 0; i <= 6; ++i) {
            if (a <= psum1[i]) {
                total += prize1[i];
                break;
            }
        }
        for (int i = 0; i <= 5; ++i) {
            if (b <= psum2[i]) {
                total += prize2[i];
                break;
            }
        }
        cout << total << endl;
    }
    return 0;
}
