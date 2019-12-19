//
//  5567_결혼식.cpp
//  Algorithms-CPP
//
//  Created by 장우진 on 2019/12/19.
//  Copyright © 2019 장우진. All rights reserved.
//

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

vector<vector<int> > graph;
bool *visited;

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    int n, m, a, b;
    cin >> n >> m;
    graph.resize(n+1);
    visited = new bool[n+1];
    while (m--) {
        cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }
    
    queue<int> q;
    int depth = 2, ans = 0;
    q.push(1);
    visited[1] = true;
    while (depth--) {
        int size = (int)q.size();
        for (int i = 0; i < size; ++i) {
            int x = q.front();
            q.pop();
            for (int j = 0; j < graph[x].size(); ++j) {
                int nx = graph[x][j];
                if (!visited[nx]) {
                    visited[nx] = true;
                    q.push(nx);
                    ans++;
                }
            }
        }
    }
    cout << ans << endl;
    
    delete []visited;
    return 0;
}
