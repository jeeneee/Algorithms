//
//  11404_플로이드.cpp
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
    int cost[MAX][MAX];
    int n, m;
    cin >> n >> m;
    // init cost
    for (int i = 0; i < n+1; ++i) {
        for (int j = 0; j < n+1; ++j) {
            if (i == j) cost[i][j] = 0;
            else cost[i][j] = INF;
        }
    }
    int a, b, c;
    while (m--) {
        cin >> a >> b >> c;
        cost[a][b] = min(cost[a][b], c);
    }
    
    // Floyd-Warshall Algorithm
    for (int k = 1; k < n + 1; ++k) {
        for (int i = 1; i < n + 1; ++i) {
            for (int j = 1; j < n + 1; ++j) {
                if (cost[i][j] > cost[i][k] + cost[k][j])
                    cost[i][j] = cost[i][k] + cost[k][j];
            }
        }
    }
    
    for (int i = 1; i < n+1; ++i) {
        for (int j = 1; j < n+1; ++j) {
            if (cost[i][j] == INF) cost[i][j] = 0;
            cout << cost[i][j] << ' ';
        }
        cout << '\n';
    }
    
    return 0;
}
