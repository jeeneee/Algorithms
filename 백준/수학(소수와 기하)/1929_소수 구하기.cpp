//
//  1929_소수 구하기.cpp
//  Algorithms-CPP
//
//  Created by 장우진 on 2019/10/24.
//  Copyright © 2019 장우진. All rights reserved.
//

#include <iostream>
using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  
  int m, n;
  cin >> m >> n;
  
  bool *primeArray = new bool[n + 1];
  for (int i = 2; i < n + 1; ++i)
    primeArray[i] = true;
  
  for (int i = 2; i * i <= n; ++i)
    if (primeArray[i])
      for (int j = i * i; j <= n; j += i)
        primeArray[j] = false;
  
  for (int i = m; i <= n; ++i) {
    if (primeArray[i])
      cout << i << '\n';
  }
  
  return 0;
}
