//
//  1767_[SW Test 샘플문제] 프로세서 연결하기.cpp
//  Algorithms-CPP
//
//  Created by 장우진 on 2020/03/24.
//  Copyright © 2020 장우진. All rights reserved.
//
/*
 백트래킹 문제.
 */
#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
using namespace std;

const int dx[] = {-1, 1, 0, 0};
const int dy[] = {0, 0, -1, 1};
const int INF = 987654321;
const int MAX = 12;
int map[MAX][MAX];
vector<pair<int, int>> core;
int max_core, min_len;
int n;

vector<pair<int, int>> connect(int idx, int d) {
	int x = core[idx].first;
	int y = core[idx].second;
	vector<pair<int, int>> pos;
	while (1) {
		int nx = x + dx[d];
		int ny = y + dy[d];
		if ((0 <= nx && nx < n) && (0 <= ny && ny < n)) {
			if (map[nx][ny] != 0) {
				pos.clear();
				break;
			}
			pos.push_back( {nx, ny} );
			x = nx; y = ny;
		} else
			break;
	}
	return pos;
}

// 코어 인덱스, 전선 길이, 코어 개수
void dfs(int idx, int len, int cnt) {
	if (max_core > core.size() - idx + cnt) return;
	if (idx == core.size()) {
		if (cnt > max_core) {
			max_core = cnt;
			min_len = len;
		}
		else if (cnt == max_core && len < min_len)
			min_len = len;
		return;
	}
	for (int i = 0; i < 4; ++i) {
		vector<pair<int, int>> pos = connect(idx, i);
		if (pos.size()) {
			for (auto& p: pos)
				map[p.first][p.second] = 2;
			dfs(idx+1, len+pos.size(), cnt+1);
			for (auto& p: pos)
				map[p.first][p.second] = 0;
		}
	}
	dfs(idx+1, len, cnt);
}

int main() {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int T;
	cin >> T;
	for (int tc = 1; tc <= T; ++tc) {
		core.clear();
		max_core = 0;
		min_len = INF;
		cin >> n;
		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < n; ++j) {
				cin >> map[i][j];
				if ( (map[i][j] == 1) &&
					((0 < i && i < n-1) && (0 < j && j < n-1)) )
					core.push_back( {i, j} );
			}
		}
		dfs(0, 0, 0);
		cout << "#" << tc << " " << min_len << '\n';
	}
	return 0;
}
