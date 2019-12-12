//
//  2447_별 찍기 10.cpp
//  Algorithms-CPP
//
//  Created by 장우진 on 2019/11/19.
//  Copyright © 2019 장우진. All rights reserved.
//

#include <iostream>
#include <vector>
#include <cstring>
#include <cmath>
#include <climits>
#include <algorithm>
using namespace std;

char mat[2200][2200];

/* 81 -> 27, 27 -> 9, 9 -> 3, 3 -> 1*/
void draw(int x, int y, int n) {
    if (n == 1) {
        mat[y][x] = '*';
        return;
    }
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            if (i == 1 && j == 1) continue;
            draw(x + j * n / 3, y + i * n / 3, n / 3);
        }
    }
}

int main() {
    int n;
    cin >> n;
    memset(mat, ' ', sizeof(mat));
    draw(0, 0, n);
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            printf("%c", mat[i][j]);
        }
        printf("\n");
    }
    return 0;
}
