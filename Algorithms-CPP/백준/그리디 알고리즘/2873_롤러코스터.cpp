//
//  2873_롤러코스터.cpp
//  Algorithms-CPP
//
//  Created by 장우진 on 2019/11/21.
//  Copyright © 2019 장우진. All rights reserved.
//

#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
using namespace std;

const int MAX = 1000;
int map[MAX][MAX];

void append(string &s, char c, int cnt) {
    for (int i = 0; i < cnt; ++i) {
        s += c;
    }
}

string go(int R, int C) {
    string s = "";
    // 세로가 홀수일 경우
    if (R % 2 == 1) {
        for (int i = 0; i < R; ++i) {
            if (i % 2 == 0) {
                append(s, 'R', C - 1);
                if (i != R - 1)
                    append(s, 'D', 1);
            } else {
                append(s, 'L', C - 1);
                append(s, 'D', 1);
            }
        }
    // 가로가 홀수일 경우
    } else if (C % 2 == 1) {
        for (int j = 0; j < C; ++j) {
            if (j % 2 == 0) {
                append(s, 'D', R - 1);
                if (j != C - 1)
                    append(s, 'R', 1);
            } else {
                append(s, 'U', R - 1);
                append(s, 'R', 1);
            }
        }
    // 가로, 세로가 모두 짝수일 경우
    } else {
        int x = 1, y = 0;
        for (int i = 0; i < R; ++i) {
            for (int j = 0; j < C; ++j) {
                // 출발점 및 도착점과의 색이 다르고 기쁨이 가장 적은 인덱스를 구함
                if ((i + j) % 2 == 1 && map[i][j] < map[y][x]) {
                    x = j;
                    y = i;
                }
            }
        }
        int x1 = 0, y1 = 0;
        int x2 = C - 1, y2 = R - 1;
        string s2 = ""; // 거꾸로 추가할 문자열
        // 두 줄이 남도록 줄인다.
        while (y2 - y1 > 1) {
            if (y1/2 < y/2) {
                append(s, 'R', C - 1);
                append(s, 'D', 1);
                append(s, 'L', C - 1);
                append(s, 'D', 1);
                y1 += 2;
            }
            if (y2/2 > y/2) {
                append(s2, 'R', C - 1);
                append(s2, 'D', 1);
                append(s2, 'L', C - 1);
                append(s2, 'D', 1);
                y2 -= 2;
            }
        }
        // 2x2 크기가 남을 때까지 줄인다.
        while (x2 - x1 > 1) {
            if (x1/2 < x/2) {
                append(s, 'D', 1);
                append(s, 'R', 1);
                append(s, 'U', 1);
                append(s, 'R', 1);
                x1 += 2;
            }
            if (x2/2 > x/2) {
                append(s2, 'D', 1);
                append(s2, 'R', 1);
                append(s2, 'U', 1);
                append(s2, 'R', 1);
                x2 -= 2;
            }
        }
        if (y == y1) {
            append(s, 'D', 1);
            append(s, 'R', 1);
        } else {
            append(s, 'R', 1);
            append(s, 'D', 1);
        }
        reverse(s2.begin(), s2.end());
        s += s2;
    }
    return s;
}

int main() {
    int R, C;
    scanf("%d %d", &R, &C);
    for (int y = 0; y < R; ++y) {
        for (int x = 0; x < C; ++x) {
            scanf("%d", &map[y][x]);
        }
    }
    cout << go(R, C) << '\n';
    
    return 0;
}
