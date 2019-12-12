//
//  1932_정수 삼각형.cpp
//  Algorithms-CPP
//
//  Created by 장우진 on 2019/10/22.
//  Copyright © 2019 장우진. All rights reserved.
//

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
  int n;
  cin >> n;
  
  vector<vector<int>> cost(n, vector<int>(n, 0));
  vector<vector<int>> totalCost(n, vector<int>(n, 0));
  
  for (int i = 0; i < n; ++i)
    for (int j = 0; j < i + 1; ++j)
      cin >> cost[i][j];
  
  totalCost[0][0] = cost[0][0];
  
  for (int i = 1; i < n; ++i) {
    totalCost[i][0] = totalCost[i - 1][0] + cost[i][0];
    for (int j = 1; j < i; ++j) {
      totalCost[i][j] = max(totalCost[i - 1][j - 1], totalCost[i - 1][j]) + cost[i][j];
    }
    totalCost[i][i] = totalCost[i - 1][i - 1] + cost[i][i];
  }
  
  int max = -1;
  for (int j = 0; j < n; ++j) {
    if (totalCost[n - 1][j] > max)
      max = totalCost[n - 1][j];
  }
  
  cout << max << endl;
  
  return 0;
}
