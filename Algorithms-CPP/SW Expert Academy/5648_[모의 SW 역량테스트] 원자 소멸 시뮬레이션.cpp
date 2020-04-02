//
//  5648_[모의 SW 역량테스트] 원자 소멸 시뮬레이션.cpp
//  Algorithms-CPP
//
//  Created by 장우진 on 2020/04/02.
//  Copyright © 2020 장우진. All rights reserved.
//
/*
 문제: 최대 1000개의 원자가 2000x2000크기의 맵에서 주어진 방향으로 움직이고, 만나면 폭발한다.
 해설: 맵의 크기가 크다. 게다가 0.5초 단위로 생각을 해줘야 한다. 예를 들면, 3칸 차이나는 두 원자가
	  마주보며 움직이면 1.5초 뒤에 만나 폭발하게 된다. 그렇기에 애초에 칸 수에 2를 곱하여 4000x4000
	  크기의 맵을 생성한다. 어려운 문제이므로 다시 풀어보자.
 */
#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
#include <cmath>
#include <algorithm>
using namespace std;

struct Atom {
	int x, y, d, energy;
	bool alive;
};

// 상하좌우
const int dx[] = {-1, 1, 0, 0};
const int dy[] = {0, 0, -1, 1};
const int MAX = 4001;
int map[MAX][MAX];
int n, ans;
Atom atom[1000];

void move() {
	for (int i = 0; i < n; ++i) {
		if (!atom[i].alive) continue;
		int x = atom[i].x;
		int y = atom[i].y;
		map[x][y] = 0;
		int nx = x + dx[atom[i].d];
		int ny = y + dy[atom[i].d];
		// 맵을 벗어나면 더 이상 만날 수 없다.
		if (nx < 0 || nx >= MAX || ny < 0 || ny >= MAX) {
			atom[i].alive = false;
			continue;
		}
		atom[i].x = nx;
		atom[i].y = ny;
		map[nx][ny] += atom[i].energy; // 다음 위치에 에너지를 더해준다.
	}
	for (int i = 0; i < n; ++i) {
		if (!atom[i].alive) continue;
		int x = atom[i].x;
		int y = atom[i].y;
		// 위에서 더한 에너지와 다르다면 다른 원자도 도착한 것이다.
		if (atom[i].energy != map[x][y]) {
			ans += map[x][y];
			// 서로 만나 폭발했으므로 0으로 초기화해준다.
			// 이 폭발에 연관된 나머지 원자들도 이 if문에 여전히 들어올 수 있다.
			map[x][y] = 0;
			atom[i].alive = false;
		}
	}
}

int main() {
	int T;
	scanf("%d", &T);
	for (int tc = 1; tc <= T; ++tc) {
		scanf("%d", &n);
		for (int i = 0; i < n; ++i) {
			int x, y, d, k;
			scanf("%d %d %d %d", &y, &x, &d, &k);
			x = (-x + 1000) * 2;
			y = (y + 1000) * 2;
			atom[i] = {x, y, d, k, true};
		}
		ans = 0;
		for (int t = 0; t <= 4000; ++t)
			move();
		printf("#%d %d\n", tc, ans);
	}
	return 0;
}
