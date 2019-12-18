//
//  1389_케빈 베이컨의 6단계 법칙.cpp
//  Algorithms-CPP
//
//  Created by 장우진 on 2019/12/18.
//  Copyright © 2019 장우진. All rights reserved.
//

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

const int INF = 987654321;
const int MAX = 101;

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    int dist[MAX][MAX];
    int n, m, u, v;
    cin >> n >> m;
    // init dist
    for (int i = 0; i < n+1; ++i) {
        for (int j = 0; j < n+1; ++j) {
            if (i == j) dist[i][j] = 0;
            else dist[i][j] = INF;
        }
    }
    while (m--) {
        cin >> u >> v;
        dist[u][v] = dist[v][u] = 1;
    }
    
    // Floyd-Warshall Algorithm
    for (int k = 1; k < n + 1; ++k) {
        for (int i = 1; i < n + 1; ++i) {
            for (int j = 1; j < n + 1; ++j) {
                if (dist[i][j] > dist[i][k] + dist[k][j])
                    dist[i][j] = dist[i][k] + dist[k][j];
            }
        }
    }
    
    int ans = 0, min_sum = INF;
    for (int i = 1; i < n+1; ++i) {
        int sum = 0;
        for (int j = 1; j < n+1; ++j) {
            sum += dist[i][j];
        }
        if (sum < min_sum) {
            min_sum = sum;
            ans = i;
        }
    }
    cout << ans << '\n';
    
    return 0;
}
