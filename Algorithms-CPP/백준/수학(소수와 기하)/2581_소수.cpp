//
//  2581_소수.cpp
//  Algorithms-CPP
//
//  Created by 장우진 on 2019/10/24.
//  Copyright © 2019 장우진. All rights reserved.
//

#include <iostream>
using namespace std;

const int MAX = 10000;

int main() {
  bool *primeArray = new bool[MAX + 1];
  for (int i = 2; i < MAX + 1; ++i)
    primeArray[i] = true;
  
  for (int i = 2; i * i <= MAX; ++i)
    if (primeArray[i])
      for (int j = i * i; j <= MAX; j += i)
        primeArray[j] = false;
  
  int m, n, sum = 0, smallestPrime = -1;
  cin >> m >> n;
  for (int i = n; i >= m; --i) {
    if (primeArray[i]) {
      sum += i;
      smallestPrime = i;
    }
  }
  
  if (sum > 0)
    cout << sum << endl;
  cout << smallestPrime << endl;
  
  return 0;
}
