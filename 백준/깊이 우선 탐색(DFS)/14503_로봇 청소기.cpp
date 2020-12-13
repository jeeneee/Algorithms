//
//  14503_로봇 청소기.cpp
//  Algorithms-CPP
//
//  Created by 장우진 on 2020/02/02.
//  Copyright © 2020 장우진. All rights reserved.
//

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// 북, 동, 남, 서
const int dx[4] = {-1, 0, 1, 0};
const int dy[4] = {0, 1, 0, -1};
const int MAX = 50;
int map[MAX][MAX]; // 0 = no-clean, 1 = wall, 2 = cleaned

void clean(int x, int y, int d) {
    for (int i = 0; i < 4; ++i) {
        // 왼쪽 방향 설정
        d = (d + 3) % 4;
        int nx = x + dx[d];
        int ny = y + dy[d];
        if (map[nx][ny] == 0) {
            map[nx][ny] = 2;
            clean(nx, ny, d);
            return;
        }
    }
    // 사방이 청소되어 있거나 벽이 있는 경우 후진해야 한다.
    int nx = x + dx[(d + 2) % 4];
    int ny = y + dy[(d + 2) % 4];
    // 벽에 막혀 후진을 못하는 경우 탈출
    if (map[nx][ny] == 1)
        return;
    clean(nx, ny, d);
}

int main() {
    int n, m, r, c, d;
    cin >> n >> m >> r >> c >> d;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cin >> map[i][j];
        }
    }
    map[r][c] = 2;
    clean(r, c, d);
    int ans = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (map[i][j] == 2)
                ++ans;
        }
    }
    cout << ans << endl;
    return 0;
}
