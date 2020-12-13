//
//  2606_바이러스.cpp
//  Algorithms-CPP
//
//  Created by 장우진 on 2019/12/08.
//  Copyright © 2019 장우진. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;

const int MAX = 101;

bool visited[MAX];
vector<int> graph[MAX];

void dfs(int vertex) {
    if (visited[vertex])
        return;
    
    visited[vertex] = true;
    for (int i = 0; i < (int)graph[vertex].size(); ++i) {
        dfs(graph[vertex][i]);
    }
}

int main() {
    int V, E, from, to;
    cin >> V >> E;

    for (int i = 0; i < E; ++i) {
        cin >> from >> to;
        graph[from].push_back(to);
        graph[to].push_back(from);
    }
    
    dfs(1);
    
    int res = 0;
    for (int i = 1; i <= V; ++i) {
        if (visited[i])
            ++res;
    }
    cout << res - 1 << endl;
    return 0;
}
