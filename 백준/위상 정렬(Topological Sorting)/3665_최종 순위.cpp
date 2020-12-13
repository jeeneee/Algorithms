//
//  3665_최종 순위.cpp
//  Algorithms-CPP
//
//  Created by 장우진 on 2020/02/09.
//  Copyright © 2020 장우진. All rights reserved.
//
/*
 인접 리스트가 아닌 인접 행렬로 순서를 표시하였다.
 정답은 세 가지로 분류되는데, 확실한 순위가 정해지든지(1), 순위가 안정해지든지(2),
 데이터에 일관성이 없든지(3) 세 가지다.

 (1)은 위상정렬이 완료되면 당연한 결과다.

 (2)는 테크트리가 완료되는 노드가 동시에 2개 이상 생긴다는 뜻으로, 큐에 2개 이상의 노드가 들어가는 결과다.

 (3)은 사이클이 생긴다는 의미로, 위상정렬 완료뒤에도 정렬되지 않은 노드가 남아있는 결과다.
 */

#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
#include <algorithm>
using namespace std;

const int MAX = 500 + 1;
bool t[MAX][MAX];
int in[MAX];
int order[MAX];

int main() {
	int tc, n, m, a, b;
	scanf("%d", &tc);
	while (tc--) {
		memset(in, 0, sizeof(in));
		memset(t, 0, sizeof(t));
		
		scanf("%d", &n);
		for (int i = 1; i <= n; ++i)
			scanf("%d", &order[i]);
		
		for (int i = 1; i <= n; ++i) {
			for (int j = i+1; j <= n; ++j) {
				t[order[i]][order[j]] = 1;
				in[order[j]]++;
			}
		}
		
		scanf("%d", &m);
		while (m--) {
			scanf("%d %d", &a, &b);
			if (t[a][b]) {
				t[a][b] = 0;
				t[b][a] = 1;
				in[b]--; in[a]++;
			} else {
				t[b][a] = 0;
				t[a][b] = 1;
				in[a]--; in[b]++;
			}
		}
		
		queue<int> q;
		for (int i = 1; i <= n; ++i) {
			if (!in[i])
				q.push(i);
		}
		
		bool isPos = true;
		vector<int> ans;
		while (!q.empty()) {
			if (q.size() > 1) {
				isPos = false;
				break;
			}
			
			int x = q.front();
			q.pop();
			ans.push_back(x);
			
			for (int i = 1; i <= n; ++i) {
				if (t[x][i]) {
					in[i]--;
					if (!in[i])
						q.push(i);
				}
			}
		}
		
		if (!isPos)
			printf("?");
		else if (ans.size() == n)
			for (auto a : ans)
				printf("%d ", a);
		else
			printf("IMPOSSIBLE");
		
		printf("\n");
	}
	return 0;
}
