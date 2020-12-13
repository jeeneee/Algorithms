//
//  1967_트리의 지름.cpp
//  Algorithms-CPP
//
//  Created by 장우진 on 2019/10/22.
//  Copyright © 2019 장우진. All rights reserved.
//

#include <iostream>
#include <vector>
#include <algorithm>
#define MAX 10001
using namespace std;

vector<pair<int, int > > tree[MAX];
bool visited[MAX];
int maxWeight = 0;
int farthestNode = 0;

void dfs(int node, int weight) {
  if (visited[node])
    return;
  visited[node] = true;
  
  for (int i = 0; i < tree[node].size(); ++i) {
    dfs(tree[node][i].first, weight + tree[node][i].second);
  }
  
  if (weight > maxWeight) {
    maxWeight = weight;
    farthestNode = node;
  }
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  
  int n, parent, child, weight;
  cin >> n;
  for (int i = 0; i < n - 1; ++i) {
    cin >> parent >> child >> weight;
    tree[parent].push_back( {child, weight} );
    tree[child].push_back( {parent, weight} );
  }
  fill(visited, visited + MAX, false);
  dfs(1, 0);
  fill(visited, visited + MAX, false);
  dfs(farthestNode, 0);
  
  cout << maxWeight << endl;
  
  return 0;
}
