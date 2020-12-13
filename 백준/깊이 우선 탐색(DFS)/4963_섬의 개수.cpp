//
//  4963_섬의 개수.cpp
//  Algorithms-CPP
//
//  Created by 장우진 on 2019/11/17.
//  Copyright © 2019 장우진. All rights reserved.
//

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

/* 위 아래 좌상 좌 좌하 우상 우 우하 */
const int dx[] = {0, 0, -1, -1, -1, 1, 1, 1};
const int dy[] = {-1, 1, -1, 0, 1, -1, 0, 1};
const int MAX = 52; // padding
int map[MAX][MAX];

void dfs(int x, int y) {
    map[y][x] = 0;
    for (int i = 0; i < 8; ++i) {
        if (map[ y + dy[i] ][ x + dx[i] ])
            dfs(x + dx[i], y + dy[i]);
    }
}

int main() {
    int w, h;
    while (true) {
        for (int i = 0; i < MAX; ++i) {
            for (int j = 0; j < MAX; ++j) {
                map[i][j] = 0;
            }
        }
        scanf("%d%d", &w, &h);
        if (w == 0 && h == 0)
            break;
        for (int i = 1; i <= h; ++i)
            for (int j = 1; j <= w; ++j)
                scanf("%1d", &map[i][j]);
        int cnt = 0;
        for (int i = 1; i <= h; ++i)
            for (int j = 1; j <= w; ++j)
                if (map[i][j]) {
                    dfs(j, i);
                    ++cnt;
                }
        printf("%d\n", cnt);
    }
    return 0;
}
