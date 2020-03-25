//
//  2382_[모의 SW 역량테스트] 미생물 격리.cpp
//  Algorithms-CPP
//
//  Created by 장우진 on 2020/03/25.
//  Copyright © 2020 장우진. All rights reserved.
//
/*
 문제: 미생물이 가중치와 방향을 갖고 움직이는데 한 곳에서 만나면 합쳐지고 경계에 부딪히면 가중치가 감소한다.
 해설: 한 곳에서 만나는 미생물이 여러 마리일 수도 있으므로 한 번에 업데이트 해줘야 한다. 가중치가 가장 큰
	  녀석을 기준으로 합쳐지므로 우선순위 큐를 이용했고 나머지를 합치기 위해 가중치와 방향은 배열로 따로
	  관리했다. 두 개의 배열이 키포인트인 것 같다.
 */
#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
#include <algorithm>
using namespace std;

struct bug {
	int x, y, s, d;
	bug(int _x, int _y, int _s, int _d)
	: x(_x), y(_y), s(_s), d(_d){}
};
bool operator<(const bug& a, const bug& b) {
	return a.s < b.s;
}
// 상하좌우
const int MAX = 100;
const int dx[] = {-1, 1, 0, 0};
const int dy[] = {0, 0, -1, 1};
int num[MAX][MAX];
int dir[MAX][MAX];
int n, m, k;

bug move(bug a) {
	a.x += dx[a.d];
	a.y += dy[a.d];
	if (a.x == 0 || a.x == n-1 || a.y == 0 || a.y == n-1) {
		a.s >>= 1;
		a.d = (5 - a.d) % 4;
	}
	return a;
}

void solve() {
	priority_queue<bug> pq;
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < n; ++j)
			if (num[i][j] != 0) {
				bug t = move(bug(i, j, num[i][j], dir[i][j]));
				pq.push(t);
				num[i][j] = 0;
				dir[i][j] = -1;
			}
	while (!pq.empty()) {
		bug a = pq.top();
		pq.pop();
		if (num[a.x][a.y] == 0) {
			num[a.x][a.y] = a.s;
			dir[a.x][a.y] = a.d;
		} else {
			num[a.x][a.y] += a.s;
		}
	}
}

int main() {
	ios::sync_with_stdio(false); cin.tie(0);
	int T;
	cin >> T;
	for (int tc = 1; tc <= T; ++tc) {
		memset(num, 0, sizeof(num));
		memset(dir, -1, sizeof(dir));
		cin >> n >> m >> k;
		for (int i = 0; i < k; ++i) {
			int x, y, s, d;
			cin >> x >> y >> s >> d;
			num[x][y] = s;
			dir[x][y] = d-1;
		}
		for (int i = 0; i < m; ++i)
			solve();
		int ans = 0;
		for (int i = 0; i < n; ++i)
			for (int j = 0; j < n; ++j)
				ans += num[i][j];
		cout << "#" << tc << " " << ans << '\n';
	}
	return 0;
}
