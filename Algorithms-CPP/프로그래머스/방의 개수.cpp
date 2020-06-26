//
//  방의 개수.cpp
//  Algorithms-CPP
//
//  Created by 장우진 on 2020/06/26.
//  Copyright © 2020 장우진. All rights reserved.
//
/*
 X자를 확인해줘야 하므로 모든 좌표를 2배로 늘린다.
 */
#include <iostream>
#include <string>
#include <vector>
#include <map>

using namespace std;

int solution(vector<int> arrows) {
	const int dx[] = { -1, -1, 0, 1, 1, 1, 0, -1 };
	const int dy[] = { 0, 1, 1, 1, 0, -1, -1, -1 };
    int answer = 0;
	map<pair<int, int>, int> vertex_chk;
	map<pair<pair<int, int>, pair<int, int>>, int> edge_chk;
	int x = 0;
	int y = 0;
	vertex_chk[{ x, y }] = 1;
	for (int i = 0; i < arrows.size(); ++i) {
        for (int j = 0; j < 2; ++j) {
            int nx = x + dx[arrows[i]];
            int ny = y + dy[arrows[i]];
            if (vertex_chk[{ nx, ny }] &&
                (edge_chk[ { { x, y }, { nx, ny } }] == 0 ||
                edge_chk[ { { nx, ny }, { x, y } }] == 0))
                ++answer;
            vertex_chk[{ nx, ny }] = 1;
            edge_chk[ { { x, y }, { nx, ny } }] = 1;
            edge_chk[ { { nx, ny }, { x, y } }] = 1;
            x = nx;
            y = ny;
        }
	}
    return answer;
}

int main() {
	vector<int> arrows = {6, 6, 6, 4, 4, 4, 2, 2, 2, 0, 0, 0, 1, 6, 5, 5, 3, 6, 0};
	cout << solution(arrows) << endl;
	return 0;
}
