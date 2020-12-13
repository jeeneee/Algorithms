//
//  1937_욕심쟁이 판다.cpp
//  Algorithms-CPP
//
//  Created by 장우진 on 2020/01/06.
//  Copyright © 2020 장우진. All rights reserved.
//
/*
 LIS
 */
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

const int dx[] = {0, 0, -1, 1};
const int dy[] = {-1, 1, 0, 0};
int n;
int map[500][500];
int dp[500][500];

int move(int x, int y) {
    if (dp[x][y] != 0) return dp[x][y];
    dp[x][y] = 1;
    for (int i = 0; i < 4; ++i) {
        int nx = x + dx[i];
        int ny = y + dy[i];
        if ((0 <= nx && nx < n) && (0 <= ny && ny < n) &&
            map[x][y] < map[nx][ny]) {
            dp[x][y] = max(dp[x][y], move(nx, ny) + 1);
        }
    }
    return dp[x][y];
}

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL);
    cin >> n;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> map[i][j];
        }
    }
    int ans = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            ans = max(ans, move(i, j));
        }
    }
    cout << ans << endl;
    return 0;
}
