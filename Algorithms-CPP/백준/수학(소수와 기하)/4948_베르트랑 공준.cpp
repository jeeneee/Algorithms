//
//  4948_베르트랑 공준.cpp
//  Algorithms-CPP
//
//  Created by 장우진 on 2019/10/24.
//  Copyright © 2019 장우진. All rights reserved.
//

#include <iostream>
using namespace std;

const int MAX = 123456 * 2;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  
  bool *primeArray = new bool[MAX + 1];
  for (int i = 2; i < MAX + 1; ++i)
    primeArray[i] = true;
  
  for (int i = 2; i * i <= MAX; ++i)
    if (primeArray[i])
      for (int j = i * i; j <= MAX; j += i)
        primeArray[j] = false;
  
  while (true) {
    int n, sum = 0;
    cin >> n;
    if (n == 0)
      break;
    for (int i = 2 * n; i > n; --i) {
      if (primeArray[i])
        sum ++;
    }
    cout << sum << '\n';
  }
  
  return 0;
}
