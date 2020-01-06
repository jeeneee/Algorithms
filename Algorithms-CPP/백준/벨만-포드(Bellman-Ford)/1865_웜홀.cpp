//
//  1865_웜홀.cpp
//  Algorithms-CPP
//
//  Created by 장우진 on 2020/01/02.
//  Copyright © 2020 장우진. All rights reserved.
//

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

typedef pair<int, int> pii;

const int INF = 987654321;

vector<vector<pii> > graph;
vector<int> cost;
int N, M, W;

void bellman(int s) {
    cost[s] = 0;
    bool negCycle = false;
    for (int i = 1; i <= N; ++i) {
        for (int j = 1; j <= N; ++j) {
            for (auto &v : graph[j]) {
                if (cost[j] != INF && cost[j] + v.second < cost[v.first]) {
                    cost[v.first] = cost[j] + v.second;
                    if (i == N)
                        negCycle = true;
                }
            }
        }
    }
    
    if (negCycle)
        cout << "YES" << '\n';
    else
        cout << "NO" << '\n';
}

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int t;
    cin >> t;
    while (t--) {
        graph.clear();
        cost.clear();
        
        cin >> N >> M >> W;
        graph.resize(N + 1);
        cost.resize(N + 1);
        
        int u, v, w;
        for (int i = 0; i < M; ++i) {
            cin >> u >> v >> w;
            graph[u].push_back(make_pair(v, w));
            graph[v].push_back(make_pair(u, w));
        }
        for (int i = 0; i < W; ++i) {
            cin >> u >> v >> w;
            graph[u].push_back(make_pair(v, -w));
        }
        
        fill(cost.begin(), cost.end(), INF);
        
        bellman(1);
    }
    
    return 0;
}
