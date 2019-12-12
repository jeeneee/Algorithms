//
//  9461_파도반 수열.cpp
//  Algorithms-CPP
//
//  Created by 장우진 on 2019/10/22.
//  Copyright © 2019 장우진. All rights reserved.
//

/* 1, 1, 1, 2, 2, 3, 4, 5, 7, 9*/
#include <iostream>
using namespace std;

int main() {
  int TC, n;
  cin >> TC;
  while (TC--) {
    long long int a = 1, b = 1, c = 1, d = 0;
    cin >> n;
    if (n <= 3) {
      cout << 1 << endl;
      continue;
    }
    for (int i = 4; i <= n; ++i) {
      d = a + b;
      a = b;
      b = c;
      c = d;
    }
    cout << d << endl;
  }
  
  return 0;
}
