//
//  14268_내리 갈굼 2.cpp
//  Algorithms-CPP
//
//  Created by 장우진 on 2020/03/16.
//  Copyright © 2020 장우진. All rights reserved.
//
/*
 문제: <14267_내리 갈굼>에 쿼리문이 추가됐다. 실시간으로 가중치를 반환해야 하기 때문에 업데이트를 바로
	  진행해줘야 하는데 전위 순회를 통해 넘버를 지정해주고 각 서브트리의 순회가 끝나면 out 배열에 따로
	  저장해 업데이트 시에 다른 가지에도 적용되는 가중치를 지워줄 수 있다.
 예제:
 5 6
 -1 1 2 2 1
 1 2 2
 1 3 4
 1 5 6
 2 2
 2 4
 2 5
 알고리즘: 펜윅트리
 O(N + MlogN)
 */
#include <iostream>
#include <vector>
using namespace std;

const int MAX = 100000 + 1;
vector<int> graph[MAX];
int in[MAX], out[MAX];
int tree[MAX];
int n, cnt;

// 전위 순회
void dfs(int u) {
	in[u] = ++cnt; // left
	for (auto& v: graph[u])
		dfs(v);
	out[u] = cnt; // right
}

void update(int x, int val) {
	for (int i = x; i <= n; i += (i&-i))
		tree[i] += val;
}

int query(int x) {
	int ret = 0;
	for (int i = x; i >= 1; i -= (i&-i))
		ret += tree[i];
	return ret;
}

int main() {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int m;
	cin >> n >> m;
	for (int ch = 1; ch <= n; ++ch) {
		int p; cin >> p;
		if (ch == 1) continue;
		graph[p].push_back(ch);
	}
	dfs(1);
	while (m--) {
		int op, x, w;
		cin >> op >> x;
		if (op == 1) {
			cin >> w;
			update(in[x], w);
			update(out[x]+1, -w); // 상관없는 부분은 지워준다.
		} else {
			cout << query(in[x]) << '\n';
		}
	}
	return 0;
}
