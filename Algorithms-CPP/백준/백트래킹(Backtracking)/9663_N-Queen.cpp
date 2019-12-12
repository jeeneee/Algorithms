//
//  9663_N-Queen.cpp
//  Algorithms-CPP
//
//  Created by 장우진 on 2019/10/26.
//  Copyright © 2019 장우진. All rights reserved.
//

/*
 1. 퀸은 하나의 행에 한 개 배치한다.
 2. 퀸은 하나의 열에 한 개 배치한다.
 3. 퀸은 한 대각선에 한 개 배치한다.
 */

#include <iostream>
using namespace std;

bool *col; // 각 열에 퀸이 배치되었는지에 대한 여부를 저장
bool *diag1; // 대각선 방향 / 에 퀸이 배치되었는지에 대한 여부를 저장
bool *diag2; // 대각선 방향 \ 에 퀸이 배치되었는지에 대한 여부를 저장
int res = 0;

/* 각 행마다 확인한다. (문제쪼갬) */
void set(int i, const int& n) {
  if (i == n) { res++; return; }
  for (int j = 0; j < n; ++j) {
    if (!col[j] && !diag1[i + j] && !diag2[i - j + n - 1]) {
      col[j] = diag1[i + j] = diag2[i - j + n - 1] = true;
      set(i + 1, n);
      col[j] = diag1[i + j] = diag2[i - j + n - 1] = false;
    }
  }
}

int main() {
  int n; // 1 ~ 14
  cin >> n;
  
  col = new bool[n];
  diag1 = new bool[2 * n - 1];
  diag2 = new bool[2 * n - 1];
  
  set(0, n);
  
  cout << res << '\n';
  
  delete []col;
  delete []diag1;
  delete []diag2;
  return 0;
}
