//
//  5086_배수와 약수.cpp
//  Algorithms-CPP
//
//  Created by 장우진 on 2019/10/28.
//  Copyright © 2019 장우진. All rights reserved.
//

#include <iostream>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    int a, b;
    while (true) {
        cin >> a >> b;
        if (a == 0 && b == 0) break;
        if (b % a == 0) {
            cout << "factor" << '\n';
            continue;
        }
        else if (a % b == 0) {
            cout << "multiple" << '\n';
            continue;
        }
        else
            cout << "neither" << '\n';
    }
    
    return 0;
}
