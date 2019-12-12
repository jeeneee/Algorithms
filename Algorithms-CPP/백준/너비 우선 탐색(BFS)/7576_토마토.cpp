//
//  7576_토마토.cpp
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
const int MAX = 1002; // padding

int map[MAX][MAX];
queue<pair<int, int> > q;   // {x, y}

int main() {
    int m, n;   // 가로: m, 세로: n
    scanf("%d%d", &m, &n);
    for (int i = 0; i < MAX; ++i)
        fill(map[i], map[i] + MAX, -1);

    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            scanf("%d", &map[i][j]);
            if (map[i][j] == 1)
                q.push(make_pair(j, i));
        }
    }
    int days = (q.empty() ? 0 : -1);
    int x, y;
    while (!q.empty()) {
        ++days;
        int size = (int)q.size();
        for (int i = 0; i < size; ++i) {
            x = q.front().first;
            y = q.front().second;
            q.pop();
            for (int j = 0; j < 4; ++j) {
                if (map[ y + dy[j] ][ x + dx[j] ] == 0) {
                    map[ y + dy[j] ][ x + dx[j] ] = 1;
                    q.push(make_pair(x + dx[j], y + dy[j]));
                }
            }
        }
    }
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            if (map[i][j] == 0)
                days = -1;
        }
    }
    printf("%d\n", days);
    return 0;
}
