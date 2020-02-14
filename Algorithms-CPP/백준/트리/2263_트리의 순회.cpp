//
//  2263_트리의 순회.cpp
//  Algorithms-CPP
//
//  Created by 장우진 on 2020/01/27.
//  Copyright © 2020 장우진. All rights reserved.
//
/*
 preorder : root - left - right
 inorder : left - root - right
 postorder : left - right - root
 */
#include <iostream>
using namespace std;

const int MAX = 100000;

int post[MAX];
int pos[MAX + 1];

    // args: inorder_begin, inorder_end, post_begin, post_end
void sol(int ib, int ie, int pb, int pe) {
    if (ib > ie || pb > pe)
        return;
    
        // root는 postorder의 마지막 원소이다.
    int root = post[pe];
    cout << root << ' ';
    
        // inorder는 root를 기준으로 left, right로 나뉜다.
        // left subtree
    sol(ib, pos[root] - 1, pb, pb + pos[root] - ib - 1);
        // right subtree
    sol(pos[root] + 1, ie, pb + pos[root] - ib, pe - 1);
}

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL);
    int n;
    cin >> n;
    for (int i = 0, in; i < n; ++i) {
        cin >> in;
        pos[in] = i;
    }
    for (int i = 0; i < n; ++i) {
        cin >> post[i];
    }
    
    sol(0, n-1, 0, n-1);
    
    cout << '\n';
    
    return 0;
}

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
