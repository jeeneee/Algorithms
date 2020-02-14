//
//  21-2 요새(FORTRESS).cpp
//  Algorithms-CPP
//
//  Created by 장우진 on 2020/02/14.
//  Copyright © 2020 장우진. All rights reserved.
//

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct TreeNode {
	vector<TreeNode*> children;
};

int longest;
int n, y[100], x[100], r[100];

int sqr(int x) {
	return x * x;
}

int sqrdist(int a, int b) {
	return sqr(y[a] - y[b]) + sqr(x[a] - x[b]);
}

bool encloses(int a, int b) {
	return r[a] > r[b] && sqrdist(a, b) < sqr(r[a] - r[b]);
}

bool isChild(int parent, int child) {
	if (!encloses(parent, child)) return false;
	for (int i = 0; i < n; ++i) {
		if (i != parent && i != child
			&& encloses(parent, i) && encloses(i, child))
			return false;
	}
	return true;
}

TreeNode* getTree(int root) {
	TreeNode* ret = new TreeNode();
	for (int ch = 0; ch < n; ++ch) {
		if (isChild(root, ch))
			ret->children.push_back(getTree(ch));
	}
	return ret;
}

int height(TreeNode* root) {
	vector<int> heights;
	for (int i = 0; i < root->children.size(); ++i) {
		heights.push_back(height(root->children[i]));
	}
	if (heights.empty())
		return 0;
	sort(heights.begin(), heights.end());
	if (heights.size() >= 2) {
		longest = max(longest, heights[heights.size() - 2] +
					  heights[heights.size() - 1] + 2);
	}
	return heights.back() + 1;
}

int solve(TreeNode* root) {
	longest = 0;
	int h = height(root);
	return max(longest, h);
}

int main() {
	ios::sync_with_stdio(false); cin.tie(0);
	int c;
	cin >> c;
	while (c--) {
		cin >> n;
		for (int i = 0; i < n; ++i)
			cin >> y[i] >> x[i] >> r[i];
		TreeNode* tree = getTree(0);
		cout << solve(tree) << '\n';
	}
	return 0;
}
