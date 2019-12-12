//
//  1520_내리막길.cpp
//  Algorithms-CPP
//
//  Created by 장우진 on 2019/12/11.
//  Copyright © 2019 장우진. All rights reserved.
//
/*
 top-down dp
 */
#include <iostream>
#include <algorithm>
using namespace std;

const int MAX = 500;
const int dx[] = {0, 0, -1, 1};
const int dy[] = {-1, 1, 0, 0};

int map[MAX][MAX];
int dp[MAX][MAX];
int m, n, ans;

int dfs(int x, int y) {
    if (x == 0 && y == 0) return 1;
    if (dp[x][y] != -1) return dp[x][y];
    
    dp[x][y] = 0;
    
    for (int i = 0; i < 4; ++i) {
        int nx = x + dx[i];
        int ny = y + dy[i];
        if ( (0 <= nx && nx < n) && (0 <= ny && ny < m) ) {
            if (map[nx][ny] > map[x][y])
                dp[x][y] += dfs(nx, ny);
        }
    }
    return dp[x][y];
}

int main() {
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios::sync_with_stdio(false);
    
    cin >> n >> m;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cin >> map[i][j];
            dp[i][j] = -1;
        }
    }
    
    cout << dfs(n-1, m-1) << endl;
    
    return 0;
}
