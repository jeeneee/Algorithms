//
//  2383_[모의 SW 역량테스트] 점심 식사시간.cpp
//  Algorithms-CPP
//
//  Created by 장우진 on 2020/03/30.
//  Copyright © 2020 장우진. All rights reserved.
//
/*
 문제: 10명 이하의 사원이 계단을 통해 내려가려 한다. 계단은 두 개가 있으며 소요 시간이 다를 수 있다.
	  각 계단은 최대 3명이 이용할 수 있고, 계단에 도착한 뒤 1초 후에 아래로 내려간다.
 해설: 완전 탐색 문제이다. 두 계단이 있으므로 중복 순열을 통해 사람마다 이용할 계단을 지정한 뒤, 매 초마다
	  일어날 상황을 조건에 맞춰 계산한다.
 알고리즘: 백트래킹 + 정렬
 */
#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;

struct Person {
	int x, y;
	int t1, t2;
};
struct Stair {
	int x, y;
	int t;
};

vector<Person> person;
vector<Stair> stair;
int toWhere[10];
int n, ans;

int down(vector<int>& v, int numStair) {
	if (v.empty()) return 0;
	
	sort(v.begin(), v.end());
	int used[3] = {0, };
	int time = v[0];
	while (1) {
		for (int i = 0; i < v.size(); ++i) {
			if (v[i] == -1) continue;
			else if (v[i] > time) break;
			for (int j = 0; j < 3; ++j) {
				if (used[j] <= 0) {
					if (i == v.size() - 1)
						return time + stair[numStair].t + 1;
					used[j] = stair[numStair].t;
					v[i] = -1;
					break;
				}
			}
		}
		for (int i = 0; i < 3; ++i)
			used[i]--;
		time++;
	}
}

void dfs(int idx) {
	if (idx == person.size()) {
		vector<int> v1, v2;
		for (int i = 0; i < person.size(); ++i) {
			if (toWhere[i] == 1) v1.push_back(person[i].t1);
			else v2.push_back(person[i].t2);
		}
		ans = min(ans, max(down(v1, 0), down(v2, 1)));
		return;
	}
	toWhere[idx] = 1;
	dfs(idx+1);
	toWhere[idx] = 2;
	dfs(idx+1);
}

int main() {
	int T;
	scanf("%d", &T);
	for (int tc = 1; tc <= T; ++tc) {
		person.clear();
		stair.clear();
		scanf("%d", &n);
		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < n; ++j) {
				int x; scanf("%d", &x);
				if (x == 1) person.push_back( {i, j, 0, 0} );
				else if (x > 1) stair.push_back( {i, j, x} );
			}
		}
		for (auto& p : person) {
			p.t1 = abs(p.x - stair[0].x) + abs(p.y - stair[0].y);
			p.t2 = abs(p.x - stair[1].x) + abs(p.y - stair[1].y);
		}
		ans = 987654321;
		dfs(0);
		printf("#%d %d\n", tc, ans);
	}
	return 0;
}
