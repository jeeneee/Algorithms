//
//  1238_파티.cpp
//  Algorithms-CPP
//
//  Created by 장우진 on 2019/11/27.
//  Copyright © 2019 장우진. All rights reserved.
//

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

typedef pair<int, int> pii;

const int INF = 987654321;
const int MAX = 1000 + 1;

vector<int> dijkstra(vector<pii> *graph, int source, int vertex) {
    vector<int> costs(vertex, INF);
    costs[source] = 0;
    
    priority_queue<pii, vector<pii>, greater<pii> > pq;
    pq.push(make_pair(costs[source], source)); // {cost, vertex}
    
    while (!pq.empty()) {
        int v = pq.top().second;
        int c = pq.top().first;
        pq.pop();
        
        if (costs[v] < c) continue;
        
        for (int i = 0; i < graph[v].size(); ++i) {
            int adj_v = graph[v][i].first;
            int adj_c = c + graph[v][i].second;
            if (costs[adj_v] > adj_c) {
                costs[adj_v] = adj_c;
                pq.push(make_pair(adj_c, adj_v));
            }
        }
    }
    return costs;
}

int main() {
    vector<pii> graph1[MAX];
    vector<pii> graph2[MAX];

    int V, E, X, from, to, cost;
    scanf("%d%d%d", &V, &E, &X);
    ++V;
    for (int i = 0; i < E; ++i) {
        scanf("%d%d%d", &from, &to, &cost);
        graph1[from].push_back(make_pair(to, cost)); // {vertex, cost}
        graph2[to].push_back(make_pair(from, cost));
    }
    
    /* graph1로 X에서 각 정점까지 걸리는 시간을 구하고
     graph2로 각 정점에서 X까지 걸리는 시간을 역으로 구한다. */
    vector<int> result1 = dijkstra(graph1, X, V);
    vector<int> result2 = dijkstra(graph2, X, V);
    
    int ans = 0;
    for (int i = 1; i < V; ++i)
        ans = max(ans, result1[i] + result2[i]);
    
    cout << ans << endl;
    
    return 0;
}
