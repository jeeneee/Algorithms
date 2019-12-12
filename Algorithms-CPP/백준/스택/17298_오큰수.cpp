//
//  17298_오큰수.cpp
//  Algorithms-CPP
//
//  Created by 장우진 on 14/10/2019.
//  Copyright © 2019 장우진. All rights reserved.
//

#include <iostream>
#include <stack>
#include <vector>
#define MAX 1000001
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    vector<int> v(MAX), ans(MAX, -1);
    stack<int> stack;
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) cin >> v[i];
    for (int i = n - 1; i > -1; --i) {
        while (!stack.empty() && v[i] >= stack.top())
            stack.pop();
        if (!stack.empty())
            ans[i] = stack.top();
        stack.push(v[i]);
    }
    
    for (int i = 0; i < n; ++i) {
        printf("%d ", ans[i]);
    }
    
    return 0;
}
