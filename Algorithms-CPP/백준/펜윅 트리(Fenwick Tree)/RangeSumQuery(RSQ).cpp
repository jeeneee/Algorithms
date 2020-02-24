//
//  RangeSumQuery(RSQ).cpp
//  Algorithms-CPP
//
//  Created by 장우진 on 2020/02/24.
//  Copyright © 2020 장우진. All rights reserved.
//

#include<cassert>
#include<cstdlib>
#include<cstdio>
#include<iostream>
#include<string>
#include<vector>
using namespace std;

// 펜윅 트리의 구현. 가상의 배열 A[] 의 부분 합을
// 빠르게 구현할 수 있도록 한다. 초기화시에는 A[] 의
// 원소가 전부 0 이라고 생각한다.
struct FenwickTree {
	vector<int> tree;
	FenwickTree(int n) : tree(n+1) {}

	// A[0..pos] 의 부분 합을 구한다
	int sum(int pos) {
		// 인덱스를 1 부터 시작하는 것이라고 생각하자
		++pos;
		int ret = 0;
		while(pos > 0) {
			ret += tree[pos];
			// 다음 구간을 찾기 위해 최종 비트를 지운다
			pos &= (pos-1);
		}
		return ret;
	}

	// A[pos] 에 val 을 더한다
	void add(int pos, int val) {
		++pos;
		// 가장 오른쪽에 있는 1인 비트를 스스로에게 더해준다
		while(pos < tree.size()) {
			tree[pos] += val;
			pos += (pos & -pos);
		}
	}
};

int main() {
	int n = 10;
	FenwickTree tree(n);
	for (int i = 0; i < n; ++i)
		tree.add(i, i);
	cout << tree.sum(7) - tree.sum(3) << endl;
	return 0;
}

