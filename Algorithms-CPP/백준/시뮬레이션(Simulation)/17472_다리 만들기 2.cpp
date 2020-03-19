//
//  17472_다리 만들기 2.cpp
//  Algorithms-CPP
//
//  Created by 장우진 on 2020/03/19.
//  Copyright © 2020 장우진. All rights reserved.
//
/*
 문제: 최소 길이의 다리를 이용해 모든 섬을 연결시키는 문제.
 해설: 크게 네 과정으로 나눌 수 있다.
 1. 섬에 번호를 부여함과 동시에 바다와 인접한 좌표를 구한다. (DFS)
 2. 한 섬에서 다른 하나의 섬으로 갈 수 있는 모든 경우의 수를 구한다.
 3. 모든 섬이 연결되었는지 확인한다. (DFS)
 4. 2에서 구한 데이터를 이용해 최단 거리를 구한다. (크루스칼 알고리즘)
 알고리즘: DFS + 크루스칼
 */
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

const int dx[] = {-1, 1, 0, 0};
const int dy[] = {0, 0, -1, 1};
const int INF = 987654321;
const int MAX = 10;

int map[MAX][MAX];
bool visited[MAX][MAX]; // makeIndex
bool visited2[7][7]; // makeRoute
bool visited3[7]; // dfs
int parent[7];
vector<int> graph[7]; // 다른 섬으로 갈 수 있는 루트 저장
vector<pair<int, int>> v[7]; // 바다에 인접한 좌표 저장
vector<pair<int, pair<int, int>>> edge; // {최단거리, {섬, 섬}}
int n, m, land;


void makeIndex(int x, int y, int land) {
	visited[x][y] = true;
	map[x][y] = land;
	bool flag = false;
	for (int i = 0; i < 4; ++i) {
		int nx = x + dx[i];
		int ny = y + dy[i];
		if ((0 <= nx && nx < n) && (0 <= ny && ny < m)) {
			if (map[nx][ny] == 0) flag = true;
			if (!visited[nx][ny] && map[nx][ny] == -1)
				makeIndex(nx, ny, land);
		}
	}
	// 주위에 바다가 있으면 좌표 저장
	if (flag) v[land].push_back( {x, y} );
}

void makeRoute() {
	for (int from = 1; from <= land; ++from) {
		for (int to = 1; to <= land; ++to) {
			visited2[from][to] = true;
			if (visited2[to][from]) continue; // 반대의 경우거나 같은 번호 무시
			int min_d = INF;
			// a=from섬의 한 점, b=to섬의 한 점
			for (auto& a : v[from]) {
				for (auto& b : v[to]) {
					// 가로로 다리를 놓을 경우
					int s = min(a.second, b.second); // 시작점
					int e = max(a.second, b.second); // 끝점
					int d = e - s - 1; // 길이
					if (a.first == b.first && d >= 2) {
						bool flag = true;
						for (int t = s + 1; t < e; ++t)
							if (map[a.first][t]) { // 장애물이 있는 경우
								flag = false;
								break;
							}
						if (flag) min_d = min(min_d, d);
					}
					// 세로로 다리를 놓을 경우
					s = min(a.first, b.first);
					e = max(a.first, b.first);
					d = e - s - 1;
					if (a.second == b.second && d >= 2) {
						bool flag = true;
						for (int t = s + 1; t < e; ++t)
							if (map[t][a.second]) {
								flag = false;
								break;
							}
						if (flag) min_d = min(min_d, d);
					}
				}
			}
			// 간선 저장
			if (min_d != INF) {
				edge.push_back( {min_d, {from, to}} );
				graph[from].push_back(to);
				graph[to].push_back(from);
			}
		}
	}
}

void dfs(int x) {
	visited3[x] = true;
	for (auto& a: graph[x])
		if (!visited3[a]) dfs(a);
}

int getParent(int u) {
	if (u == parent[u]) return u;
	return parent[u] = getParent(parent[u]);
}

void unionParent(int u, int v) {
	u = getParent(u); v = getParent(v);
	if (u < v) swap(u, v);
	parent[u] = v;
}

int main() {
	ios::sync_with_stdio(false); cin.tie(0);
	cin >> n >> m;
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			cin >> map[i][j];
			map[i][j] = (map[i][j] == 1 ? -1 : 0); // 땅은 -1로 설정한다.
		}
	}
	// 섬에 인덱스를 부여한다.
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < m; ++j)
			if (map[i][j] == -1 && !visited[i][j])
				makeIndex(i, j, ++land);
	// 갈 수 있는 모든 루트를 edge에 저장한다.
	makeRoute();
	// 섬에 갈 수 있는 루트가 없다면 종료
	for (int i = 1; i <= land; ++i) {
		if (graph[i].empty()) {
			puts("-1");
			return 0;
		}
	}
	// 임의의 섬(섬의 개수는 2개 이상이므로 1을 넣었다.)에서 출발하여 모든 섬을 방문할 수 없다면 종료
	dfs(1);
	for (int i = 1; i <= land; ++i) {
		if (!visited3[i]) {
			puts("-1");
			return 0;
		}
	}
	// 모든 섬에 다리를 놓을 수 있음이 보장되었다면 거리를 기준으로 정렬한다.
	// 크루스칼 알고리즘
	sort(edge.begin(), edge.end());
	// 부모를 자신으로 초기화
	for (int i = 1; i <= land; ++i)
		parent[i] = i;
	
	int ans = 0;
	for (auto& e : edge) {
		int d = e.first;
		int u = getParent(e.second.first);
		int v = getParent(e.second.second);
		if (u == v) continue; // 부모 노드가 서로 같다면 싸이클이 생기므로 무시한다.
		unionParent(u, v); // 부모 노드를 같게 한다.
		ans += d;
	}
	cout << ans << '\n';
		
	return 0;
}
