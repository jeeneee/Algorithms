//
//  1158_조세퍼스 문제.cpp
//  Algorithms-CPP
//
//  Created by 장우진 on 2019/11/12.
//  Copyright © 2019 장우진. All rights reserved.
//

#include <iostream>
#include <queue>
using namespace std;

int main() {
    int n, k;
    queue<int> q;
    cin >> n >> k;
    int *joseph = new int[n];
    int idx = 0;
    // initialize queue
    for (int i = 1; i <= n; ++i)
        q.push(i);
    
    for (int i = 1; !q.empty(); ++i) {
        int element = q.front();
        q.pop();
        if (i % k == 0)
            joseph[idx++] = element;
        else
            q.push(element);
    }
    
    cout << '<';
    for (int i = 0; i < n; ++i) {
        cout << joseph[i];
        if (i != (n - 1))
            cout << ", ";
    }
    cout << ">\n";
    
    delete []joseph;
    return 0;
}
