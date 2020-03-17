//
//  17136_색종이 붙이기.cpp
//  Algorithms-CPP
//
//  Created by 장우진 on 2020/03/17.
//  Copyright © 2020 장우진. All rights reserved.
//
/*
 문제: 1x1...5x5 크기의 색종이를 최대한 적게 사용해 10x10 크기의 종이 위에 붙이는 문제이다.
 해설: 모든 경우의 수를 시도해야 하기 때문에 백트래킹을 사용했다. 중요한 점은 map의 범위를 넘어가면 안되고
	  색종이를 붙이고 뗄 때 cover함수로 조정한다. 어렵지 않은 문제이나 범위를 넘어가는 바람에 오래 걸렸다.
 알고리즘: 백트래킹 DFS
 */
#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
using namespace std;

const int N = 10;
int map[N][N];
int c_map[N][N];
int cnt[6] = {0, 5, 5, 5, 5, 5};
int ans = 987654321;

bool isPossible(int x, int y, int size) {
	for (int i = x; i < x+size; ++i) {
		for (int j = y; j < y+size; ++j) {
			if (!map[i][j])
				return false;
		}
	}
	return true;
}

void cover(int x, int y, int size, int val) {
	for (int i = x; i < x+size; ++i)
		for (int j = y; j < y+size; ++j)
			map[i][j] = val;
}

void dfs(int num) {
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < N; ++j) {
			if (map[i][j]) {
				bool flag = false; // 커버할 색종이가 있는지에 대한 여부
				for (int k = 1; k <= 5; ++k) {
					// 중요! 범위를 초과하면 색종이 크기를 더 늘릴 필요가 없다.
					if (i + k > N || j + k > N) break;
					if (cnt[k] && isPossible(i, j, k)) {
						flag = true;
						cnt[k]--; // 색종이 사용
						cover(i, j, k, 0); // 색종이로 덮는다.(0)
						dfs(num+1);
						cover(i, j, k, 1); // 색종이를 치운다.(1)
						cnt[k]++; // 색종이 복구
						flag = false;
					}
				}
				if (!flag) return; // 커버할 색종이가 없으므로 더 이상 나아가면 안된다.
			}
		}
	}
	// 모두 0이 된다면 최소값을 갱신
	ans = min(ans, num);
	return;
}

int main() {
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < N; ++j) {
			cin >> map[i][j];
		}
	}
	dfs(0);
	if (ans == 987654321) ans = -1;
	cout << ans << '\n';
	return 0;
}
