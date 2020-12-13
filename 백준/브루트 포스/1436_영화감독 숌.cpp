//
//  1436_영화감독 숌.cpp
//  Algorithms-CPP
//
//  Created by 장우진 on 08/10/2019.
//  Copyright © 2019 장우진. All rights reserved.
//

#include <iostream>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int n, num = 666;
    cin >> n;
    while (n) {
        int current_num = num;
        int cnt = 0;
        while (current_num) {
            if (current_num % 10 == 6) cnt++;
            else cnt = 0;
            if (cnt == 3) {
                n--;
                break;
            }
            current_num /= 10;
        }
        num++;
    }
    cout << --num << endl;
    
    return 0;
}

