//
//  17144_미세먼지 안녕!.cpp
//  Algorithms-CPP
//
//  Created by 장우진 on 2020/03/09.
//  Copyright © 2020 장우진. All rights reserved.
//
/*
 문제: 미세먼지가 주위로 퍼진다. 순차적으로 퍼지는 게 아닌, 동시다발적으로 퍼져야 하기 때문에 맵을 하나
	  복사하여 기존의 맵은 참조로 사용하고 복사한 맵은 업데이트를 진행한다. 후에 기존의 맵으로 다시 복사한다.
	  여기서 공기 청정기의 순환을 구현하는 과정이 까다로웠다. 코드를 더 줄여서 진행해보려 하였지만 오히려
	  그게 더 시간 낭비일 것 같아 노가다를 하였다.
 O(RCT) = 50x50x1000 최악의 경우 250만
 */
#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
using namespace std;

const int dx[] = {-1, 0, 0, 1};
const int dy[] = {0, -1, 1, 0};
const int MAX = 50;
int r, c, t;
int map[MAX][MAX];
int c_map[MAX][MAX];
int air_x1, air_x2;

void spread() {
	memcpy(c_map, map, sizeof(map));
	for (int x = 0; x < r; ++x) {
		for (int y = 0; y < c; ++y) {
			int dust = map[x][y];
			if (dust < 5) continue;
			int cnt = 0;
			for (int i = 0; i < 4; ++i) {
				int nx = x + dx[i];
				int ny = y + dy[i];
				if ((0 <= nx && nx < r) && (0 <= ny && ny < c)) {
					if (map[nx][ny] != -1) {
						c_map[nx][ny] += dust / 5;
						cnt++;
					}
				}
			}
			c_map[x][y] -= (dust / 5) * cnt;
		}
	}
	memcpy(map, c_map, sizeof(map));
}

void circulate() {
	// ccw
	for (int i = air_x1 - 1; i-1 >= 0; --i)
		map[i][0] = map[i-1][0];
	for (int j = 0; j+1 <= c-1; ++j)
		map[0][j] = map[0][j+1];
	for (int i = 0; i+1 <= air_x1; ++i)
		map[i][c-1] = map[i+1][c-1];
	for (int j = c-1; j-1 > 0; --j)
		map[air_x1][j] = map[air_x1][j-1];
	map[air_x1][1] = 0;
	// cw
	for (int i = air_x2 + 1; i+1 <= r-1; ++i)
		map[i][0] = map[i+1][0];
	for (int j = 0; j+1 <= c-1; ++j)
		map[r-1][j] = map[r-1][j+1];
	for (int i = r-1; i-1 >= air_x2; --i)
		map[i][c-1] = map[i-1][c-1];
	for (int j = c-1; j-1 > 0; --j)
		map[air_x2][j] = map[air_x2][j-1];
	map[air_x2][1] = 0;
}

int main() {
	ios::sync_with_stdio(false); cin.tie(0);
	cin >> r >> c >> t;
	for (int i = 0; i < r; ++i) {
		for (int j = 0; j < c; ++j) {
			cin >> map[i][j];
			if (map[i][j] == -1) {
				if (air_x1 == 0)
					air_x1 = i;
				else
					air_x2 = i;
			}
		}
	}
	
	while (t--) {
		spread();
		circulate();
	}
	
	int ans = 0;
	for (int i = 0; i < r; ++i) {
		for (int j = 0; j < c; ++j) {
			if (map[i][j] != -1)
				ans += map[i][j];
		}
	}
	cout << ans << endl;
	return 0;
}
