//
//  1904_01타일.cpp
//  Algorithms-CPP
//
//  Created by 장우진 on 2019/10/22.
//  Copyright © 2019 장우진. All rights reserved.
//

#include <iostream>
using namespace std;

int main() {
  int n, a = 1, b = 2, c = 0;
  cin >> n;
  if (n == 1) {
    cout << a << endl;
    return 0;
  }
  else if (n == 2) {
    cout << b << endl;
    return 0;
  }
  for (int i = 3; i <= n; ++i) {
    c = (a + b) % 15746;
    a = b;
    b = c;
  }
  cout << c << endl;
  return 0;
}
