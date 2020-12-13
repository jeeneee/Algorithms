//
//  10451_순열 사이클.cpp
//  Algorithms-CPP
//
//  Created by 장우진 on 2019/11/16.
//  Copyright © 2019 장우진. All rights reserved.
//

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

const int MAX = 1000 + 1;
int graph[MAX];
bool visited[MAX];
bool isCycle;

void dfs(int start, int root) {
    if (visited[start]) {
        isCycle = (start == root ? true : false);
        return;
    }
    visited[start] = true;
    dfs(graph[start], root);
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int t, n;
    cin >> t;
    while (t--) {
        cin >> n;
        fill(visited, visited + MAX, false);
        for (int i = 1; i <= n; ++i) {
            cin >> graph[i];
        }
        int res = 0;
        for (int i = 1; i <= n; ++i) {
            isCycle = true;
            if (!visited[i]) {
                dfs(i, i);
                if (isCycle)
                    ++res;
            }
        }
        cout << res << '\n';
    }
    return 0;
}
