//
//  15663_N과 M(9).cpp
//  Algorithms-CPP
//
//  Created by 장우진 on 2019/10/26.
//  Copyright © 2019 장우진. All rights reserved.
//

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> picked;
vector<int> board;
bool visited[9];

void printPicked(const int& m) {
  for (int i = 0; i < m; ++i) {
    cout << picked[i] << ' ';
  }
  cout << '\n';
}

void pick(int toPick, const int& n, const int& m) {
  if (toPick == 0) { printPicked(m); return; }
  
  bool isUsed[10001] = {false, };
  
  for (int i = 0; i < n; ++i) {
    if (!visited[i] && !isUsed[board[i]]) {
      isUsed[board[i]] = true;
      visited[i] = true;
      picked.push_back(board[i]);
      pick(toPick - 1, n, m);
      picked.pop_back();
      visited[i] = false;
    }
  }
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  
  int n, m;
  cin >> n >> m;
  
  for (int i = 0; i < n; ++i) {
    int num;
    cin >> num;
    board.push_back(num);
  }
  
  sort(board.begin(), board.end());
  
  pick(m, n, m);
  
  return 0;
}
