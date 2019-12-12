//
//  1149_RGB 거리.cpp
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
  int N;
  cin >> N;
  
  vector<vector<int>> cost(N, vector<int> (3, 0));
  
  for (int i = 0; i < N; ++i)
    cin >> cost[i][0] >> cost[i][1] >> cost[i][2];
  
  vector<vector<int>> totalCost(N, vector<int> (3, 0));
  
  totalCost[0][0] = cost[0][0];
  totalCost[0][1] = cost[0][1];
  totalCost[0][2] = cost[0][2];
  
  for (int i = 1; i < N; ++i) {
    totalCost[i][0] = min(totalCost[i - 1][1], totalCost[i - 1][2]) + cost[i][0];
    totalCost[i][1] = min(totalCost[i - 1][0], totalCost[i - 1][2]) + cost[i][1];
    totalCost[i][2] = min(totalCost[i - 1][0], totalCost[i - 1][1]) + cost[i][2];
  }
  
  int result = min(min(totalCost[N - 1][0], totalCost[N - 1][1]), totalCost[N - 1][2]);
  
  cout << result << endl;
  
  return 0;
}
