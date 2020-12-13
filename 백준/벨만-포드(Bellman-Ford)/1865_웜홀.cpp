//
//  1865_웜홀.cpp
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

int main() {
   ios::sync_with_stdio(false); cin.tie(0);
   int tc;
   cin >> tc;
   while (tc--) {
      int n, m, w, s, e, t;
      cin >> n >> m >> w;
      vector<vector<Node>> adj(n + 1);
      vector<int> dist(n + 1, INF);

      while (m--) {
         cin >> s >> e >> t;
         adj[s].push_back({ e, t });
         adj[e].push_back({ s, t });
      }
      while (w--) {
         cin >> s >> e >> t;
         adj[s].push_back({ e, -t });
      }

      bool flag = false;
      dist[1] = 0;

      for (int i = 1; i <= n && !flag; ++i)
         for (int j = 1; j <= n && !flag; ++j)
            for (int k = 0; k < adj[j].size() && !flag; ++k) {
               int next = adj[j][k].next;
               int cost = adj[j][k].cost;
               if (dist[next] > dist[j] + cost) {
                  dist[next] = dist[j] + cost;
                  if (i == n) flag = true;
               }
            }

      if (flag) cout << "YES" << '\n';
      else cout << "NO" << '\n';
   }
   return 0;
}
