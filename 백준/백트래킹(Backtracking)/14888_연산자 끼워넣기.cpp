//
//  14888_연산자 끼워넣기.cpp
//  Algorithms-CPP
//
//  Created by 장우진 on 2019/10/27.
//  Copyright © 2019 장우진. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;

int max = -1234567890;
int min = 1234567890;
int *op;
int *arr;
bool *visited;

void solve(int v, const int& idx, int res, const int& n) {
    int result = 0;
    if (idx == n) {
        if (res < ::min) ::min = res;
        if (res > ::max) ::max = res;
    }
    for (int i = 0; i < n - 1; ++i) {   // 연산자 수
        if (!visited[i]) {
            switch (op[i]) {
                case 1:
                    result = res + arr[idx];
                    break;
                case 2:
                    result = res - arr[idx];
                    break;
                case 3:
                    result = res * arr[idx];
                    break;
                case 4:
                    result = res / arr[idx];
                    break;
            }
            visited[i] = true;
            solve(i, idx + 1, result, n);
        }
    }
    visited[v] = false;
}

int main() {
    int n;
    cin >> n;
    arr = new int[n];
    op = new int[n - 1];
    visited = new bool[n - 1];
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }
    int cnt = 0;
    for (int i = 1; i <= 4; ++i) {
        int num;
        cin >> num;
        for (int j = 0; j < num; ++j) {
            op[cnt++] = i;
        }
    }
    solve(0, 1, arr[0], n);
    cout << ::max << endl;
    cout << ::min << endl;
    delete []arr;
    delete []op;
    delete []visited;
    return 0;
}
