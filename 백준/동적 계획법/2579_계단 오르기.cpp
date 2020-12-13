#include <iostream>
#include <algorithm>
using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  
  int n;
  cin >> n;
  int *stair = new int[n];
  int *res = new int[n];
  
  for (int i = 0; i < n; ++i) {
    cin >> stair[i];
  }
  
  res[0] = stair[0]; // 1칸
  res[1] = max(stair[0] + stair[1], stair[1]); // 1칸 + 1칸, 2칸
  res[2] = max(stair[0] + stair[2], stair[1] + stair[2]); // 1칸 + 2칸, 2칸 + 1칸
  
  /* max(2칸 + 1칸, 2칸) */
  for (int i = 3; i < n; ++i) {
    res[i] = max(res[i - 3] + stair[i - 1], res[i - 2]) + stair[i];
  }
  
  cout << res[n - 1] << '\n';
  
  delete []stair;
  delete []res;
  return 0;
}
