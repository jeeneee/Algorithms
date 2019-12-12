//
//  11723_집합.cpp
//  Algorithms-CPP
//
//  Created by 장우진 on 2019/12/09.
//  Copyright © 2019 장우진. All rights reserved.
//

#include <iostream>
#include <string>
using namespace std;

int main() {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int m, x, s = 0;
    string op;
    cin >> m;
    while (m--) {
        cin >> op;
        if (op == "add") {
            cin >> x;
            s |= (1 << x);
        } else if (op == "remove") {
            cin >> x;
            s &= ~(1 << x);
        } else if (op == "check") {
            cin >> x;
            cout << ((s & (1 << x)) > 0)<< '\n';
        } else if (op == "toggle") {
            cin >> x;
            s ^= (1 << x);
        } else if (op == "all") {
            s = 2097151;
        } else if (op == "empty") {
            s = 0;
        }
    }
    
    return 0;
}
