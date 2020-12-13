//
//  13913_숨바꼭질 4.cpp
//  Algorithms-CPP
//
//  Created by 장우진 on 2020/01/29.
//  Copyright © 2020 장우진. All rights reserved.
//

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

const int MAX = 100000 + 1;
bool visited[MAX];
int par[MAX];
int n, k;

int main() {
    cin >> n >> k;
    
    if (n == k) {
        cout << 0 << endl;
        cout << n << endl;
        return 0;
    }
    
    queue<int> q;
    q.push(n);
    int t = 0;
    bool flag = false;
    visited[n] = true;
    
    while (!q.empty()) {
        int size = (int)q.size();
        for (int i = 0; i < size; ++i) {
            int x = q.front();
            q.pop();
            
            int nx[3] = {x - 1, x + 1, x * 2};
            for (int j = 0; j < 3; ++j) {
                if (0 <= nx[j] && nx[j] < MAX && !visited[nx[j]]) {
                    q.push(nx[j]);
                    par[nx[j]] = x;
                    visited[nx[j]] = true;
                    if (nx[j] == k) {
                        flag = true;
                        break;
                    }
                }
            }
            if (flag)
                break;
        }
        ++t;
        if (flag)
            break;
    }
    cout << t << endl;
    
    vector<int> v;
    while (k != n) {
        v.push_back(k);
        k = par[k];
    }
    v.push_back(n);
    
    for (auto it = v.rbegin(); it != v.rend(); ++it)
        cout << *it << ' ';
    
    return 0;
}
