//
//  1978_소수 찾기.cpp
//  Algorithms-CPP
//
//  Created by 장우진 on 2019/10/24.
//  Copyright © 2019 장우진. All rights reserved.
//

#include <iostream>
using namespace std;

const int MAX = 1000;

int main() {
  bool *primeArray = new bool[MAX + 1];
  for (int i = 2; i < MAX + 1; ++i)
    primeArray[i] = true;
  
  for (int i = 2; i * i <= MAX; ++i)
    if (primeArray[i])
      for (int j = i * i; j <= MAX; j += i)
        primeArray[j] = false;
  
  int n, res = 0;
  cin >> n;
  while (n--) {
    int num;
    cin >> num;
    if (primeArray[num])
      res++;
  }
  cout << res << endl;
  
  return 0;
}
