//
//  9237_이장님 초대.cpp
//  Algorithms-CPP
//
//  Created by 장우진 on 2020/02/15.
//  Copyright © 2020 장우진. All rights reserved.
//

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	int n;
	scanf("%d", &n);
	vector<int> tree(n);
	for (int i = 0; i < n; ++i)
		scanf("%d", &tree[i]);
	sort(tree.begin(), tree.end());
	reverse(tree.begin(), tree.end());
	int ans = 0;
	for (int i = 0; i < n; ++i)
		ans = max(ans, tree[i] + i + 1);
	printf("%d\n", ans + 1);
	return 0;
}
