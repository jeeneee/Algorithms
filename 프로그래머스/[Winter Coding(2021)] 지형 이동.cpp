//
//  Winter Coding(~2018)] 방문 길이.cpp
//  Algorithms-CPP
//
//  Created by 장우진 on 2020/05/18.
//  Copyright © 2020 장우진. All rights reserved.
//

#include <iostream>
#include <string>
using namespace std;

int solution(string dirs) {
	// RDLU
	const int dx[] = {0, 1, 0, -1};
	const int dy[] = {1, 0, -1, 0};
	bool visited[11][11][4] = {false, };
	int x = 5, y = 5;
	int nx, ny, d;
	int answer = 0;
	for (auto& dir : dirs) {
		if (dir == 'U') d = 3;
		else if (dir == 'D') d = 1;
		else if (dir == 'R') d = 0;
		else d = 2;
		nx = x + dx[d];
		ny = y + dy[d];
		if (nx < 0 || nx > 10 || ny < 0 || ny > 10) continue;
		if (!visited[x][y][d]) {
			visited[x][y][d] = true;
			visited[nx][ny][(d+2)%4] = true;
			answer++;
		}
		x = nx; y = ny;
	}
	return answer;
}

int main() {
	string dirs = "ULURRDLLU";
	cout << solution(dirs) << endl;
	return 0;
}
