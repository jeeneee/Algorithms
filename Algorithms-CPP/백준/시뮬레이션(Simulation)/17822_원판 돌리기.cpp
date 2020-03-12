//
//  17822_원판 돌리기.cpp
//  Algorithms-CPP
//
//  Created by 장우진 on 2020/03/12.
//  Copyright © 2020 장우진. All rights reserved.
//
/*
 문제: 여러 원판을 회전시키고 인접한 수를 없앤다. 인접한 수가 없는 경우에는 평균을 구해 각 수를 조작한다.
 해설: 원판을 회전시키는 데는 데크를 이용하였고, 인접한 수는 큐를 이용하여 찾았다. 평균을 나눌 때 0을
	  나눌 수 있음에 유의하자. 또한 인접한 수에서 각 끝(즉, 인덱스가 0과 m-1일 경우)에 도달하면
	  반대편으로 이동시켜준다. 물론 데크가 아닌 배열을 큐가 아닌 for문을 이용할 수 있다. 이 경우,
	  0으로 업데이트를 바로 하지않고 동시에 해줘야 한다.
 알고리즘: BFS + 자료구조(Deque)
 */
#include <iostream>
#include <vector>
#include <deque>
#include <queue>
#include <cstring>
#include <algorithm>
using namespace std;

const int dx[] = {-1, 1, 0, 0};
const int dy[] = {0, 0, -1, 1};
const int MAX = 50 + 1;
deque<int> dq[MAX];
bool visited[MAX][MAX];
int n, m, t;

void Rotate(int x, int d, int k) {
	for (int i = x; i <= n; i += x) {
		for (int j = 0; j < k; ++j) {
			if (d == 0) {
				dq[i].push_front(dq[i].back());
				dq[i].pop_back();
			} else {
				dq[i].push_back(dq[i].front());
				dq[i].pop_front();
			}
		}
	}
}

void Transform() {
	bool noAdj = true;
	memset(visited, false, sizeof(visited));
	for (int i = 1; i <= n; ++i) {
		for (int j = 0; j < m; ++j) {
			if (dq[i][j] != 0 && !visited[i][j]) {
				queue<pair<int, int>> q;
				q.push( {i, j} );
				bool hasSame = false;
				int value = dq[i][j];
				while (!q.empty()) {
					int x = q.front().first;
					int y = q.front().second;
					q.pop();
					for (int i = 0; i < 4; ++i) {
						int nx = x + dx[i];
						int ny = y + dy[i];
						if ((1 <= nx && nx <= n) && (-1 <= ny && ny <= m)) {
							if (ny == -1)
								ny = m-1;
							else if (ny == m)
								ny = 0;
							if (visited[nx][ny] || dq[nx][ny] != value)
								continue;
							hasSame = true;
							dq[nx][ny] = 0;
							visited[nx][ny] = true;
							q.push( {nx, ny} );
						}
					}
				}
				if (hasSame) {
					noAdj = false;
					dq[i][j] = 0;
				}
			}
		}
	}
	if (noAdj) {
		double average = 0;
		int num = 0;
		for (int i = 1; i <= n; ++i)
			for (int j = 0; j < m; ++j) {
				average += dq[i][j];
				if (dq[i][j] != 0) num++;
			}
		if (num == 0) return;
		average /= num;
		for (int i = 1; i <= n; ++i) {
			for (int j = 0; j < m; ++j) {
				if (dq[i][j] == 0) continue;
				if ((double)dq[i][j] > average)
					dq[i][j]--;
				else if ((double)dq[i][j] < average)
					dq[i][j]++;
			}
		}
	}
}

int main() {
	ios::sync_with_stdio(false); cin.tie(0);
	cin >> n >> m >> t;
	for (int i = 1; i <= n; ++i) {
		dq[i].resize(m);
		for (int j = 0; j < m; ++j) {
			int x;
			cin >> x;
			dq[i][j] = x;
		}
	}
	while (t--) {
		int x, d, k;
		cin >> x >> d >> k;
		Rotate(x, d, k);
		Transform();
	}
	int ans = 0;
	for (int i = 1; i <= n; ++i)
		for (int j = 0; j < m; ++j)
			ans += dq[i][j];
	cout << ans << '\n';
	return 0;
}
