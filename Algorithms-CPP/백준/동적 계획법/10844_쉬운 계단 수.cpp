//
//  10844_쉬운 계단 수.cpp
//  Algorithms-CPP
//
//  Created by 장우진 on 2019/10/23.
//  Copyright © 2019 장우진. All rights reserved.
//
/*
 다이나믹답게 아래와 같은 규칙을 찾을 수 있다.
 한자리 1 1  1 1  1 1  1 1  1
 두자리 2 2 2 2 2 2 2 2 1
 세자리 3 4 4 4 4 4 4 3 2
 네자리 6 7 8 ...
 다섯잘 10 ...
  %10억을 조심하자!
 */
#include <iostream>
using namespace std;

const int divider = 1000000000;

int main() {
  int n;
  cin >> n;
  long long int dp[101][9];
  
  for (int i = 0; i < 2; ++i)
    for (int j = 0; j < 9; ++j)
      dp[i][j] = 1;
  
  for (int i = 2; i <= n; ++i) {
    for (int j = 0; j < 9; ++j) {
      if (j == 0)
        dp[i][j] = (dp[i - 2][j] + dp[i - 1][j + 1]) % divider;
      else if (j == 8)
        dp[i][j] = dp[i - 1][j - 1] % divider;
      else
        dp[i][j] = (dp[i - 1][j - 1] + dp[i - 1][j + 1]) % divider;
    }
  }
  
  long long int sum = 0;
  
  for (int j = 0; j < 9; ++j) {
    sum = (sum + dp[n][j]) % divider;
  }
  
  cout << sum << endl;
  
  return 0;
}
