//
//  2748_피보나치 수2.cpp
//  Algorithms-CPP
//
//  Created by 장우진 on 2019/10/24.
//  Copyright © 2019 장우진. All rights reserved.
//

#include <iostream>
using namespace std;

int main() {
  int n;
  cin >> n;
  
  long long int *f = new long long int[n + 1];
  f[0] = 0;
  f[1] = 1;
  
  for (int i = 2; i <= n; ++i) {
    f[i] = f[i - 2] + f[i - 1];
  }
  
  cout << f[n] << endl;
  
  delete []f;
  return 0;
}
