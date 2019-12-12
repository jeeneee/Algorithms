//
//  6064_카잉 달력.cpp
//  Algorithms-CPP
//
//  Created by 장우진 on 2019/10/24.
//  Copyright © 2019 장우진. All rights reserved.
//

#include <iostream>
using namespace std;

// 최대 공약수
int gcd(int a, int b) {
  if (a % b == 0) return b;
  return gcd(b, a % b);
}

// 최소 공배수
int lcm(int a, int b) {
  return a * b / gcd(a, b);
}

void swap(int &a, int &b) {
  int temp = a;
  a = b;
  b = temp;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  
  int TC;
  cin >> TC;
  
  while (TC--) {
    int M, N, x, y;
    cin >> M >> N >> x >> y;
    
    if (M > N) {
      swap(M, N);
      swap(x, y);
    }
    
    int b, res = x;
    bool isFound = false;
    for (int i = 0; i < lcm(M, N) / M; ++i) {
      b = (x + M * i) % N;
      if (b == 0)
        b = N;
      res += M;
      if (b == y) {
        cout << res - M << '\n';
        isFound = true;
        break;
      }
    }
    if (!isFound)
      cout << -1 << '\n';
  }
  
  return 0;
}
