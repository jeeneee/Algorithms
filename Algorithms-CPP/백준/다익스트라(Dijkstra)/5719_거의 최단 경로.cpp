//
//  5719_거의 최단 경로.cpp
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

typedef pair<int, int> pii;

const int INF = 1234567890;

vector<vector<pii> > graph;
vector<vector<int> > trace;

vector<int> dijkstra(int source, int vertex) {
    priority_queue<pii, vector<pii>, greater<pii> > pq;
    vector<int> dist(vertex, INF);
    
    dist[source] = 0;
    pq.push(make_pair(dist[source], source));
    
    while (!pq.empty()) {
        int d = pq.top().first;
        int v = pq.top().second;
        pq.pop();
        
        if (dist[v] < d)
            continue;
        
        for (int i = 0; i < graph[v].size(); ++i) {
            int adj_d = d + graph[v][i].second;
            int adj_v = graph[v][i].first;
            
            // 삭제된 최단 거리의 경로는 무시한다.
            if (graph[v][i].second == -1)
                continue;
            
            if (dist[adj_v] > adj_d) {
                dist[adj_v] = adj_d;
                pq.push(make_pair(adj_d, adj_v));
                
                trace[adj_v].clear();
                trace[adj_v].push_back(v);
            }
            else if (dist[adj_v] == adj_d)
                trace[adj_v].push_back(v);
        }
    }
    return dist;
}

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int v, e, start, end, from, to, cost;
    while (1) {
        graph.clear();
        trace.clear();
        
        cin >> v >> e;
        
        if (v == 0 && e == 0)
            break;
        
        graph.resize(v);
        trace.resize(v);
        cin >> start >> end;
        while (e--) {
            cin >> from >> to >> cost;
            graph[from].push_back(make_pair(to, cost));
        }
        
        // 최단 거리의 경로(trace)를 찾음
        dijkstra(start, v);
        
        // BFS
        queue<int> q;
        q.push(end);
        while (!q.empty()) {
            int v = q.front();
            q.pop();
            for (int i = 0; i < trace[v].size(); ++i) {
                int adj_v = trace[v][i];
                for (int j = 0; j < graph[adj_v].size(); ++j) {
                    if (graph[adj_v][j].first == v)
                        graph[adj_v][j].second = -1;
                }
                q.push(adj_v);
            }
        }
        
        // 다익스트라를 다시 이용해 거의 최단 거리를 구한다.
        vector<int> res = dijkstra(start, v);
        
        if (res[end] == INF)
            cout << -1 << endl;
        else
            cout << res[end] << endl;
    }
    return 0;
}
