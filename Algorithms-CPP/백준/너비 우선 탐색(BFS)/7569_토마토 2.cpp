//
//  7569_토마토 2.cpp
//  Algorithms-CPP
//
//  Created by 장우진 on 2019/12/08.
//  Copyright © 2019 장우진. All rights reserved.
//
/*
 7576_토마토는 2차원 배열이고 이 문제는 3차원 배열을 사용해야 한다.
 */
#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

const int MAX = 102;
const int dx[6] = {0, 0, 0, 0, -1, 1};
const int dy[6] = {0, 0, -1, 1, 0, 0};
const int dz[6] = {-1, 1, 0, 0, 0, 0};

// x,y,z
int map[MAX][MAX][MAX];

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    
    for (int i = 0; i < MAX; ++i) {
        for (int j = 0; j < MAX; ++j) {
            fill(map[i][j], map[i][j] + MAX, -1);
        }
    }
    
    int m, n, h;
    cin >> m >> n >> h;
    
    // {z, {x, y} }
    queue<pair<int, pair<int, int> > > q;
    for (int z = 1; z <= h; ++z) {
        for (int y = 1; y <= n; ++y) {
            for (int x = 1; x <= m; ++x) {
                cin >> map[x][y][z];
                if (map[x][y][z] == 1)
                    q.push( {z, {x, y}} );
            }
        }
    }
   
    int days = q.empty() ? 0 : -1;
    while (!q.empty()) {
        int size = (int)q.size();
        
        for (int i = 0; i < size; ++i) {
            int x = q.front().second.first;
            int y = q.front().second.second;
            int z = q.front().first;
            q.pop();
            
            for (int j = 0; j < 6; ++j) {
                int nx = x + dx[j];
                int ny = y + dy[j];
                int nz = z + dz[j];
                
                if (map[nx][ny][nz] == 0) {
                    q.push( {nz, {nx, ny}} );
                    map[nx][ny][nz] = 1;
                }
            }
        }
        ++days;
    }
    
    for (int z = 1; z <= h; ++z) {
        for (int y = 1; y <= n; ++y) {
            for (int x = 1; x <= m; ++x) {
                if (map[x][y][z] == 0)
                    days = -1;
            }
        }
    }
    cout << days << endl;
    
    return 0;
}
