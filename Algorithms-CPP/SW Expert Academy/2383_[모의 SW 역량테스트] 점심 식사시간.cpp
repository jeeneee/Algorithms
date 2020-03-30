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
#include <algorithm>
using namespace std;

struct Person {
	int x, y, d1, d2;
};
struct Stair {
	int x, y, t;
};
bool cmp1(const Person& a, const Person& b) {
	return a.d1 < b.d1;
}
bool cmp2(const Person& a, const Person& b) {
	return a.d2 < b.d2;
}
vector<Person> person;
vector<Stair> stair;
int toWhere[10];
int ans;

int getTime1(vector<Person>& v) {
	if (v.empty()) return 0;
	
	sort(v.begin(), v.end(), cmp1);
	int used[3] = {0, };
	int time = v[0].d1;
	
	while (1) {
		for (int i = 0; i < v.size(); ++i) {
			if (v[i].d1 == 0 || v[i].d1 > time) continue;
			for (int j = 0; j < 3; ++j) {
				if (used[j] <= 0) {
					used[j] = stair[0].t;
					v[i].d1 = 0;
					if (i == v.size() - 1)
						return time + stair[0].t + 1;
					break;
				}
			}
		}
		for (int i = 0; i < 3; ++i)
			used[i]--;
		time++;
	}
}

int getTime2(vector<Person>& v) {
	if (v.empty()) return 0;
	
	sort(v.begin(), v.end(), cmp2);
	int used[3] = {0, };
	int time = v[0].d2;
	
	while (1) {
		for (int i = 0; i < v.size(); ++i) {
			if (v[i].d2 == 0 || v[i].d2 > time) continue;
			for (int j = 0; j < 3; ++j) {
				if (used[j] <= 0) {
					used[j] = stair[1].t;
					v[i].d2 = 0;
					if (i == v.size() - 1)
						return time + stair[1].t + 1;
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
		vector<Person> v1, v2;
		for (int i = 0; i < person.size(); ++i) {
			if (toWhere[i] == 1) v1.push_back(person[i]);
			else if (toWhere[i] == 2) v2.push_back(person[i]);
		}
		ans = min(ans, max(getTime1(v1), getTime2(v2)));
		return;
	}
	toWhere[idx] = 1;
	dfs(idx+1);
	toWhere[idx] = 2;
	dfs(idx+1);
}

int main() {
	int T;
	cin >> T;
	for (int tc = 1; tc <= T; ++tc) {
		person.clear();
		stair.clear();
		int n;
		cin >> n;
		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < n; ++j) {
				int x; cin >> x;
				if (x == 1)
					person.push_back( {i, j, 0, 0} );
				else if (x > 1)
					stair.push_back( {i, j, x} );
			}
		}
		for (int i = 0; i < person.size(); ++i) {
			person[i].d1 = abs(stair[0].x - person[i].x) +
						abs(stair[0].y - person[i].y);
			person[i].d2 = abs(stair[1].x - person[i].x) +
						abs(stair[1].y - person[i].y);
		}
		ans = 987654321;
		dfs(0);
		cout << "#" << tc << " " << ans << "\n";
	}
	return 0;
}
