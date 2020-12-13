//
//  14502_연구소.cpp
//  Algorithms-CPP
//
//  Created by 장우진 on 2020/02/02.
//  Copyright © 2020 장우진. All rights reserved.
//
/*
 3개의 벽을 세울 수 있는 모든 경우의 수를 완전 탐색해야 하므로 조합을 구하는 백트래킹 형식의 DFS와
 바이러스를 퍼뜨리는 데에 BFS를 적용하였다.
 */
#include <iostream>
#include <vector>
#include <cstring>
#include <queue>
#include <algorithm>
using namespace std;

typedef pair<int, int> pii;

const int MAX = 10;
const int dx[] = {-1, 1, 0, 0};
const int dy[] = {0, 0, -1, 1};
int n, m;
int map[MAX][MAX];
int temp_map[MAX][MAX];
queue<pii> virus;

// BFS
int spread_virus() {
    queue<pii> q = virus;
    while (!q.empty()) {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();
        for (int i = 0; i < 4; ++i) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if (temp_map[nx][ny] == 0) {
                q.push( {nx, ny} );
                temp_map[nx][ny] = 2;
            }
        }
    }
    int ret = 0;
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            if (temp_map[i][j] == 0)
                ++ret;
        }
    }
    return ret;
}

// DFS
int build_wall(int cnt) {
    int ret = 0;
    if (cnt == 3) {
        memcpy(temp_map, map, sizeof(map));
        return spread_virus();
    }
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            if (map[i][j] == 0) {
                map[i][j] = 1;
                ret = max(ret, build_wall(cnt + 1));
                map[i][j] = 0;
            }
        }
    }
    return ret;
}

int main() {
    memset(map, -1, sizeof(map));
    cin >> n >> m;
    
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= m; ++j)
            cin >> map[i][j];
    
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            if (map[i][j] == 2)
                virus.push(make_pair(i, j));
        }
    }
    
    cout << build_wall(0) << endl;
    
    return 0;
}
