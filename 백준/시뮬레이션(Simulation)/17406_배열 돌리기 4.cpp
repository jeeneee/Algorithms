//
//  17406_배열 돌리기 4.cpp
//  Algorithms-CPP
//
//  Created by 장우진 on 2020/03/18.
//  Copyright © 2020 장우진. All rights reserved.
//
/*
 문제: 배열을 돌리는데 돌리는 순서가 다를 수 있다. 백트래킹 문제.
 알고리즘: 백트래킹 DFS 배열 회전
 */
#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
using namespace std;

const int INF = 987654321;
const int MAX = 51;
int A[MAX][MAX], c_A[MAX][MAX];
int R[6], C[6], S[6];
bool visited[6];
vector<int> cand;
int N, M, K, ans = INF;

int calc() {
	int ret = INF;
	for (int i = 1; i <= N; ++i) {
		int sum = 0;
		for (int j = 1; j <= M; ++j)
			sum += A[i][j];
		ret = min(ret, sum);
	}
	return ret;
}

void rot(int r, int c, int s) {
	while (s) {
		int temp = A[r-s][c-s];
		// 왼쪽
		for (int i = r-s; i < r+s; ++i)
			A[i][c-s] = A[i+1][c-s];
		// 아래
		for (int j = c-s; j < c+s; ++j)
			A[r+s][j] = A[r+s][j+1];
		// 오른쪽
		for (int i = r+s; i > r-s; --i)
			A[i][c+s] = A[i-1][c+s];
		// 위
		for (int j = c+s; j > c-s; --j)
			A[r-s][j] = A[r-s][j-1];
		A[r-s][c-s+1] = temp;
		s--;
	}
}

void dfs(int cnt) {
	if (cnt == K) {
		memcpy(c_A, A, sizeof(A));
		for (auto& i: cand)
			rot(R[i], C[i], S[i]);
		ans = min(ans, calc());
		memcpy(A, c_A, sizeof(A));
		return;
	}
	for (int i = 0; i < K; ++i) {
		if (visited[i]) continue;
		visited[i] = true;
		cand.push_back(i);
		dfs(cnt+1);
		cand.pop_back();
		visited[i] = false;
	}
}

int main() {
	ios::sync_with_stdio(false); cin.tie(0);
	cin >> N >> M >> K;
	for (int i = 1; i <= N; ++i)
		for (int j = 1; j <= M; ++j)
			cin >> A[i][j];
	for (int i = 0; i < K; ++i)
		cin >> R[i] >> C[i] >> S[i];
	dfs(0);
	rot(3, 4, 2);
	cout << ans << '\n';
	return 0;
}
