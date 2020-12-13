//
//  2146_다리 만들기.cpp
//  Algorithms-CPP
//
//  Created by 장우진 on 2019/11/18.
//  Copyright © 2019 장우진. All rights reserved.
//

#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <algorithm>
#include <climits>
using namespace std;

typedef pair<int, int> pii;
/* 위 아래 좌 우 */
const int dx[] = {0, 0, -1, 1};
const int dy[] = {-1, 1, 0, 0};
const int MAX = 100; // padding

int map[MAX][MAX];
queue<pii> q;   // {x, y}
int land_num = 1;
int n;  // n: 세로, 가로

void dfs(int x, int y) {
    map[y][x] = land_num;
    bool flag = false;
    for (int i = 0; i < 4; ++i) {
        int nx = x + dx[i];
        int ny = y + dy[i];
        if (nx < 0 || ny < 0 || nx >= n || ny >= n) continue;
        if (map[ny][nx] == -1)
            dfs(nx, ny);
        else if (map[ny][nx] == 0)
            flag = true;
    }
    if (flag)
        q.push(make_pair(x, y));
}

int bfs() {
    int cnt = 0;
    while (!q.empty()) {
        int size = (int)q.size();
        for (int i = 0; i < size; ++i) {
            int x = q.front().first;
            int y = q.front().second;
            q.pop();
            for (int j = 0; j < 4; ++j) {
                int nx = x + dx[j];
                int ny = y + dy[j];
                if (nx < 0 || ny < 0 || nx >= n || ny >= n) continue;
                if (!map[ny][nx]) {
                    map[ny][nx] = map[y][x];
                    q.push(make_pair(nx, ny));
                }
                else {
                    if (map[ny][nx] < map[y][x]) {
                        cnt++;
                        goto EXIT;
                    }
                    else if (map[ny][nx] > map[y][x]) {
                        goto EXIT;
                    }
                }
            }
        }
        cnt += 2;
    }
EXIT:
    return cnt;
}

int main() {
    scanf("%d", &n);

    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j) {
            scanf("%d", &map[i][j]);
            map[i][j] = -map[i][j];
        }
    
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (map[i][j] == -1) {
                dfs(j, i);
                land_num++;
            }
        }
    }
    printf("%d\n", bfs());
    return 0;
}
