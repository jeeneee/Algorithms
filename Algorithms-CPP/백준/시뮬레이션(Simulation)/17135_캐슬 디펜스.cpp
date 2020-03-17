//
//  17135_캐슬 디펜스.cpp
//  Algorithms-CPP
//
//  Created by 장우진 on 2020/03/17.
//  Copyright © 2020 장우진. All rights reserved.
//
/*
 문제: 궁수 세 명을 임의로 배치해 최대의 적을 죽이는 문제. 궁수의 위치는 조합을 이용해야 한다.
	  이 문제의 핵심은 적을 죽이는 것에 있는데, 조건은 다음과 같다.
	  1. 사정 거리 안에 들어오고 가장 가까운 적을 공격한다.
	  2. 가장 가까운 적이 여러 명이라면 가장 왼쪽에 있는 적을 공격한다. (중복 가능)
 해설: 처음엔 우선순위 큐로 해결하려 했지만 동시에 공격해야 해서 구현이 까다로웠다. BFS를 하되, 벡터를
	  이용하였다. n, m이 작기 때문에 하나하나 직접 비교해서 타겟에 넣어준다. 중복이 있을 수 있음에 유의한다.
 알고리즘: DFS + BFS + 시뮬레이션
 */
#include <iostream>
#include <vector>
#include <queue>
#include <cmath>
#include <set>
#include <algorithm>
using namespace std;

#define x first
#define y second

typedef pair<int, int> pii;
typedef pair<int, pii> pipii;
const int MAX = 15;
vector<pii> archer, enemy;
int map[MAX][MAX];
int n, m, d, ans = 0;

inline int dist(pii& a, pii& b) {
	return abs(a.x - b.x) + abs(a.y - b.y);
}

void dfs(int idx, int cnt) {
	if (cnt == 3) {
		int res = 0;
		vector<pii> v = enemy;
		// bfs
		while (!v.empty()) {
			// 적이 없어질 때까지 공격한다.
			vector<int> target; // 죽은 적들의 좌표를 저장
			int enemy_y = v[0].y;
			int idx = 0;
			for (int i = 0; i < archer.size(); ++i) {
				int distance = dist(archer[i], v[0]); // 첫 번째 적과 궁수와의 거리
				for (int j = 1; j < v.size(); ++j) { // 나머지 적과 궁수와의 거리 비교
					int temp_distance = dist(archer[i], v[j]);
					if (temp_distance < distance) { // 작으면 업데이트
						distance = temp_distance;
						enemy_y = v[j].y;
						idx = j; // 몇 번째 적인지 저장한다.
					}
					// 거리가 같고 더 좌측에 있다면 업데이트
					else if (temp_distance == distance && v[j].y < enemy_y) {
						enemy_y = v[j].y;
						idx = j;
					}
				}
				// 사정거리 안에 있다면 타겟에 넣어준다.
				if (distance <= d)
					target.push_back(idx);
			}
			vector<pii> temp_v; // 임시 적
			for (int i = 0; i < v.size(); ++i) {
				bool died = false;
				for (auto& t: target)
					if (t == i) { // 타겟에 있는 적은 죽인다. 즉, v에 넣지 않는다.
						died = true;
						res++;
						break;
					}
				// 한 칸 내렸을 때 궁수에 닿지 않는 적은 넣어준다.
				if (!died && v[i].x < n-1)
					temp_v.push_back( {v[i].x+1, v[i].y} );
			}
			v = temp_v; // 교환
		}
		ans = max(ans, res);
		return;
	}
	// 조합
	for (int j = idx; j < m; ++j) {
		archer.push_back( {n, j} );
		dfs(j+1, cnt+1);
		archer.pop_back();
	}
}

int main() {
	ios::sync_with_stdio(false); cin.tie(0);
	cin >> n >> m >> d;
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			cin >> map[i][j];
			if (map[i][j] == 1)
				enemy.push_back( {i, j} );
		}
	}
	dfs(0, 0);
	cout << ans << endl;
	return 0;
}
