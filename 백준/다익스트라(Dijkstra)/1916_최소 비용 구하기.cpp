//
//  1916_최소 비용 구하기.cpp
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

vector<pii> graph[MAX];

vector<int> dijkstra(int source, int vertex) {
    vector<int> costs(vertex, INF);
    costs[source] = 0;
    
    priority_queue<pii, vector<pii>, greater<pii> > pq;
    pq.push(make_pair(costs[source], source)); // {cost, vertex}
    
    while (!pq.empty()) {
        int c = pq.top().first;
        int v = pq.top().second;
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
    int V, E, from, to, cost, start, end;
    scanf("%d%d", &V, &E);
    ++V;
    for (int i = 0; i < E; ++i) {
        scanf("%d%d%d", &from, &to, &cost);
        graph[from].push_back(make_pair(to, cost)); // {vertex, cost}
    }
    scanf("%d%d", &start, &end);
    
    vector<int> result = dijkstra(start, V);
    
    cout << result[end] << endl;
    
    return 0;
}
