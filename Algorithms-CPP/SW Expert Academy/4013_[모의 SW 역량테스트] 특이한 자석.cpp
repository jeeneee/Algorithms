//
//  4013_[모의 SW 역량테스트] 특이한 자석.cpp
//  Algorithms-CPP
//
//  Created by 장우진 on 2020/04/02.
//  Copyright © 2020 장우진. All rights reserved.
//
/*
 문제: 8개의 자석톱니로 이루어진 4개의 톱니바퀴를 규칙에 맞게 회전시키는 문제.
 */
#include <iostream>
#include <deque>
using namespace std;

deque<int> cog[4];
int direction[4];

void toRight(int num, int dir) {
	for (int i = num + 1; i < 4; ++i) {
		if (cog[i-1][2] == cog[i][6])
			return;
		else {
			dir = dir * -1;
			direction[i] = dir;
		}
	}
}

void toLeft(int num, int dir) {
	for (int i = num-1; i >= 0; --i) {
		if (cog[i+1][6] == cog[i][2])
			return;
		else {
			dir = dir * -1;
			direction[i] = dir;
		}
	}
}

void rot(int num, int dir) {
	if (dir == -1) {       // 반시계 방향
		int x = cog[num].front();
		cog[num].pop_front();
		cog[num].push_back(x);
	} else if (dir == 1) { // 시계 방향
		int x = cog[num].back();
		cog[num].pop_back();
		cog[num].push_front(x);
	}
}

int main() {
	int T;
	scanf("%d", &T);
	for (int tc = 1; tc <= T; ++tc) {
		int k;
		scanf("%d", &k);
		for (int i = 0; i < 4; ++i) {
			cog[i].clear();
			for (int j = 0, x; j < 8; ++j) {
				scanf("%d", &x);
				cog[i].push_back(x);
			}
		}
		int num, dir;
		while (k--) {
			for (int i = 0; i < 4; ++i)
				direction[i] = 0;
			scanf("%d %d", &num, &dir);
			num--;
			direction[num] = dir;
			toLeft(num, dir);
			toRight(num, dir);
			for (int i = 0; i < 4; ++i)
				rot(i, direction[i]);
		}
		int ans = 0;
		for (int i = 0; i < 4; ++i)
			ans += cog[i][0] * (1 << i);
		printf("#%d %d\n", tc, ans);
	}
	return 0;
}
