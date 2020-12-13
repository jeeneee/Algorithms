//
//  1676_팩토리얼 0의 개수.cpp
//  Algorithms-CPP
//
//  Created by 장우진 on 2019/10/29.
//  Copyright © 2019 장우진. All rights reserved.
//

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int n, two = 0, five = 0;
    cin >> n;
    for (int i = 2; i <= n; ++i) {
        int num = i;
        for (int j = 2; j * j <= num; ++j) {
            while (num % j == 0) {
                if (j == 2) ++two;
                else if (j == 5) ++five;
                num /= j;
            }
        }
        if (num == 2) ++two;
        if (num == 5) ++five;
    }
    cout << min(two, five) << '\n';
    
    return 0;
}

