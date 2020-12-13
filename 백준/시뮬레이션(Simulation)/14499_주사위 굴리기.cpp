//
//  14499_주사위 굴리기.cpp
//  Algorithms-CPP
//
//  Created by 장우진 on 2020/03/06.
//  Copyright © 2020 장우진. All rights reserved.
//

/*
 문제: 주사위를 굴렸을 때, 이동한 칸에 쓰여 있는 수가 0이면, 주사위의 바닥면에 쓰여 있는 수가 칸에 복사된다.
	  0이 아닌 경우에는 칸에 쓰여 있는 수가 주사위의 바닥면으로 복사되며, 칸에 쓰여 있는 수는 0이 된다.
	  주사위를 굴릴 때마다의 상태를 저장하는 것이 중요하다.
 */
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

const int MAX = 20;
const int dx[] = {0, 0, -1, 1};
const int dy[] = {1, -1, 0, 0};
int map[MAX][MAX];
int dice[6];

void move(int x, int y, int d) {
	switch (d) {
		case 0:
			swap(dice[2], dice[3]);
			swap(dice[0], dice[3]);
			swap(dice[2], dice[5]);
			break;
		case 1:
			swap(dice[0], dice[2]);
			swap(dice[0], dice[5]);
			swap(dice[0], dice[3]);
			break;
		case 2:
			swap(dice[0], dice[1]);
			swap(dice[1], dice[4]);
			swap(dice[1], dice[5]);
			break;
		case 3:
			swap(dice[0], dice[1]);
			swap(dice[0], dice[4]);
			swap(dice[4], dice[5]);
			break;
	}
	if (!map[x][y])
		map[x][y] = dice[0];
	else {
		dice[0] = map[x][y];
		map[x][y] = 0;
	}
	cout << dice[5] << '\n';
}

int main() {
	int n, m, x, y, k;
	cin >> n >> m >> x >> y >> k;
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < m; ++j)
			cin >> map[i][j];
	while (k--) {
		int d;
		cin >> d;
		d -= 1;
		int nx = x + dx[d];
		int ny = y + dy[d];
		if ((0 <= nx && nx < n) && (0 <= ny && ny < m)) {
			move(nx, ny, d);
			x = nx; y = ny;
		}
	}
	return 0;
}
