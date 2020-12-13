//
//  1167_트리의 지름.cpp
//  Algorithms-CPP
//
//  Created by 장우진 on 2019/10/22.
//  Copyright © 2019 장우진. All rights reserved.
//

/*
 여기서 중요한 포인트는 임의의 한 점에서 가장 먼 점을 찾은 후,
 그 점으로부터 가장 먼 점까지의 거리가 트리의 지름이란 점이다.
 */

#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#define MAX 100001
using namespace std;

vector<pair<int, int > > graph[MAX];
bool visited[MAX];
int farthestNode = 0;
int maxDistance = 0;

void dfs (int node, int distance) {
  if (visited[node])
    return;
  
  visited[node] = true;
  
  for (int i = 0; i < graph[node].size(); ++i) {
    int d = distance + graph[node][i].second;
    dfs(graph[node][i].first, d);
  }
  if (distance > maxDistance) {
    maxDistance = distance;
    farthestNode = node;
  }
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  
  int n;
  cin >> n;
  
  while (n--) {
    int from, to, distance;
    cin >> from;
    while (1) {
      cin >> to;
      if (to == -1)
        break;
      cin >> distance;
      graph[from].push_back( {to, distance} );
    }
  }
  fill(visited, visited + MAX, false);
  dfs(1, 0);
  fill(visited, visited + MAX, false);
  dfs(farthestNode, 0);
  cout << maxDistance << endl;
  
  return 0;
}
