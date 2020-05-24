//
//  [찾아라 프로그래밍 마에스터] 게임 맵 최단거리.cpp
//  Algorithms-CPP
//
//  Created by 장우진 on 2020/05/24.
//  Copyright © 2020 장우진. All rights reserved.
//

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

const int dx[] = {0, 1, 0, -1};
const int dy[] = {1, 0, -1, 0};

struct Node {
	int x, y, d;
};

int solution(vector<vector<int> > maps) {
	int n = maps.size();
	int m = maps[0].size();
	vector<vector<bool>> chk(n, vector<bool>(m, false));
	queue<Node> q;
	q.push( {0, 0, 1} );
	chk[0][0] = true;
	while (!q.empty()) {
		int x = q.front().x;
		int y = q.front().y;
		int d = q.front().d;
		q.pop();
		if (x == n-1 && y == m-1) return d;
		for (int i = 0; i < 4; ++i) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
			if (maps[nx][ny] == 1 && !chk[nx][ny]) {
				q.push( {nx, ny, d+1} );
				chk[nx][ny] = true;
			}
		}
	}
	return -1;
}

int main() {
	vector<vector<int>> maps = {
		{1,0,1,1,1},
		{1,0,1,0,1},
		{1,0,1,1,1},
		{1,1,1,0,1},
		{0,0,0,0,1}
	};
	cout << solution(maps) << endl;
	return 0;
}
