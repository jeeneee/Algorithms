//
//  11657_타임머신.cpp
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
vector<int> dist;
int N, M;

void bellman(int s) {
    dist[s] = 0;
    bool negCycle = false;
    for (int i = 1; i <= N; ++i) {
        for (int j = 1; j <= N; ++j) {
            for (auto &v : graph[j]) {
                if (dist[j] != INF && dist[j] + v.second < dist[v.first]) {
                    dist[v.first] = dist[j] + v.second;
                    if (i == N)
                        negCycle = true;
                }
            }
        }
    }
    
    if (negCycle)
        cout << -1 << '\n';
    else
        for (int i = 2; i <= N; ++i) {
            if (dist[i] == INF) dist[i] = -1;
            cout << dist[i] << '\n';
        }
}

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> N >> M;
    graph.resize(N + 1);
    dist.resize(N + 1);
    
    int u, v, w;
    for (int i = 0; i < M; ++i) {
        cin >> u >> v >> w;
        graph[u].push_back(make_pair(v, w));
    }
    
    fill(dist.begin(), dist.end(), INF);
    
    bellman(1);
    
    return 0;
}
