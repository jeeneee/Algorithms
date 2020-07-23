//
//  [2020 카카오 인턴십] 경주로 건설.cpp
//  Algorithms-CPP
//
//  Created by 장우진 on 2020/07/23.
//  Copyright © 2020 장우진. All rights reserved.
//

#include <iostream>
#include <vector>
#include <cstring>
#include <queue>
#include <algorithm>
using namespace std;

struct Car { int x, y, cost, dir; };
const int dx[] = { 0, 1, 0, -1 };
const int dy[] = { 1, 0, -1, 0 };
const int INF = 2e9;
const int MAX = 25;
int costs[MAX][MAX];

int solution(vector<vector<int>> board) {
    int answer = INF;
	int n = board.size();
	memset(costs, 0x3f, sizeof(costs));
	queue<Car> q;
	q.push({ 0, 0, 0, 0 });
	q.push({ 0, 0, 0, 1 });
	costs[0][0] = 0;
	while (!q.empty()) {
		Car now = q.front(); q.pop();
		if (now.x == n-1 && now.y == n-1) {
			answer = min(answer, now.cost);
			continue;
		}
		int dir[3] = { now.dir, (now.dir + 1) % 4, (now.dir + 3) % 4 };
		for (int i = 0; i < 3; ++i) {
			int nx = now.x + dx[dir[i]];
			int ny = now.y + dy[dir[i]];
			if (nx < 0 || nx >= n || ny < 0 || ny >= n) continue;
			if (board[nx][ny] == 1) continue;
			int cost = now.cost + (i == 0 ? 100 : 600);
			if (cost <= costs[nx][ny]) {
				costs[nx][ny] = cost;
				q.push({ nx, ny, cost, dir[i] });
			}
		}
	}
    return answer;
}

int main() {
	ios::sync_with_stdio(false); cin.tie(0);
	vector<vector<int>> board = {
		{0,0,0,0,0,0,0,1},
		{0,0,0,0,0,0,0,0},
		{0,0,0,0,0,1,0,0},
		{0,0,0,0,1,0,0,0},
		{0,0,0,1,0,0,0,1},
		{0,0,1,0,0,0,1,0},
		{0,1,0,0,0,1,0,0},
		{1,0,0,0,0,0,0,0}
	};
	cout << solution(board) << endl;
	return 0;
}
