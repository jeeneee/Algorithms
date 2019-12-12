//
//  3009_네 번째 점.cpp
//  Algorithms-CPP
//
//  Created by 장우진 on 2019/10/24.
//  Copyright © 2019 장우진. All rights reserved.
//
/* XOR 연산을 이용한 풀이 */
#include <iostream>
using namespace std;

int main() {
  int x[3], y[3];
  
  for (int i = 0; i < 3; ++i) {
    cin >> x[i] >> y[i];
  }
  
  cout << (x[0] ^ x[1] ^ x[2]) << ' ' << (y[0] ^ y[1] ^y[2]) << endl;

  return 0;
}

