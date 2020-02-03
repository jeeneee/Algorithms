//
//  14890_경사로.cpp
//  Algorithms-CPP
//
//  Created by 장우진 on 2020/02/03.
//  Copyright © 2020 장우진. All rights reserved.
//

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

#define ABS(x) ( ((x) < 0) ? -(x) : (x) )
const int MAX = 100;
int map[MAX][MAX];
int arr[MAX];
int N, L;

bool canBuild(int x, int h) {
    for (int i = x; i < x + L; ++i) {
        if (arr[i] != h)
            return false;
    }
    return true;
}

    // d = 0: 가로, d = 1: 세로
bool pass(int rc, int d) {
    if (d == 0)
        for (int i = 0; i < N; ++i)
            arr[i] = map[rc][i];
    else
        for (int i = 0; i < N; ++i)
            arr[i] = map[i][rc];
    
    int flat = 1;
    for (int i = 1; i < N; ++i) {
        if (arr[i] - arr[i-1] == 0) // 평평할 때
            ++flat;
        else if (arr[i-1] == arr[i] + 1) { // 앞이 더 높을 때
            if (canBuild(i, arr[i])) {
                flat = 0;
                i += L - 1;
            } else {
                return false;
            }
        }
        else if (arr[i-1] == arr[i] - 1) { // 뒤가 더 높을 때
            if (flat >= L) {
                flat = 1;
            } else
                return false;
        }
        else
            return false;
    }
    return true;
}

int main() {
    cin >> N >> L;
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            cin >> map[i][j];
        }
    }
    
    int ans = 0;
    for (int d = 0; d < 2; ++d) {
        for (int i = 0; i < N; ++i) {
            if (pass(i, d))
                ++ans;
        }
    }
    cout << ans << endl;
    return 0;
}
