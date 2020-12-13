//
//  Winter Coding(~2018)] 배달.cpp
//  Algorithms-CPP
//
//  Created by 장우진 on 2020/05/18.
//  Copyright © 2020 장우진. All rights reserved.
//

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

typedef pair<int, int> pii;
const int INF = 987654321;

vector<int> dijkstra(int src, int N, vector<vector<pii>>& graph) {
	vector<int> distance(N+1, INF);
	distance[src] = 0;
	
	priority_queue<pii, vector<pii>, greater<pii>> pq;
	pq.push( {distance[src], src} );
	while (!pq.empty()) {
		int d = pq.top().first;
		int v = pq.top().second;
		pq.pop();
		
		if (distance[v] < d) continue;
		
		for (int i = 0; i < graph[v].size(); ++i) {
			int adj_d = d + graph[v][i].second;
			int adj_v = graph[v][i].first;
			if (distance[adj_v] > adj_d) {
				distance[adj_v] = adj_d;
				pq.push( {adj_d, adj_v} );
			}
		}
	}
	return distance;
}

int solution(int N, vector<vector<int> > road, int K) {
	vector<vector<pii>> graph(N+1);
	for (auto& a : road) {
		graph[a[0]].push_back( {a[1], a[2]} );
		graph[a[1]].push_back( {a[0], a[2]} );
	}
	vector<int> distance = dijkstra(1, N, graph);
	int answer = 0;
	for (int i = 1; i <= N; ++i)
		if (distance[i] <= K) answer++;
	return answer;
}

int main() {
	int N = 5, K = 3;
	vector<vector<int>> road = {
		{1,2,1},{2,3,3},{5,2,2},{1,4,2},{5,3,1},{5,4,2}
	};
	cout << solution(N, road, K) << endl;
	return 0;
}
