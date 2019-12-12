//
//  9020_골드바흐의 추측.cpp
//  Algorithms-CPP
//
//  Created by 장우진 on 2019/10/24.
//  Copyright © 2019 장우진. All rights reserved.
//

#include <iostream>
using namespace std;

const int MAX = 10000;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  
  bool *primeArray = new bool[MAX];
  for (int i = 2; i < MAX; ++i)
    primeArray[i] = true;
  
  for (int i = 2; i * i <= MAX; ++i)
    if (primeArray[i])
      for (int j = i * i; j <= MAX; j += i)
        primeArray[j] = false;
  
  int TC;
  cin >> TC;
  while (TC--) {
    int n;
    cin >> n;
    for (int i = n / 2; i >= 2; --i) {
      if (primeArray[i] && primeArray[n - i]) {
        cout << i << ' ' << n - i << '\n';
        break;
      }
    }
  }
  
  return 0;
}
