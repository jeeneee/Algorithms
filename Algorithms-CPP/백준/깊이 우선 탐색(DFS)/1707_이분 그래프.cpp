//
//  1707_이분 그래프.cpp
//  Algorithms-CPP
//
//  Created by 장우진 on 2019/11/16.
//  Copyright © 2019 장우진. All rights reserved.
//

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

const int MAX = 20000 + 1;
const int RED = 0;
const int BLUE = 1;

int colors[MAX];
vector<int> graph[MAX];
bool isBipartite;

void dfs(int start, int color) {
    if (graph[start].empty()) return;
    colors[start] = color;
    for (int i = 0; i < graph[start].size(); ++i) {
        // 인접한 정점의 색과 같은 경우
        if (colors[graph[start].at(i)] == color) {
            isBipartite = false;
            return;
        }
        // 방문하지 않은 경우
        if (colors[graph[start].at(i)] == -1)
            dfs(graph[start].at(i), !color);
    }
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int t, V, E;
    cin >> t;
    while (t--) {
        for (int i = 1; i < MAX; ++i)
            graph[i].clear();
        cin >> V >> E;  // V: 정점의 수, E: 간선의 수
        fill(colors, colors + MAX, -1);  // -1: 방문x, 0: red, 1: blue
        int from, to;
        for (int i = 0; i < E; ++i) {
            cin >> from >> to;
            graph[from].push_back(to);
            graph[to].push_back(from);
        }
        isBipartite = true;
        for (int i = 1; i <= V; ++i) {
            if (!isBipartite) break;
            if (colors[i] == -1)
                dfs(i, RED);
        }
        if (isBipartite) cout << "YES" << '\n';
        else cout << "NO" << '\n';
    }
    return 0;
}
