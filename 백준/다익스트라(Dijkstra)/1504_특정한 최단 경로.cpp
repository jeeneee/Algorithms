//
//  1504_특정한 최단 경로.cpp
//  Algorithms-CPP
//
//  Created by 장우진 on 2019/12/10.
//  Copyright © 2019 장우진. All rights reserved.
//

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

typedef pair<int, int> pii;

const int MAX = 801;
const int INF = 1000000;
vector<pii> graph[MAX]; // {vertex, distacne}

vector<int> dijkstra(int source, int vertex) {
    priority_queue<pii, vector<pii>, greater<pii> > q; // {distance, vertex}
    vector<int> distance(vertex + 1, INF);
    
    distance[source] = 0;
    q.push(make_pair(distance[source], source));
    while (!q.empty()) {
        int d = q.top().first;
        int v = q.top().second;
        q.pop();
        
        if (distance[v] < d)
            continue;
        
        for (int i = 0; i < graph[v].size(); ++i) {
            int adj_d = d + graph[v][i].second;
            int adj_v = graph[v][i].first;
            if (distance[adj_v] > adj_d) {
                distance[adj_v] = adj_d;
                q.push(make_pair(adj_d, adj_v));
            }
        }
    }
    
    return distance;
}

int main() {
    int V, E, a, b, c;
    scanf("%d%d", &V, &E);
    for (int i = 0; i < E; ++i) {
        scanf("%d%d%d", &a, &b, &c);
        graph[a].push_back(make_pair(b, c));
        graph[b].push_back(make_pair(a, c));
    }
    int via, via2;
    scanf("%d%d", &via, &via2);
    
    vector<int> first = dijkstra(1, V);
    vector<int> second = dijkstra(via, V);
    vector<int> third = dijkstra(V, V);
    
    long long cand = first[via] + second[via2] + third[via2];
    long long cand2 = first[via2] + second[via2] + third[via];
    long long ans = min(cand, cand2);
    
    if (ans >= INF) ans = -1;
    printf("%lld\n", ans);
    return 0;
}
