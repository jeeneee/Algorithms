//
//  1068_트리.cpp
//  Algorithms-CPP
//
//  Created by 장우진 on 2019/12/19.
//  Copyright © 2019 장우진. All rights reserved.
//

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<vector<int> > graph;
int cnt = 0;

void dfs(int root, int del, int prev) {
    if (root == del) {
        if (graph[prev].size() == 1)
            ++cnt;
        return;
    }

    if (graph[root].empty()) cnt++;
    else
        for (int i = 0; i < graph[root].size(); ++i)
            dfs(graph[root][i], del, root);
}

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    int n, parent, root = 0, del = 0;
    cin >> n;
    graph.resize(n);
    
    for (int i = 0; i < n; ++i) {
        cin >> parent;
        if (parent == -1) root = i;
        else graph[parent].push_back(i);
    }
    cin >> del;
    
    dfs(root, del, root);
    cout << cnt << endl;
    return 0;
}
