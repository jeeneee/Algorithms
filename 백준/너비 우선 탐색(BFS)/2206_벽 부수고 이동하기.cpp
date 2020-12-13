//
//  2206_벽 부수고 이동하기.cpp
//  Algorithms-CPP
//
//  Created by 장우진 on 2019/12/08.
//  Copyright © 2019 장우진. All rights reserved.
//

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

typedef pair<int, int> pii;
typedef pair<int, pii> pipii;

const int MAX = 1000;
const int dx[4] = {0, 0, -1, 1};
const int dy[4] = {-1, 1, 0, 0};

int map[MAX][MAX];
int cache[MAX][MAX][2];

int BFS(int m, int n) {
    // {op, {x, y} }
    queue<pipii> q;
    q.push( {1, {0, 0}} );
    cache[0][0][1] = 1;
    while (!q.empty()) {
        int op = q.front().first;
        int x = q.front().second.first;
        int y = q.front().second.second;
        q.pop();
        
        if (x == m-1 && y == n-1)
            return cache[x][y][op];
        
        for (int i = 0; i < 4; ++i) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            
            if ( (0 <= nx && nx < m) && (0 <= ny && ny < n) ) {
                if (map[nx][ny] == 0 && cache[nx][ny][op] == 0) {
                    cache[nx][ny][op] = cache[x][y][op] + 1;
                    q.push( {op, {nx, ny}} );
                }
                else if (map[nx][ny] == 1 && op) {
                    cache[nx][ny][op-1] = cache[x][y][op] + 1;
                    q.push( {op-1, {nx, ny}} );
                }
            }
        }
    }
    return -1;
}

int main() {
    int n, m;
    scanf("%d %d", &n, &m);
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            scanf("%1d", &map[j][i]);
        }
    }
    
    printf("%d\n", BFS(m, n));
    
    return 0;
}
