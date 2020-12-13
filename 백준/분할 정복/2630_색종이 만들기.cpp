//
//  2630_색종이 만들기.cpp
//  Algorithms-CPP
//
//  Created by 장우진 on 2019/10/16.
//  Copyright © 2019 장우진. All rights reserved.
//

#include <iostream>
#define MAX 128
using namespace std;

int mat[MAX][MAX];  // w:0, b:1

void DnC(int n, int x, int y, int &w, int &b){
    int sum = 0;
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j)
            sum += mat[x + i][y + j];
    if (sum == 0 || sum == n * n) {
        mat[x][y] ? b++ : w++;
        return;
    }
    int half = n / 2;
    DnC(half, x, y, w, b);
    DnC(half, x, y + half, w, b);
    DnC(half, x + half, y, w, b);
    DnC(half, x + half, y + half, w, b);
}
         
int main() {
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j)
            cin >> mat[i][j];
    int b = 0, w = 0;
    DnC(n, 0, 0, w, b);
    cout << w << endl << b << endl;
    return 0;
}
