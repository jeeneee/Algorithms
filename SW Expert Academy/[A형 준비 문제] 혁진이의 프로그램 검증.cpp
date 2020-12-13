//
//  [A형 준비 문제] 혁진이의 프로그램 검증.cpp
//  Algorithms-CPP
//
//  Created by 장우진 on 2020/04/09.
//  Copyright © 2020 장우진. All rights reserved.
//
/*
 문제: 에디터 문제와 유사하다. 무한 재귀에 빠지는지 확인하는 문제. 조건에 맞게 설계하면 된다.
 */
#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

// 좌우상하
const int dx[] = {0, 0, -1, 1};
const int dy[] = {-1, 1, 0, 0};
char map[20][21];
bool visited[20][21][4][16];
int r, c;

bool go(int x, int y, int d, int m) {
	char op = map[x][y];
	if (op == '@') return true;
	else if (op == '<' || (op == '_' && m != 0)) d = 0;
	else if (op == '>' || op == '_') d = 1;
	else if (op == '^' || (op == '|' && m != 0)) d = 2;
	else if (op == 'v' || op == '|') d = 3;
	else if ('0' <= op && op <= '9') m = op - '0';
	else if (op == '+') m = (m + 1) % 16;
	else if (op == '-') m = (m + 15) % 16;
	
	if (visited[x][y][d][m]) return false;
	visited[x][y][d][m] = true;
	
	if (op == '?') {
		bool ret = false;
		for (int i = 0; i < 4; ++i) {
			int nx = (x + dx[i] + r) % r;
			int ny = (y + dy[i] + c) % c;
			ret = max(ret, go(nx, ny, i, m));
		}
		return ret;
	} else {
		int nx = (x + dx[d] + r) % r;
		int ny = (y + dy[d] + c) % c;
		return go(nx, ny, d, m);
	}
}

int main() {
	int T;
	scanf("%d", &T);
	for (int tc = 1; tc <= T; ++tc) {
		memset(visited, false, sizeof(visited));
		scanf("%d %d", &r, &c);
		for (int i = 0; i < r; ++i)
			scanf("%s", map[i]);
		printf("#%d %s\n", tc, go(0, 0, 1, 0) ? "YES" : "NO");
	}
	return 0;
}
