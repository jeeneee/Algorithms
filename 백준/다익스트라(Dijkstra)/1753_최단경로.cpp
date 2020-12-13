//
//  1753_최단경로.cpp
//  Algorithms-CPP
//
//  Created by 장우진 on 2019/11/27.
//  Copyright © 2019 장우진. All rights reserved.
//

#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

typedef pair<int, int> pii;

const int MAX = 20000 + 1;
const int INF = 987654321;

vector<pii> graph[MAX];

vector<int> dijkstra(int source, int vertex) {
    vector<int> distance(vertex, INF);
    distance[source] = 0;
    
    priority_queue<pii, vector<pii>, greater<pii>> pq; // distance, vertex
    pq.push(make_pair(distance[source], source));
    
    while (!pq.empty()) {
        int d = pq.top().first;
        int v = pq.top().second;
        pq.pop();
        
        if (distance[v] < d)
            continue;
        
        for (int i = 0; i < graph[v].size(); ++i) {
            int adj_d = d + graph[v][i].second;
            int adj_v = graph[v][i].first;
            if (distance[adj_v] > adj_d) {
                distance[adj_v] = adj_d;
                pq.push(make_pair(adj_d, adj_v));
            }
        }
    }
    return distance;
}

int main() {
    int V, E, K, u, v, w;
    scanf("%d%d%d", &V, &E, &K);
    ++V;
    
    for (int i = 0; i < E; ++i) {
        scanf("%d%d%d", &u, &v, &w); // u -> v: w
        graph[u].push_back(make_pair(v, w));
    }
    
    vector<int> result = dijkstra(K, V);
    
    for (int i = 1; i < V; ++i) {
        if (result[i] == INF)
            cout << "INF" << '\n';
        else
            cout << result[i] << '\n';
    }
    
    return 0;
}
