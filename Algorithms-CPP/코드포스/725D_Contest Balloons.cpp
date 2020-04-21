//
//  725D_Contest Balloons.cpp
//  Algorithms-CPP
//
//  Created by 장우진 on 2020/04/21.
//  Copyright © 2020 장우진. All rights reserved.
//
/*
 문제: 첫번째 팀의 팀원이 다른 팀에게 풍선을 줘서 하늘로 날아오르게 한다. 이를 반복해 최고 등수로 올라가는 문제.
 해설: 먼저 풍선의 개수를 기준으로 내림차 순, 개수가 같다면 개수와 무게와의 차이를 기준으로 오름차 순으로 정렬한다.
	  처음 한번만 하면 된다. 그리고 첫번째 팀보다 풍선이 많으면 우선순위 큐에 넣고 꺼내서 뺀다. 이 과정을 풍선의
	  수가 0보다 작을 때까지 반복한다.
 알고리즘: 정렬, 우선순위 큐
 */
#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

struct Team {
	long long num, weight;
	long long diff;
};
struct Team_cmp {
	bool operator()(const Team& a, const Team& b) {
		return a.diff > b.diff;
	}
};
bool cmp(const Team& a, const Team& b) {
	if (a.num == b.num) return a.diff < b.diff;
	return a.num > b.num;
}

Team team[300000];
int n;

int main() {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	cin >> n;
	for (int i = 0; i < n; ++i) {
		cin >> team[i].num >> team[i].weight;
		team[i].diff = team[i].weight - team[i].num;
	}
	sort(team + 1, team + n, cmp);
	
	priority_queue<Team, vector<Team>, Team_cmp> pq;
	int i = 1;
	for (; i < n; ++i) {
		if (team[i].num > team[0].num)
			pq.push(team[i]);
		else break;
	}
	
	int ans = i, temp = i, j = i;
	while (!pq.empty()) {
		Team t = pq.top();
		pq.pop();
		team[0].num -= t.diff + 1;
		if (team[0].num < 0)
			break;
		--temp;
		for (; j < n; ++j) {
			if (team[j].num > team[0].num) {
				pq.push(team[j]);
				++temp;
			}
			else break;
		}
		ans = min(ans, temp);
	}
	cout << ans << '\n';
	return 0;
}
