//
//  17143_낚시왕.cpp
//  Algorithms-CPP
//
//  Created by 장우진 on 2020/03/10.
//  Copyright © 2020 장우진. All rights reserved.
//
/*
 문제: 낚시왕은 처음에 1번 열의 한 칸 왼쪽에 있다. 다음은 1초 동안 일어나는 일이며, 아래 적힌 순서대로 일어난다.
	  낚시왕은 가장 오른쪽 열의 오른쪽 칸에 이동하면 이동을 멈춘다.
		1. 낚시왕이 오른쪽으로 한 칸 이동한다.
		2. 낚시왕이 있는 열에 있는 상어 중에서 땅과 제일 가까운 상어를 잡는다. 상어를 잡으면 격자판에서 잡은 상어가 사라진다.
		3. 상어가 이동한다.
	  상어는 입력으로 주어진 속도로 이동하고, 속도의 단위는 칸/초이다.
	  상어가 이동하려고 하는 칸이 격자판의 경계인 경우에는 방향을 반대로 바꿔서 속력을 유지한채로 이동한다.
	  상어가 이동을 마친 후에 한 칸에 상어가 두 마리 이상 있을 수 있다. 이때는 크기가 가장 큰 상어가 나머지 상어를 모두 잡아먹는다.
	  낚시왕이 상어 낚시를 하는 격자판의 상태가 주어졌을 때, 낚시왕이 잡은 상어 크기의 합을 구해보자.
 해설: 어떤 자료구조를 써야할지 잘 생각해야 한다. 이동 후에 한 위치에 여러 마리의 상어가 올 수 있지만
	  그 중 가장 큰 상어만 남겨놓을 것이므로 단순히 2차원 배열만 써도 된다. 처음엔 벡터를 썼지만 수정하였다. 시간 차이는 없다.
	  조건만 잘 이행하면 되는 문제.
 */
#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
#include <algorithm>
using namespace std;

struct Pos {
	int x, y;
};

struct Shark {
	int v, d, z;
};

// 위, 아래, 오른쪽, 왼쪽
const int dx[] = {-1, 1, 0, 0};
const int dy[] = {0, 0, 1, -1};
const int MAX = 100 + 1;
int R, C, M;
Shark shark[MAX][MAX];

int main() {
	ios::sync_with_stdio(false); cin.tie(0);
	cin >> R >> C >> M;
	for (int i = 0; i < M; ++i) {
		int x, y, v, d, z;
		cin >> x >> y >> v >> d >> z;
		shark[x][y] = {v, d-1, z};
	}
	
	int ans = 0;
	// cur = 낚시왕의 위치, 1. 낚시왕이 오른쪽으로 한 칸 이동한다.
	for (int cur = 1; cur <= C; ++cur) {
		// 2. 낚시왕이 있는 열에 있는 상어 중에서 땅과 제일 가까운 상어를 잡는다. 상어를 잡으면 격자판에서 잡은 상어가 사라진다.
		for (int i = 1; i <= R; ++i)
			if (shark[i][cur].z > 0) {
				ans += shark[i][cur].z;
				shark[i][cur] = {0, 0, 0};
				break;
			}
		// 살아있는 상어를 모두 큐에 넣는다.
		queue<pair<Pos, Shark>> q;
		for (int i = 1; i <= R; ++i)
			for (int j = 1; j <= C; ++j)
				if (shark[i][j].z > 0) {
					q.push( {{i, j}, shark[i][j]} );
					shark[i][j] = {0, 0, 0};
				}
		// 3. 상어가 이동한다.
		while (!q.empty()) {
			int x = q.front().first.x;
			int y = q.front().first.y;
			int v = q.front().second.v;
			int d = q.front().second.d;
			int z = q.front().second.z;
			q.pop();
			int temp = v;
			// 위, 아래
			if (d < 2) {
				temp %= (R - 1) * 2; // 한바퀴 돌아 제자리에 오는 경우
				for (int i = 0; i < temp; ++i) {
					int nx = x + dx[d];
					if (!(1 <= nx && nx <= R))
						d = 1 - d;
					x += dx[d];
				}
			}
			// 오른쪽, 왼쪽
			else {
				temp %= (C - 1) * 2;
				for (int i = 0; i < temp; ++i) {
					int ny = y + dy[d];
					if (!(1 <= ny && ny <= C))
						d = 5 - d;
					y += dy[d];
				}
			}
			// 이동한 위치에 있는 상어의 크기가 더 작으면 대체한다.
			if (shark[x][y].z < z)
				shark[x][y] = {v, d, z};
		}
	}
	cout << ans << '\n';
	return 0;
}
