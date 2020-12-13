//
//  11437_LCA.cpp
//  Algorithms-CPP
//
//  Created by 장우진 on 2020/02/17.
//  Copyright © 2020 장우진. All rights reserved.
//

#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
#include <cmath>
#include <algorithm>
using namespace std;

const int MAX = 50000 + 1;
const int max_depth = (int)floor(log2(MAX));
vector<int> graph[MAX];
int ac[MAX][20];
int depth[MAX];

void make_tree(int child, int parent) {
	// 자식의 깊이는 부모의 깊이 + 1
	depth[child] = depth[parent] + 1;
	// 자식의 2^0번째 조상은 부모이다.
	ac[child][0] = parent;
	// 예를 들면, child의 2^i번째 조상은 child의 2^(i-1)번째 조상의 입장에선 2^(i-1)번째 조상이다.
	for (int i = 1; i <= max_depth; ++i)
		ac[child][i] = ac[ac[child][i-1]][i-1];
	// dfs
	for (auto& ch : graph[child])
		if (ch != parent)
			make_tree(ch, child);
}

int main() {
	ios::sync_with_stdio(false); cin.tie(0);
	int n, m;
	cin >> n;
	for (int i = 0; i < n-1; ++i) {
		int from, to;
		cin >> from >> to;
		// 양방향 그래프
		graph[from].push_back(to);
		graph[to].push_back(from);
	}
	
	// 0의 깊이를 -1로 설정
	depth[0] = -1;
	// 루트가 1이며, 부모는 0으로 설정
	make_tree(1, 0);
	
	// 쿼리문
	cin >> m;
	while (m--) {
		int a, b;
		cin >> a >> b;
		if (depth[a] != depth[b]) {
			if (depth[a] > depth[b])
				swap(a, b);
			// b를 올려서 depth를 맞춰준다.
			/*
			 이렇게하면 만약 max_level이 4라면
			 2^4 -> 2^3 -> 2^2 -> 2^1 -> 2^0방식으로 찾아갈텐데
			 결국 1, 2, 3, 4, 5 ..., 31까지 모두 찾는 방식과 같아진다.
			 예를들어, i가 4일때와 1일때 만족했다 치면
			 depth[a] <= depth[ac[b][4]]에 의해
			 b = ac[b][4];가 되어 b는 b의 16번째 조상을 보고 있을 것이고
			 depth[a] <= depth[ac[b][1]]에 의해(현재 b는 처음 b의 16번째 조상인 b로 바뀌었다.)
			 b = ac[b][1];이 되어 b는 b의 2번째 조상을 보게 된다.
			 즉, b의 16번째 조상의 2번째 조상을 보는 것이니 b의 18번째 조상을 보게 된다.
			 (하고자 하는 말은 3번째, 7번째, 11번째 이런 조상들도 모두 볼 수 있다는 의미이다.)
			 */
			for (int i = max_depth; i >= 0; --i)
				// b의 2^i번째 조상이 a의 depth보다 크거나 같으면 계속 조상을 타고간다.
				if (depth[a] <= depth[ac[b][i]])
					b = ac[b][i];
		}
		int lca = a;
		// a와 b가 다르다면 현재 깊이가 같으니 깊이를 계속 올려 서로 다른 노드의 조상이 같아질 때까지 반복한다.
		// 즉, 서로 다른 노드(2,3)의 조상이 1로 같다면 lca = ac[2][0]에 의해 2의 조상이 1임을 알 수 있고
		// 마찬가지로 ac[3][0] 또한 3의 조상이 1임을 알게되며 알고리즘이 끝이난다.
		if (a != b) {
			for (int i = max_depth; i >= 0; --i) {
				if (ac[a][i] != ac[b][i]) {
					a = ac[a][i];
					b = ac[b][i];
				}
				lca = ac[a][i];
			}
		}
		cout << lca << '\n';
	}
	return 0;
}
