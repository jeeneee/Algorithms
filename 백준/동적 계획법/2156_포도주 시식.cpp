//
//  2156_포도주 시식.cpp
//  Algorithms-CPP
//
//  Created by 장우진 on 2019/10/24.
//  Copyright © 2019 장우진. All rights reserved.
//

#include <iostream>
#include <algorithm>
using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  
  int n;
  cin >> n;
  int *wine = new int[n + 1];
  int *res = new int[n + 1] {0};
  
  for (int i = 1; i <= n; ++i) {
    cin >> wine[i];
  }
  
  res[1] = wine[1];
  res[2] = wine[1] + wine[2];
  
  // 마지막 와인을 꼭 마셔야 할 필요가 없으므로 이전 결과와 비교하는 구문이 추가된다.
  for (int i = 3; i <= n; ++i) {
    res[i] = max(res[i - 1], max(res[i - 2] + wine[i],
                                 res[i - 3] + wine[i - 1] + wine[i]));
  }
  
  cout << res[n] << endl;
  
  delete []wine;
  delete []res;
  return 0;
}
