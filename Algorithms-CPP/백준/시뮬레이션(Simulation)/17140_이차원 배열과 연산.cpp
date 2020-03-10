//
//  17140_이차원 배열과 연산.cpp
//  Algorithms-CPP
//
//  Created by 장우진 on 2020/03/10.
//  Copyright © 2020 장우진. All rights reserved.
//
/*
 문제: 한 행 또는 열에 있는 수를 정렬하려면, 각각의 수가 몇 번 나왔는지 알아야 한다.
	  그 다음, 수의 등장 횟수가 커지는 순으로, 그러한 것이 여러가지면 수가 커지는 순으로 정렬한다.
	  그 다음에는 배열 A에 정렬된 결과를 다시 넣어야 한다.
	  정렬된 결과를 배열에 넣을 때는, 수와 등장 횟수를 모두 넣으며, 순서는 수가 먼저이다.
	  예를 들어, [3, 1, 1]에는 3이 1번, 1가 2번 등장한다.
	  따라서, 정렬된 결과는 [3, 1, 1, 2]가 된다. 다시 이 배열에는 3이 1번, 1이 2번, 2가 1번 등장한다.
	  다시 정렬하면 [2, 1, 3, 1, 1, 2]가 된다.
 해설: R연산과 C연산이 나누어져있지만 한 연산만 구현하고 다른 하나는 A행렬을 전치시켜 구한다.
	  정렬할 때에는 등장 횟수의 오름차 순(우선순위1), 해당 수의 오름차 순(우선순위2)으로 정렬한다.
	  (그냥 pair<int, int>로 {등장 횟수, 넘버}를 넣어주고 그대로 정렬시키면 된다.
 알고리즘: 정렬
 O(N^2 * lgN)
 */
#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
using namespace std;

const int MAX = 100 + 1;
int A[MAX][MAX], cnt[MAX]; // A=2차원 배열, cnt=등장 횟수
vector<pair<int, int>> v[MAX]; // {등장 횟수, 넘버}
int R, C;

void Cal() {
	for (int i = 1; i <= R; ++i) {
		int maxNum = 0; // 끝까지 확인할 필요 없도록 최대 수를 저장한다
		for (int j = 1; j <= C; ++j) {
			if (A[i][j] == 0) continue;	// 0 무시
			cnt[A[i][j]]++;
			maxNum = max(maxNum, A[i][j]);
			A[i][j] = 0; // 0 초기화
		}
		for (int num = 1; num <= maxNum; ++num)
			if (cnt[num]) {
				v[i].push_back( {cnt[num], num} );
				cnt[num] = 0; // 0 초기화
			}
	}
	C = 0;
	for (int i = 1; i <= R; ++i) {
		sort(v[i].begin(), v[i].end()); // 정렬
		int j = 0; // 열(1부터)
		for (auto& a : v[i]) {
			A[i][++j] = a.second;
			A[i][++j] = a.first;
		}
		v[i].clear(); // 벡터 초기화
		C = max(C, j); // 최대 열 계산
	}
}

// 전치 행렬
void transpose() {
	int temp[MAX][MAX];
	memset(temp, 0, sizeof(temp));
	for (int i = 1; i <= C; ++i)
		for (int j = 1; j <= R; ++j)
			temp[i][j] = A[j][i];
	memcpy(A, temp, sizeof(temp));
}

int main() {
	int r, c, k;
	cin >> r >> c >> k;
	for (int i = 1; i <= 3; ++i) {
		for (int j = 1; j <= 3; ++j) {
			cin >> A[i][j];
		}
	}
	
	R = 3; C = 3;
	int time = 0;
	while (1) {
		// 기저 사례
		if (A[r][c] == k) {
			cout << time << '\n';
			return 0;
		} else if (time > 100) {
			cout << -1 << '\n';
			return 0;
		}
		// 연산
		if (R < C) {
			transpose();
			swap(R, C);
			Cal();
			transpose();
			swap(R, C);
		}
		else
			Cal();
		time++;
	}
	return 0;
}
