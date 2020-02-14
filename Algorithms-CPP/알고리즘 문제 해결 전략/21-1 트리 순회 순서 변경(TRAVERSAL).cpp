//
//  21-1 트리 순회 순서 변경(TRAVERSAL).cpp
//  Algorithms-CPP
//
//  Created by 장우진 on 2020/02/14.
//  Copyright © 2020 장우진. All rights reserved.
//

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> slice(const vector<int>& v, int a, int b) {
	return vector<int>(v.begin() + a, v.begin() + b);
}

void printPostOrder(const vector<int>& preorder,
					const vector<int>& inorder) {
	const int n = (int)preorder.size();
	if (preorder.empty())
		return;
	const int root = preorder[0];
	const int le = find(inorder.begin(), inorder.end(), root) - inorder.begin();
//	const int ri = n - 1 - le;
	printPostOrder(slice(preorder, 1, le + 1), slice(inorder, 0, le));
	printPostOrder(slice(preorder, le + 1, n), slice(inorder, le + 1, n));
	cout << root << ' ';
}

int main() {
	ios::sync_with_stdio(false); cin.tie(0);
	int t, n;
	cin >> t;
	while (t--) {
		cin >> n;
		vector<int> preorder(n), inorder(n);
		for (int i = 0; i < n; ++i)
			cin >> preorder[i];
		for (int i = 0; i < n; ++i)
			cin >> inorder[i];
		printPostOrder(preorder, inorder);
	}
	return 0;
}
