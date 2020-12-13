//
//  15652_N과 M(4).cpp
//  Algorithms-CPP
//
//  Created by 장우진 on 2019/10/25.
//  Copyright © 2019 장우진. All rights reserved.
//

#include <iostream>
#include <vector>
#include <algorithm>
#define MAX 9
using namespace std;

vector<int> picked;
bool visited[MAX] = {false};

void printPicked(int m) {
  for (int i = 1; i <= m; ++i) {
    cout << picked[i] << ' ';
  }
  cout << '\n';
}

void pick(int toPick, int n, int m) {
  if (toPick == 0) {printPicked(m); return;}
  for (int i = 1; i <= n; ++i) {
    if (i >= picked.back()) {
//      visited[i] = true;
      picked.push_back(i);
      pick(toPick - 1, n, m);
//      visited[i] = false;
      picked.pop_back();
    }
  }
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  
  int n, m;
  cin >> n >> m;
  
  picked.push_back(0);
  pick(m, n, m);
  
  return 0;
}
