//
//  1261_알고스팟.cpp
//  Algorithms-CPP
//
//  Created by 장우진 on 2019/11/28.
//  Copyright © 2019 장우진. All rights reserved.
//
/*
 기본적인 bfs와 같고 큐만 우선순위 큐(priority queue)로 바꿨을 뿐인데,
 빠르고 쉽게 최단 거리를 구할 수 있다.
 벽을 부수는 횟수를 맨 앞으로 두고 최소 힙 큐로 우선 순위를 정하였다.
 */
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

typedef pair<int, int> pii;
typedef pair<int, pii> pipii;

const int MAX = 100;
const int dx[4] = {0, 0, -1, 1};
const int dy[4] = {-1, 1, 0, 0};

char map[MAX][MAX+1];
bool visited[MAX][MAX];

int dijkstra(const int n, const int m) {
    priority_queue<pipii, vector<pipii>, greater<pipii> > pq;
    pq.push( {0, {0, 0}} ); // {cnt, {x, y}}
    visited[0][0] = true;
    
    while (!pq.empty()) {
        int cnt = pq.top().first;
        int x = pq.top().second.first;
        int y = pq.top().second.second;
        pq.pop();
        
        if (x == m - 1 && y == n - 1)
            return cnt;
        
        for (int i = 0; i < 4; ++i) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if ( (0 <= nx && nx < m) && (0 <= ny && ny < n) ) {
                if (!visited[ny][nx]) {
                    if (map[ny][nx] == '1')
                        pq.push( {cnt+1, {nx, ny}} );
                    else
                        pq.push( {cnt, {nx, ny}} );
                    visited[ny][nx] = true;
                }
            }
        }
    }
    return 0;
}

int main() {
    int n, m;
    scanf("%d%d", &m, &n);
    for (int i = 0; i < n; ++i)
        scanf("%s", map[i]);
    
    printf("%d\n", dijkstra(n, m));
    
    return 0;
    
}
