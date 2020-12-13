//
//  2580_스도쿠.cpp
//  Algorithms-CPP
//
//  Created by 장우진 on 2019/10/26.
//  Copyright © 2019 장우진. All rights reserved.
//

#include <iostream>
#include <vector>
#include <utility>
#define SIZE 9
using namespace std;

int sudoku[SIZE][SIZE];
vector<pair<int, int > > toSolve; // first: row, second: column

void print() {
    for (int i = 0; i < SIZE; ++i) {
        for (int j = 0; j < SIZE; ++j)
            cout << sudoku[i][j] << ' ';
        cout << '\n';
    }
}

bool chkRow(const int& row, const int& num) {
    for (int j = 0; j < SIZE; ++j)
        if (sudoku[row][j] == num)
            return false;
    return true;
}

bool chkCol(const int& col, const int& num) {
    for (int i = 0; i < SIZE; ++i)
        if (sudoku[i][col] == num)
            return false;
    return true;
}

bool chkSqr(const int& row, const int& col, const int& num) {
    int r = row / 3;
    int c = col / 3;
    for (int i = r * 3; i < (r * 3) + 3; ++i)
        for (int j = c * 3; j < (c * 3) + 3; ++j)
            if (sudoku[i][j] == num)
                return false;
    return true;
}

bool pass(const int& row, const int& col, const int& num) {
    return chkRow(row, num) && chkCol(col, num) && chkSqr(row, col, num);
}

void solve(const int& index) {
    if (index == toSolve.size()) { print(); exit(0); }
    for (int num = 1; num <= SIZE; ++num) {
        int row = toSolve[index].first;
        int col = toSolve[index].second;
        if (pass(row, col, num)) {
            sudoku[row][col] = num;
            solve(index + 1);
            sudoku[row][col] = 0;
        }
    }
}

int main() {
    for (int i = 0; i < SIZE; ++i) {
        for (int j = 0; j < SIZE; ++j) {
            cin >> sudoku[i][j];
            if (sudoku[i][j] == 0)
                toSolve.push_back( {i, j} );
        }
    }
    solve(0);
  
    return 0;
}

