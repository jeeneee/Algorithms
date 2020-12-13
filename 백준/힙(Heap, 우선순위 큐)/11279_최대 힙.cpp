//
//  11279_최대 힙.cpp
//  Algorithms-CPP
//
//  Created by 장우진 on 2019/12/09.
//  Copyright © 2019 장우진. All rights reserved.
//

#include <iostream>
#include <queue>
using namespace std;

int main() {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int n, x;
    priority_queue<int> q;
    cin >> n;
    while (n--) {
        cin >> x;
        if (x == 0) {
            if (q.empty())
                cout << 0 << '\n';
            else {
                cout << q.top() << '\n';
                q.pop();
            }
        }
        else
            q.push(x);
    }
    return 0;
}
