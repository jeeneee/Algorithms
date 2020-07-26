//
//  5852_Island Travels.cpp
//  Algorithms-CPP
//
//  Created by 장우진 on 2020/07/26.
//  Copyright © 2020 장우진. All rights reserved.
//

/*
This problem is somewhat complex, and the algorithm to solve it uses the following three major steps:

1. Flood fill to find the islands. (Both depth-first search, DFS, and breadth-first search, BFS, will work fine here.)

2. Flood fill to find the distances between all pairs of islands. (BFS should be considerably faster than DFS here.)

3. After finding the distances between all pairs of islands, find the minimum distance needed to traverse all islands.
   (This is a well-known problem that is also known as the Traveling Salesman Problem.)
   The simplest solution to this would be to try all possible orderings of the islands, but this is far too slow for N = 15.
   To speed up the algorithm, we can use dynamic programming, with our state consisting of our current location and the subset
   of islands that we have visited, and the value as the current total distance. This algorithm can be implemented either
   recursively or iteratively for a complexity of O(N2 x 2N).
*/

#include <iostream>
#include <cstring>
#include <queue>
#include <algorithm>
using namespace std;

const int dr[] = { 0, 1, 0, -1 };
const int dc[] = { 1, 0, -1, 0 };
const int INF = 2e9;
const int MAXN = 16;
const int MAXG = 55;
const int MAXS = 70000;

struct loc { int row, col, dis; };

int N, R, C;

char map[MAXG][MAXG + 1];
int group[MAXG][MAXG];

int tdist[MAXG][MAXG];
int dist[MAXN][MAXN];
queue<loc> q;

int best[MAXN][MAXS];
int masks[MAXS];
int msize;

int ans;

bool comp(int a, int b) {
   return __builtin_popcount(a) < __builtin_popcount(b);
}

void floodFill(int r, int c) {
   group[r][c] = N;
   for (int k = 0; k < 4; ++k) {
      int nr = r + dr[k];
      int nc = c + dc[k];
      if (map[nr][nc] == 'X' && group[nr][nc] == -1)
         floodFill(nr, nc);
   }
}

void solveIslands() {
   memset(group, -1, sizeof(group));

   N = 0;
   for (int i = 1; i <= R; ++i)
      for (int j = 1; j <= C; ++j)
         if (map[i][j] == 'X' && group[i][j] == -1) {
            floodFill(i, j);
            N++;
         }
}

void solveDist() {
   memset(dist, 0x3f, sizeof(dist));

   for (int i = 0; i < N; ++i) {
      int ir = -1, ic = -1;
      bool found = false;

      for (int r = 1; r <= R && !found; ++r)
         for (int c = 1; c <= C && !found; ++c)
            if (group[r][c] == i) {
               ir = r; ic = c;
               found = true;
            }

      memset(tdist, 0x3f, sizeof(tdist));

      q.push({ ir, ic, 0 });
      tdist[ir][ic] = 0;

      while (!q.empty()) {
         loc top = q.front(); q.pop();

         if (group[top.row][top.col] != -1 &&
            top.dis < dist[i][group[top.row][top.col]])
            dist[i][group[top.row][top.col]] = top.dis;

         for (int k = 0; k < 4; ++k) {
            int nr = top.row + dr[k];
            int nc = top.col + dc[k];
            if (map[nr][nc] == 'X' &&
               top.dis < tdist[nr][nc]) {
               tdist[nr][nc] = top.dis;
               q.push({ nr, nc, top.dis });
            }
            else if (map[nr][nc] == 'S' &&
               top.dis + 1 < tdist[nr][nc]) {
               tdist[nr][nc] = top.dis + 1;
               q.push({ nr, nc, top.dis + 1 });
            }
         }
      }
   }
}

void solveTsp() {
   memset(best, 0x3f, sizeof(best));

   for (int i = 0; i < N; ++i)
      best[i][1 << i] = 0;

   msize = 0;
   for (int m = 1; m < (1 << N); ++m)
      masks[msize++] = m;

   sort(masks, masks + msize, comp);

   for (int k = 0; k < msize; ++k) {
      int m = masks[k];

      for (int i = 0; i < N; ++i) {
         if (best[i][m] < INF) {
            for (int j = 0; j < N; ++j)
               if (best[i][m] + dist[i][j] < best[j][m | (1 << j)])
                  best[j][m | (1 << j)] = best[i][m] + dist[i][j];
         }
      }
   }

   ans = INF;

   for (int i = 0; i < N; ++i)
      ans = min(ans, best[i][(1 << N) - 1]);
}

int main() {
   ios::sync_with_stdio(false); cin.tie(0);

   memset(map, '.', sizeof(map));

   cin >> R >> C;

   for (int i = 1; i <= R; ++i)
      for (int j = 1; j <= C; ++j)
         cin >> map[i][j];

   solveIslands();
   solveDist();
   solveTsp();

   cout << ans << endl;

   return 0;
}
