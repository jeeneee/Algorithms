//
//  1956_운동.cpp
//  Algorithms-CPP
//
//  Created by 장우진 on 2020/01/07.
//  Copyright © 2020 장우진. All rights reserved.
//

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

const int MAX = 400 + 1;
const int INF = 987654321;
int cost[MAX][MAX];

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL);
    int V, E;
    cin >> V >> E;
    
    for (int i = 1; i <= V; ++i)
        for (int j = 1; j <= V; ++j)
            cost[i][j] = (i == j ? 0 : INF);
    
    int u, v, c;
    for (int i = 0; i < E; ++i) {
        cin >> u >> v >> c;
        cost[u][v] = c;
    }
    
    for (int k = 1; k <= V; ++k) {
        for (int i = 1; i <= V; ++i) {
            for (int j = 1; j <= V; ++j) {
                if (cost[i][j] > cost[i][k] + cost[k][j])
                    cost[i][j] = cost[i][k] + cost[k][j];
            }
        }
    }
    
    int ans = INF;
    for (int i = 1; i <= V; ++i) {
        for (int j = 1; j <= V; ++j) {
            if (i == j) continue;
            ans = min(ans, cost[i][j] + cost[j][i]);
        }
    }
    
    if (ans == INF)
        cout << -1 << endl;
    else
        cout << ans << endl;
    
    return 0;
}
