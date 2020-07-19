//
//  1800_인터넷 설치.cpp
//  Algorithms-CPP
//
//  Created by 장우진 on 2020/07/19.
//  Copyright © 2020 장우진. All rights reserved.
//
/*
 cost원 이하의 비용으로 1번 컴퓨터와 n번 컴퓨터의 연결 가능 여부를 판별하는 문제로 바꾼다.
 따라서 cost원 이하의 간선의 가중치는 0, cost원보다 비싼 간선의 가중치는 1로 잡고 다익스트라를 돌려준다.
 이분 탐색 + 다익스트라
 */
#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
#include <algorithm>
using namespace std;

typedef pair<int, int> pii;
const int MAX = 1000;
vector<pii> graph[MAX + 1];
int dist[MAX + 1];
int n, p, k;

bool dijkstra(int cost) {
   priority_queue<pii> pq;
   memset(dist, 0x3f, sizeof(dist));
   dist[1] = 0;
   pq.push({ 0, 1 });
   while (!pq.empty()) {
      int now = pq.top().second;
      int nowCost = -pq.top().first;
      pq.pop();

      if (dist[now] < nowCost) continue;

      for (auto& next : graph[now]) {
         int adj = next.first;
         int adjCost = nowCost + (next.second > cost);
         if (adjCost < dist[adj]) {
            dist[adj] = adjCost;
            pq.push({ -adjCost, adj });
         }
      }
   }
   return dist[n] <= k;
}

int main() {
   ios::sync_with_stdio(false); cin.tie(0);
   cin >> n >> p >> k;
   int u, v, d;
   for (int i = 0; i < p; i++) {
      cin >> u >> v >> d;
      graph[u].push_back({ v, d });
      graph[v].push_back({ u, d });
   }
   int ans = -1;
   int lo = 0, hi = 1e6;
   while (lo <= hi) {
      int mid = (lo + hi) / 2;
      if (dijkstra(mid)) {
         hi = mid - 1;
         ans = mid;
      }
      else {
         lo = mid + 1;
      }
   }
   cout << ans << endl;
   return 0;
}
