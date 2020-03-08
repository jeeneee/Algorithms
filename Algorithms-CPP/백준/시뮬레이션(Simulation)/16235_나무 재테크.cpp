//
//  16235_나무 재테크.cpp
//  Algorithms-CPP
//
//  Created by 장우진 on 2020/03/08.
//  Copyright © 2020 장우진. All rights reserved.
//
/*
 문제: 아래 주석 참고
 알고리즘: 덱
 */
#include <iostream>
#include <vector>
#include <deque>
#include <cstring>
#include <algorithm>
using namespace std;

const int dx[] = {-1, -1, -1, 0, 0, 1, 1, 1};
const int dy[] = {-1, 0, 1, -1, 1, -1, 0, 1};
const int MAX = 12;
int map[MAX][MAX];
int A[MAX][MAX];
int num[MAX][MAX];
deque<int> age[MAX][MAX];
int n, m, k;

int main() {
	ios::sync_with_stdio(false); cin.tie(0);
	memset(map, -1, sizeof(map));
	cin >> n >> m >> k;
	for (int i = 1; i <= n; ++i)
		for (int j = 1; j <= n; ++j) {
			cin >> A[i][j];
			map[i][j] = 5;
		}
	// 처음으로 주어지는 나무 정보
	while (m--) {
		int x, y, z;
		cin >> x >> y >> z;
		age[x][y].push_back(z);
		num[x][y]++;
	}
	/*
	 봄에는 나무가 자신의 나이만큼 양분을 먹고, 나이가 1 증가한다. 각각의 나무는 나무가 있는 1×1 크기의 칸에 있는 양분만 먹을 수 있다.
	 하나의 칸에 여러 개의 나무가 있다면, 나이가 어린 나무부터 양분을 먹는다.
	 만약, 땅에 양분이 부족해 자신의 나이만큼 양분을 먹을 수 없는 나무는 양분을 먹지 못하고 즉시 죽는다.
	 
	 여름에는 봄에 죽은 나무가 양분으로 변하게 된다. 각각의 죽은 나무마다 나이를 2로 나눈 값이 나무가 있던 칸에 양분으로 추가된다.
	 소수점 아래는 버린다.
	 
	 가을에는 나무가 번식한다. 번식하는 나무는 나이가 5의 배수이어야 하며, 인접한 8개의 칸에 나이가 1인 나무가 생긴다.
	 상도의 땅을 벗어나는 칸에는 나무가 생기지 않는다.
	 
	 겨울에는 S2D2가 땅을 돌아다니면서 땅에 양분을 추가한다. 각 칸에 추가되는 양분의 양은 A[r][c]이고, 입력으로 주어진다.
	 */
	// k년 동안 위 단계를 반복
	while (k--) {
		// 봄, 여름
		for (int i = 1; i <= n; ++i) {
			for (int j = 1; j <= n; ++j) {
				int fertilizer = 0;
				if (num[i][j]) {
					deque<int>::iterator it = age[i][j].begin();
					for (auto& a : age[i][j]) {
						if (a <= map[i][j]) {
							map[i][j] -= a;
							a++;
							it++;
						} else {
							fertilizer += a / 2;
							num[i][j]--;
						}
					}
					map[i][j] += fertilizer;
					age[i][j].erase(it, age[i][j].end());
				}
			}
		}
		// 가을
		for (int x = 1; x <= n; ++x) {
			for (int y = 1; y <= n; ++y) {
				if (num[x][y]) {
					for (auto& a : age[x][y]) {
						if (a % 5 == 0) {
							for (int i = 0; i < 8; ++i) {
								int nx = x + dx[i];
								int ny = y + dy[i];
								if (map[nx][ny] == -1)
									continue;
								age[nx][ny].push_front(1);
								num[nx][ny]++;
							}
						}
					}
				}
			}
		}
		// 겨울
		for (int i = 1; i <= n; ++i)
			for (int j = 1; j <= n; ++j)
				map[i][j] += A[i][j];
	}
	int cnt = 0;
	for (int i = 1; i <= n; ++i)
		for (int j = 1; j <= n; ++j)
			cnt += num[i][j];
	cout << cnt << endl;
	return 0;
}
