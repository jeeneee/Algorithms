//
//  11779_최소 비용 구하기 2.cpp
//  Algorithms-CPP
//
//  Created by 장우진 on 2020/01/29.
//  Copyright © 2020 장우진. All rights reserved.
//
/*
 [1916 최소비용 구하기]와 다른 점은 경로를 역추적해야 한다는 점이다.
 if 문에 "par[adj_v] = v" 만 추가해주면 된다.
 */
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

typedef pair<int, int> pii;

const int MAX = 1000 + 1;
const int INF = 987654321;
vector<pii> graph[MAX];
int par[MAX];

int main() {
    int n, m, u, v, c, s, e;
    scanf("%d %d", &n, &m);
    for (int i = 0; i < m; ++i) {
        scanf("%d %d %d", &u, &v, &c);
        graph[u].push_back( {v, c} );
    }
    scanf("%d %d", &s, &e);
    
    priority_queue<pii, vector<pii>, greater<pii> > pq;
    vector<int> cost(n+1, INF);
    cost[s] = 0;
    pq.push( {cost[s], s} );
    while (!pq.empty()) {
        int c = pq.top().first;
        int v = pq.top().second;
        pq.pop();
        
        if (c > cost[v])
            continue;
        
        for (int i = 0; i < graph[v].size(); ++i) {
            int adj_v = graph[v][i].first;
            int adj_c = graph[v][i].second + c;
            if (cost[adj_v] > adj_c) {
                cost[adj_v] = adj_c;
                pq.push( {adj_c, adj_v} );
                par[adj_v] = v;
            }
        }
    }
    printf("%d\n", cost[e]);
    
    vector<int> route;
    while (e != s) {
        route.push_back(e);
        e = par[e];
    }
    route.push_back(s);
    
    printf("%d\n", (int)route.size());
    
    for (auto it = route.rbegin(); it != route.rend(); ++it)
        printf("%d ", *it);
    printf("\n");
    
    return 0;
}
