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

struct Node { int next, cost; };
const int INF = 1e9;

vector<vector<Node>> adj;
vector<long long> dist;
int n, m, a, b, c;

int main() {
   scanf("%d %d", &n, &m);
   adj.resize(n + 1);
   dist.resize(n + 1, INF);
   while (m--) {
      scanf("%d %d %d", &a, &b, &c);
      adj[a].push_back({ b, c });
   }

   dist[1] = 0;
   bool flag = false;
   
   for (int i = 1; i <= n && !flag; ++i)
      for (int j = 1; j <= n && !flag; ++j)
         for (int k = 0; k < adj[j].size() && !flag; ++k) {
            int next = adj[j][k].next;
            int cost = adj[j][k].cost;
            if (dist[j] != INF && dist[next] > dist[j] + cost) {
               dist[next] = dist[j] + cost;
               if (i == n) flag = true;
            }
         }

   if (flag) puts("-1");
   else for (int i = 2; i <= n; ++i)
        printf("%lld\n", dist[i] == INF ? -1 : dist[i]);

   return 0;
}
