//
//  1012_유기농 배추.cpp
//  Algorithms-CPP
//
//  Created by 장우진 on 2019/12/08.
//  Copyright © 2019 장우진. All rights reserved.
//
/*
 4963_섬의 개수 와 비슷함.
 */
#include <iostream>
#include <algorithm>
using namespace std;

const int dx[4] = {0, 0, -1, 1};
const int dy[4] = {-1, 1, 0, 0};
const int MAX = 52;

int map[MAX][MAX];

void dfs(int x, int y) {
    map[y][x] = 0;
    
    for (int i = 0; i < 4; ++i) {
        int nx = x + dx[i];
        int ny = y + dy[i];
        
        if (map[ny][nx])
            dfs(nx, ny);
    }
}

int main() {
    int t, n, m, k, x, y;
    cin >> t;
    while (t--) {
        // 세로 n, 가로 m
        cin >> m >> n >> k;
        while (k--) {
            cin >> x >> y;
            map[y+1][x+1] = 1;
        }
        
        int res = 0;
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= m; ++j) {
                if (map[i][j]) {
                    dfs(j, i);
                    ++res;
                }
            }
        }
        cout << res << endl;
    }
    return 0;
}
