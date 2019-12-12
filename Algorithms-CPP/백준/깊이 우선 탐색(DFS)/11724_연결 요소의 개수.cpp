//
//  11724_연결 요소의 개수.cpp
//  Algorithms-CPP
//
//  Created by 장우진 on 2019/11/16.
//  Copyright © 2019 장우진. All rights reserved.
//

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

void dfs(bool **graph, bool visited[], int start, int n) {
    visited[start] = true;
    for (int i = 1; i <= n; ++i) {
        if (graph[start][i] && !visited[i])
            dfs(graph, visited, i, n);
    }
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int n, m; // n: 정점의 수, m: 간선의 수
    cin >> n >> m;
    /* Initialization */
    bool **graph = new bool*[n + 1];
    for (int i = 0; i < n + 1; ++i) {
        graph[i] = new bool[n + 1];
        fill(graph[i], graph[i] + n + 1, false);
    }
    bool *visited = new bool[n + 1];
    fill(visited, visited + n + 1, false);
    
    int a, b;
    for (int i = 0; i < m; ++i) {
        cin >> a >> b;
        graph[a][b] = graph[b][a] = true;
    }
    
    int res = 0;
    for (int i = 1; i <= n; ++i) {
        if (!visited[i]) {
            dfs(graph, visited, i, n);
            ++res;
        }
    }
    
    cout << res << endl;
    
    for (int i = 0; i < n + 1; ++i) {
        delete []graph[i];
    }
    delete []visited;
    return 0;
}
