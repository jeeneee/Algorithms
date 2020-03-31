//
//  1953_[모의 SW 역량테스트] 탈주범 검거.cpp
//  Algorithms-CPP
//
//  Created by 장우진 on 2020/03/31.
//  Copyright © 2020 장우진. All rights reserved.
//
/*
 문제: 지하 터널 지도와 맨홀 뚜껑의 위치, 경과된 시간이 주어질 때 탈주범이 위치할 수 있는 장소의 최대 개수를 구하는 문제.
 해설: 7개의 파이프의 형태가 모두 다르기 때문에 그에 따른 상수를 지정하는 게 포인트이다.
 알고리즘: BFS
 */
#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
#include <algorithm>
using namespace std;

// 상하좌우
const int dx[] = {-1, 1, 0, 0};
const int dy[] = {0, 0, -1, 1};
const vector<int> func[7] = {
	{0, 1, 2, 3},
	{0, 1},
	{2, 3},
	{0, 3},
	{1, 3},
	{1, 2},
	{0, 2}
};
const int MAX = 50;
int map[MAX][MAX];
bool visited[MAX][MAX];
int N, M, L, ans;

void bfs(queue<pair<int, int>>& q) {
	int cnt = 1;
	while (!q.empty()) {
		if (cnt == L)
			break;
		int size = q.size();
		while (size--) {
			int x = q.front().first;
			int y = q.front().second;
			q.pop();
			for (auto& i : func[map[x][y] - 1]) {
				int nx = x + dx[i];
				int ny = y + dy[i];
				if (nx < 0 || nx >= N || ny < 0 || ny >= M)
					continue;
				if (map[nx][ny] != 0 && !visited[nx][ny]) {
					bool possible = false;
					for (auto& j : func[map[nx][ny] - 1])
						if (j == (5-i) % 4)
							possible = true;
					if (possible) {
						q.push( {nx, ny} );
						visited[nx][ny] = true;
						ans++;
					}
				}
			}
		}
		cnt++;
	}
}

int main() {
	ios::sync_with_stdio(false); cin.tie(0);
	int T;
	cin >> T;
	for (int tc = 1; tc <= T; ++tc) {
		memset(visited, false, sizeof(visited));
		queue<pair<int, int>> q;
		int R, C;
		cin >> N >> M >> R >> C >> L;
		q.push( {R, C} );
		visited[R][C] = true;
		for (int i = 0; i < N; ++i) {
			for (int j = 0; j < M; ++j) {
				cin >> map[i][j];
			}
		}
		ans = 1;
		bfs(q);
		cout << "#" << tc << " " << ans << "\n";
	}
	return 0;
}
