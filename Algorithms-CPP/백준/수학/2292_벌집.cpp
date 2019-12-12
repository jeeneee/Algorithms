//
//  2292_벌집.cpp
//  Algorithms-CPP
//
//  Created by 장우진 on 07/10/2019.
//  Copyright © 2019 장우진. All rights reserved.
//

#include <iostream>
using namespace std;

int main() {
    int x, prev_num = 2;
    cin >> x;
    if (x < 2) {cout << 1 << endl; return 0;}
    for (int i = 1; ; ++i) {
        int cur_num = prev_num + 6 * i;
        if (prev_num <= x && x < cur_num) {
            cout << ++i << endl;
            return 0;
        }
        prev_num = cur_num;
    }
}
