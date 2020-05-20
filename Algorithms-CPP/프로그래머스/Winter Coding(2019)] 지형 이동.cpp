//
//  Winter Coding(2019)] 지형 이동.cpp
//  Algorithms-CPP
//
//  Created by 장우진 on 2020/05/20.
//  Copyright © 2020 장우진. All rights reserved.
//

#include <iostream>
#include <string>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

const int dx[] = {0, 1, 0, -1};
const int dy[] = {1, 0, -1, 0};

void markLand(vector<vector<int>>& land, vector<vector<int>>& map,
			  int x, int y, int height, int num) {
	int n = land.size();
	map[x][y] = num;
	for (int i = 0; i < 4; ++i) {
		int nx = x + dx[i];
		int ny = y + dy[i];
		if (nx < 0 || nx >= n || ny < 0 || ny >= n) continue;
		if (map[nx][ny] == -1 && abs(land[nx][ny] - land[x][y]) <= height)
			markLand(land, map, nx, ny, height, num);
	}
}

int getParent(int x, vector<int>& parent) {
	if (x == parent[x]) return x;
	return parent[x] = getParent(parent[x], parent);
}

void merge(int a, int b, vector<int>& parent) {
	if (a < b) parent[b] = a;
	else parent[a] = b;
}

int solution(vector<vector<int>> land, int height) {
	int n = land.size();
	vector<vector<int>> map(n, vector<int>(n, -1)); // 각 섬의 인덱스 표시
	int num = 0; // 섬의 개수
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < n; ++j)
			if (map[i][j] == -1) markLand(land, map, i, j, height, num++);
	// 300 x 300 x 4 = 360,000, edge는 최대 36만 개 있다.
	vector<pair<int, pair<int, int>>> edges;
 	for (int x = 0; x < n; ++x) {
		for (int y = 0; y < n; ++y) {
			for (int d = 0; d < 4; ++d) {
				int nx = x + dx[d], ny = y + dy[d];
				if (nx < 0 || nx >= n || ny < 0 || ny >= n) continue;
				int from = map[x][y], to = map[nx][ny];
				if (from != to)
					edges.push_back( {abs(land[nx][ny] - land[x][y]), {from, to}} );
			}
		}
	}
	sort(edges.begin(), edges.end());
	// MST
	vector<int> parent(num);
	for (int i = 0; i < num; ++i) parent[i] = i;
	int answer = 0;
	for (auto& edge : edges) {
		int a = edge.second.first;
		int b = edge.second.second;
		int d = edge.first;
		int parent_a = getParent(a, parent);
		int parent_b = getParent(b, parent);
		if (parent_a != parent_b) {
			merge(parent_a, parent_b, parent);
			answer += d;
		}
	}
	return answer;
}

int main() {
	vector<vector<int>> land = {
		{10, 11, 10, 11}, {2, 21, 20, 10}, {1, 20, 21, 11}, {2, 1, 2, 1}
	};
	int height = 1;
	cout << solution(land, height) << endl;
	return 0;
}
