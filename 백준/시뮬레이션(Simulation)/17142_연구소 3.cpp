//
//  17142_연구소 3.cpp
//  Algorithms-CPP
//
//  Created by 장우진 on 2020/03/11.
//  Copyright © 2020 장우진. All rights reserved.
//
/*
 문제: <17141_연구소 2>와 다르게 선택되지 않은 바이러스를 0으로 하면 안된다. 활성 바이러스가 비활성
	  바이러스에 가면 비활성 바이러스가 활성화된다. 이 과정은 시간에 포함되지 않아야 한다. 그렇기 때문에
	  시간을 관리하는 t 배열을 만들어 매 조합마다 초기화를 하고 BFS에서 전체 시간 매개변수를 하나 생성해
	  이동한 칸이 빈 칸일 때만 업데이트를 진행해준다.
 알고리즘: bfs + dfs
 */
#include <iostream>
#include <queue>
#include <vector>
#include <cstring>
#include <algorithm>
using namespace std;

const int dx[] = {0, 0, -1, 1};
const int dy[] = {-1, 1, 0, 0};
const int INF = 987654321;
const int MAX = 50;
int map[MAX][MAX], t[MAX][MAX];
vector<pair<int, int>> virus;
vector<bool> sel;
int N, M, room, ans = INF;

void spreadVirus(queue<pair<int, int>>& q) {
	int emptyRoom = room;
	int total = 0;
	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		q.pop();
		for (int i = 0; i < 4; ++i) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			if ((0 <= nx && nx < N) && (0 <= ny && ny < N)) {
				if (map[nx][ny] == 1 || t[nx][ny] != -1)
					continue;
				t[nx][ny] = t[x][y] + 1;
				if (map[nx][ny] == 0) {
					emptyRoom--;
					total = t[nx][ny];
				}
				q.push( {nx, ny} );
			}
		}
	}
	if (emptyRoom == 0)
		ans = min(ans, total);
}

void selectVirus(int idx, int cnt) {
	if (cnt == M) {
		memset(t, -1, sizeof(t));
		queue<pair<int, int>> q;
		for (int i = 0; i < sel.size(); ++i)
			if (sel[i]) {
				q.push(virus[i]);
				t[virus[i].first][virus[i].second] = 0;
			}
		spreadVirus(q);
		return;
	}
	// dfs
	for (int i = idx; i < virus.size(); ++i) {
		sel[i] = true;
		selectVirus(i+1, cnt+1);
		sel[i] = false;
	}
}

int main() {
	cin >> N >> M;
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < N; ++j) {
			cin >> map[i][j];
			if (map[i][j] == 0) room++;
			else if (map[i][j] == 2) virus.push_back( {i, j} );
		}
	}
	
	sel.resize(virus.size());
	selectVirus(0, 0);
	
	if (ans == INF) ans = -1;
	cout << ans << '\n';
	return 0;
}
