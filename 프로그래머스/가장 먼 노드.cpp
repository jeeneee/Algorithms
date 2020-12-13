//
//  가장 먼 노드.cpp
//  Algorithms-CPP
//
//  Created by 장우진 on 2020/06/20.
//  Copyright © 2020 장우진. All rights reserved.
//

#include <iostream>
#include <string>
#include <vector>
#include <queue>

using namespace std;

int solution(int n, vector<vector<int>> edges) {
    int answer = 0;
    vector<vector<int>> graph(n+1);
    vector<bool> visited(n+1);
    for (auto& edge: edges) {
        graph[edge[0]].push_back(edge[1]);
        graph[edge[1]].push_back(edge[0]);
    }
    queue<int> q;
    q.push(1);
    visited[1] = true;
    while (!q.empty()) {
        int size = q.size();
        answer = size;
        while (size--) {
            int x = q.front();
            q.pop();
            for (int i = 0; i < graph[x].size(); ++i) {
                if (!visited[graph[x][i]]) {
                    visited[graph[x][i]] = true;
                    q.push(graph[x][i]);
                }
            }
        }
    }
    return answer;
}
