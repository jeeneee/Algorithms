//
//  9370_미확인 도착지.cpp
//  Algorithms-CPP
//
//  Created by 장우진 on 2019/12/10.
//  Copyright © 2019 장우진. All rights reserved.
//

#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;

typedef pair<int, int> pii;

const int INF = 200000000;
const int MAX = 2000 + 1;

vector<pii> graph[MAX]; // {vertex, distance}

vector<int> dijkstra(int source, int vertex) {
    vector<int> distance(vertex + 1, INF);
    distance[source] = 0;
    
    priority_queue<pii, vector<pii>, greater<pii> > q; // {distance, vertex}
    q.push(make_pair(distance[source], source));
    
    while (!q.empty()) {
        int d = q.top().first;
        int v = q.top().second;
        q.pop();
        
        if (distance[v] < d) continue;
        
        for (int i = 0; i < graph[v].size(); ++i) {
            int adj_v = graph[v][i].first;
            int adj_d = d + graph[v][i].second;
            if (distance[adj_v] > adj_d) {
                distance[adj_v] = adj_d;
                q.push(make_pair(adj_d, adj_v));
            }
        }
    }
    return distance;
}

int main() {
    /*
        n: 교차로
        m: 도로
        t: 목적지 후보의 개수
        s: 출발지
        g, h: 두 교차로의 도로를 경유
    */
    int TC, n, m, t, s, g, h;
    scanf("%d", &TC);
    
    while (TC--) {
        for (int i = 0; i < MAX; ++i) {
            graph[i].clear();
        }
        
        scanf("%d%d%d", &n, &m, &t);
        scanf("%d%d%d", &s, &g, &h);

        int a, b, d;
        for (int i = 0; i < m; ++i) {
            scanf("%d%d%d", &a, &b, &d);
            graph[a].push_back(make_pair(b, d));
            graph[b].push_back(make_pair(a, d));
        }
        
        vector<int> dest;
        int destination;
        for (int i = 0; i < t; ++i) {
            scanf("%d", &destination);
            dest.push_back(destination);
        }
        
        sort(dest.begin(), dest.end());
        
        vector<int> shortest = dijkstra(s, n);
        vector<int> from_h = dijkstra(h, n);
        vector<int> from_g = dijkstra(g, n);
        
        int via_d = 0;
        for (int i = 0; i < graph[g].size(); ++i) {
            if (graph[g][i].first == h)
                via_d = graph[g][i].second;
        }
        
        for (int i = 0; i < dest.size(); ++i) {
            long long cand = shortest[g] + via_d + from_h[dest[i]];
            long long cand2 = shortest[h] + via_d + from_g[dest[i]];
            
            if (min(cand, cand2) == shortest[dest[i]])
                printf("%d ", dest[i]);
        }
        printf("\n");
    }
    return 0;
}
