//
//  2178_미로 탐색.cpp
//  Algorithms-CPP
//
//  Created by 장우진 on 2019/11/17.
//  Copyright © 2019 장우진. All rights reserved.
//

#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <algorithm>
using namespace std;

/* 위 아래 좌 우 */
const int dx[] = {0, 0, -1, 1};
const int dy[] = {-1, 1, 0, 0};
const int MAX = 102; // padding

int map[MAX][MAX];
queue<pair<int, int> > q;   // {x, y}

int main() {
    int n, m;   // 세로: n, 가로: m
    scanf("%d%d", &n, &m);

    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= m; ++j)
            scanf("%1d", &map[i][j]);
    
    int x, y;
    int ans = 0;
    if (map[1][1] == 1)
        q.push(make_pair(1, 1));
    while (!q.empty()) {
        ++ans;
        int size = (int)q.size();
        for (int i = 0; i < size; ++i) {
            x = q.front().first;
            y = q.front().second;
            if (x == m && y == n)
                goto EXIT;
            q.pop();
            for (int j = 0; j < 4; ++j) {
                if (map[ y + dy[j] ][ x + dx[j] ] == 1) {
                    map[ y + dy[j] ][ x + dx[j] ] = 0;
                    q.push(make_pair(x + dx[j], y + dy[j]));
                }
            }
        }
    }
EXIT:
    printf("%d\n", ans);
    return 0;
}
