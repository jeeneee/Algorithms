//
//  20056_마법사 상어와 파이어볼.cpp
//  Algorithms-CPP
//
//  Created by 장우진 on 2020/10/20.
//  Copyright © 2020 장우진. All rights reserved.
//

#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
using namespace std;

struct Fireball { int m, s, d; };

const int dr[] = {-1, -1, 0, 1, 1, 1, 0, -1};
const int dc[] = {0, 1, 1, 1, 0, -1, -1, -1};
vector<Fireball> map[50][50];
int n, m, k;

bool even(vector<int>& dir) {
	for (auto& d : dir)
		if (d % 2 != 0) return false;
	return true;
}

bool odd(vector<int>& dir) {
	for (auto& d : dir)
		if (d % 2 == 0) return false;
	return true;
}

void go() {
	vector<Fireball> c_map[50][50];
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			for (auto& f : map[i][j]) {
				int nr = ((i + dr[f.d] * f.s) % n + n) % n;
				int nc = ((j + dc[f.d] * f.s) % n + n) % n;
				c_map[nr][nc].push_back({ f.m, f.s, f.d });
			}
			map[i][j].clear();
		}
	}
	
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			if (c_map[i][j].size() == 0) continue;
			else if (c_map[i][j].size() == 1) {
				map[i][j].push_back(c_map[i][j][0]);
				continue;
			}
			int m = 0, s = 0;
			vector<int> dir;
			for (auto& f : c_map[i][j]) {
				m += f.m;
				s += f.s;
				dir.push_back(f.d);
			}
			m /= 5;
			s /= c_map[i][j].size();
			if (m == 0) continue;
			if (even(dir) || odd(dir)) {
				for (int d = 0; d < 8; d += 2)
					map[i][j].push_back({ m, s, d });
			} else {
				for (int d = 0; d < 8; d += 2)
					map[i][j].push_back({ m, s, d+1 });
			}
		}
	}
}

int main() {
	ios::sync_with_stdio(false); cin.tie(0);
	cin >> n >> m >> k;
	for (int i = 0; i < m; ++i) {
		int r, c, m, s, d;
		cin >> r >> c >> m >> s >> d;
		map[r-1][c-1].push_back({ m, s, d });
	}
	
	for (int i = 0; i < k; ++i) go();
	
	int answer = 0;
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < n; ++j)
			for (auto& f : map[i][j])
				answer += f.m;
	
	cout << answer << endl;
	return 0;
}

