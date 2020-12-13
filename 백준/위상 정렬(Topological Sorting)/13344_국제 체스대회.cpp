//
//  13344_국제 체스대회.cpp
//  Algorithms-CPP
//
//  Created by 장우진 on 2020/02/11.
//  Copyright © 2020 장우진. All rights reserved.
//
/*
 ------------
 예제 입력 2
 5 5
 0 = 1
 1 = 2
 3 = 4
 0 > 3
 1 > 4
 ------------
 위와 같은 입력을 받는다면, 0,1,2와 3,4를 disjoint set으로 결합한 후 위상 정렬을 실행한다.
 여기서 edge[0]={3} edge[1]={4}였지만 edge2[0]={3, 3}으로 바뀌게 되는데 중복 원소를
 그대로 넣어도 무방하다. 어차피 in[0] = 2가 되기 때문이다.
 */
#include <iostream>
#include <vector>
#include <cstring>
#include <queue>
#include <set>
#include <algorithm>
using namespace std;

const int MAX = 50000;
int in[MAX];
vector<int> v;

int find(int x) {
	if (x == v[x])
		return x;
	return v[x] = find(v[x]);
}

void merge(int a, int b) {
	if (a > b) swap(a, b);
	a = find(a); b = find(b);
	if (a == b) return;
	v[b] = a;
}

int main() {
	int N, M, K, L;
	char S;
	scanf("%d %d", &N, &M);
	
	vector<vector<int>> edge(N);
	v.resize(N);
	for (int i = 0; i < N; ++i)
		v[i] = i;
	
	while (M--) {
		scanf("%d %c %d", &K, &S, &L);
		if (S == '>')
			edge[K].push_back(L); // K가 L을 이긴다.
		else
			merge(K, L); // K와 L의 실력이 동등.
	}
	
	vector<vector<int>> edge2(N);
	vector<int> in(N, 0);
	for (int i = 0; i < N; ++i) {
		int win = find(i);
		for (auto& lose : edge[i]) {
			lose = find(lose);
			if (win == lose) {
				printf("inconsistent\n");
				return 0;
			}
			// 이 부분은 중복 원소를 제거하기 위한 코드(속도가 4배로 느려진다.)
//			bool flag = true;
//			for (auto& a : edge2[win])
//				if (a == lose) {
//					flag = false;
//					break;
//				}
//			if (flag) {
				edge2[win].push_back(lose);
				in[lose]++;
//			}
		}
	}
	
	queue<int> q;
	for (int i = 0; i < N; ++i) {
		if (!in[i])
			q.push(i);
	}
	
	vector<int> order;
	while (!q.empty()) {
		int x = q.front();
		q.pop();
		order.push_back(x);
		
		for (auto& next : edge2[x]) {
			if (--in[next] == 0)
				q.push(next);
		}
	}
	
	if (order.size() == N)
		printf("consistent\n");
	else
		printf("inconsistent\n");
	
	return 0;
}
