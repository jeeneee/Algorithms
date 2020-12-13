//
//  5644_[모의 SW 역량테스트] 무선 충전.cpp
//  Algorithms-CPP
//
//  Created by 장우진 on 2020/04/02.
//  Copyright © 2020 장우진. All rights reserved.
//
/*
 문제: 두 사람이 움직이며 규칙에 따른 무선 충전기의 영향을 받아 충전하는 양의 최대값을 구하는 문제.
 해설: 우선 최대 8대의 무선 충전기에 영역을 맵에 표시해준다. 그리고 두 사람을 움직이며 최대값을 계산한다.
 */
#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
#include <cmath>
#include <algorithm>
using namespace std;

struct User {
	int x, y, battery;
};

// 이동x, 상, 우, 하, 좌
const int dx[] = {0, -1, 0, 1, 0};
const int dy[] = {0, 0, 1, 0, -1};
const int n = 10;
int dir[2][101]; // 두 사람이 움직이는 방향
vector<int> map[n][n]; // 무선 충전기의 번호
int power[8]; // 각 무선 충전기의 충전량
int m, numCharger; // 움직인 횟수, 충전기 개수

// 맨하튼 거리
inline int dist(int x1, int y1, int x2, int y2) {
	return abs(x1-x2) + abs(y1-y2);
}

// 충전기의 영역을 맵으로 확장
void expand(int x, int y, int c, int idx) {
	for (int i = x-c; i <= x+c; ++i)
		for (int j = y-c; j <= y+c; ++j)
			if ((0 <= i && i < n) && (0 <= j && j < n))
				if (dist(i, j, x, y) <= c)
					map[i][j].push_back(idx);
}

// 두 사람을 움직이며 충전량을 계산한다.
int mov() {
	int ret = 0;
	User user[2];
	user[0] = {0, 0, 0};
	user[1] = {9, 9, 0};
	for (int i = 0; i <= m; ++i) {
		for (int j = 0; j < 2; ++j) {
			user[j].x += dx[dir[j][i]];
			user[j].y += dy[dir[j][i]];
		}
		int x1 = user[0].x;
		int y1 = user[0].y;
		int x2 = user[1].x;
		int y2 = user[1].y;
		int maxPower = 0;
		// 두 사람이 모두 충전기의 범위 안에 있을 경우
		if (map[x1][y1].size() && map[x2][y2].size()) {
			// 이중 포문
			for (auto& idx1 : map[x1][y1]) {
				for (auto& idx2 : map[x2][y2]) {
					// 겹치는 충전기가 있을 때 어차피 두 사람의 충전량 합을 구하는 것이므로,
					// 최대값을 바로 계산하면 된다.
					if (idx1 == idx2) maxPower = max(maxPower, power[idx1]);
					else maxPower = max(maxPower, power[idx1] + power[idx2]);
				}
			}
		} else if (map[x1][y1].size()) { // A만 충전 범위에 있는 경우
			for (auto& idx1 : map[x1][y1])
				maxPower = max(maxPower, power[idx1]);
		} else if (map[x2][y2].size()) { // B만 충전 범위에 있는 경우
			for (auto& idx2 : map[x2][y2])
				maxPower = max(maxPower, power[idx2]);
		}
		ret += maxPower;
	}
	return ret;
}

int main() {
	int T;
	scanf("%d", &T);
	for (int tc = 1; tc <= T; ++tc) {
		// 초기화
		for (int i = 0; i < n; ++i)
			for (int j = 0; j < n; ++j)
				map[i][j].clear();
		scanf("%d %d", &m, &numCharger);
		// 0초일 때도 포함된다.
		dir[0][0] = dir[1][0] = 0;
		for (int i = 0; i < 2; ++i)
			for (int j = 1; j <= m; ++j)
				scanf("%d", &dir[i][j]);
		// 각 충전기의 정보를 저장하고 맵으로 확장시킨다.
		for (int i = 0; i < numCharger; ++i) {
			int x, y, c, p;
			scanf("%d %d %d %d", &y, &x, &c, &p);
			x--; y--;
			power[i] = p;
			expand(x, y, c, i);
		}
		printf("#%d %d\n", tc, mov());
	}
	return 0;
}
