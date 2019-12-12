//
//  1967_트리의 지름(bfs).cpp
//  Algorithms-CPP
//
//  Created by 장우진 on 2019/10/22.
//  Copyright © 2019 장우진. All rights reserved.
//
/*
 뭔가 부족하다.
 가중치 부분 수정해야 할듯.. 36행의 if문에서 44행의 작업을 대신할 수 있을 것이다.
 */
#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#define MAX 10001
using namespace std;

vector<pair<int, int > > tree[MAX];
int w[MAX] = {0, };
bool visited[MAX];
int maxWeight = 0;
int farthestNode = 0;

void bfs(int node, int size) {
  queue<int> q;
  q.push(node);
  visited[node] = true;
  
  while (!q.empty()) {
    int n = q.front();
    q.pop();
    for (int i = 0; i < tree[n].size(); ++i) {
      int des = tree[n][i].first;
      int weight = tree[n][i].second;
      if (!visited[des]) {
        visited[des] = true;
        q.push(des);
        w[des] = w[n] + weight;
      }
    }
  }
  
  for (int i = 1; i <= size; ++i) {
    if (w[i] > maxWeight) {
      maxWeight = w[i];
      farthestNode = i;
    }
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
  bfs(1, n);
  fill(visited, visited + MAX, false);
  fill(w, w + MAX, 0);
  bfs(farthestNode, n);
  cout << maxWeight << endl;

  return 0;
}
