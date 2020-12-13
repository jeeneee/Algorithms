//
//  11725_트리의 부모 찾기.cpp
//  Algorithms-CPP
//
//  Created by 장우진 on 2019/10/21.
//  Copyright © 2019 장우진. All rights reserved.
//

#include <iostream>
#include <vector>
#include <queue>
#define MAX 100002
using namespace std;

vector<int> tree[MAX];
queue<int> q;
int parent[MAX];

void bfs(int x) {
    q.push(x);
    while (!q.empty()) {
        int next = q.front();
        q.pop();
        for (int i = 0; i < tree[next].size(); ++i) {
            if (!parent[tree[next].at(i)]) {
                q.push(tree[next].at(i));
                parent[tree[next].at(i)] = next;
            }
        }
    }
}

void dfs(int x) {
    for (int i = 0; i < tree[x].size(); ++i) {
        int next = tree[x][i];
        if (!parent[next]) {
            parent[next] = x;
            dfs(next);
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int n, from, to;
    cin >> n;
    for (int i = 0; i < n - 1; ++i) {
        cin >> from >> to;
        tree[from].push_back(to);
        tree[to].push_back(from);
    }
    
//    parent[1] = 1;
//    bfs(1);
    dfs(1);
    
    for (int i = 2; i <= n; ++i) {
        cout << parent[i] << '\n';
    }
    
    return 0;
}
