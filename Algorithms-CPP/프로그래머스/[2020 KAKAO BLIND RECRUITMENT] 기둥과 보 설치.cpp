//
//  [2020 KAKAO BLIND RECRUITMENT] 기둥과 보 설치.cpp
//  Algorithms-CPP
//
//  Created by 장우진 on 2020/09/06.
//  Copyright © 2020 장우진. All rights reserved.
//

#include <iostream>
#include <string>
#include <vector>
#include <cstring>
using namespace std;

bool col[101][101];
bool beam[101][101];

bool checkCol(int x, int y, int n) {
    if (y == 0) return 1;
    if (col[x][y - 1]) return 1;
    if (x > 0 && beam[x - 1][y]) return 1;
    if (x < n && beam[x][y]) return 1;
    return 0;
}

bool checkBeam(int x, int y, int n) {
    if (col[x][y - 1]) return 1;
    if (x < n && col[x + 1][y - 1]) return 1;
    if (0 < x && x < n && beam[x - 1][y] && beam[x + 1][y]) return 1;
    return 0;
}

vector<vector<int>> solution(int n, vector<vector<int>> build_frame) {
    vector<vector<int>> answer;
    memset(col, 0, sizeof(col));
    memset(beam, 0, sizeof(beam));
    for (int i = 0; i < build_frame.size(); ++i) {
        int x, y, a, b;
        x = build_frame[i][0];
        y = build_frame[i][1];
        a = build_frame[i][2];
        b = build_frame[i][3];

        // 기둥 설치
        if (a == 0 && b == 1) {
            if (checkCol(x, y, n)) col[x][y] = 1;
        }
        // 보 설치
        else if (a == 1 && b == 1) {
            if (checkBeam(x, y, n)) beam[x][y] = 1;
        }
        // 기둥 삭제
        else if (a == 0 && b == 0) {
            col[x][y] = 0;
            if (y < n && col[x][y + 1] && !checkCol(x, y + 1, n))
                col[x][y] = 1;
            else if (y < n && beam[x][y + 1] && !checkBeam(x, y + 1, n))
                col[x][y] = 1;
            else if (x > 0 && y < n && beam[x - 1][y + 1] && !checkBeam(x - 1, y + 1, n))
                col[x][y] = 1;
        }
        // 보 삭제
        else if (a == 1 && b == 0) {
            beam[x][y] = 0;
            if (col[x][y] && !checkCol(x, y, n)) beam[x][y] = 1;
            else if (x < n && col[x + 1][y] && !checkCol(x + 1, y, n))
                beam[x][y] = 1;
            else if (x > 0 && beam[x - 1][y] && !checkBeam(x - 1, y, n))
                beam[x][y] = 1;
            else if (x < n && beam[x + 1][y] && !checkBeam(x + 1, y, n))
                beam[x][y] = 1;
        }
    }
    for (int i = 0; i <= n; ++i) {
        for (int j = 0; j <= n; ++j) {
            if (col[i][j]) answer.push_back({ i, j, 0 });
            if (beam[i][j]) answer.push_back({ i, j, 1 });
        }
    }
    return answer;
}

int main() {
    vector<vector<int>> build_frame = {
		{0,0,0,1},
		{2,0,0,1},
		{4,0,0,1},
		{0,1,1,1},
		{1,1,1,1},
		{2,1,1,1},
		{3,1,1,1},
		{2,0,0,0},
		{1,1,1,0},
		{2,2,0,1}
	};
    for (auto a : solution(5, build_frame))
        cout << a[0] << ' ' << a[1] << ' ' << a[2] << endl;
    return 0;
}
