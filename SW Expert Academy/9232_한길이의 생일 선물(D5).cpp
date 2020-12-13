//
//  9232_한길이의 생일 선물(D5).cpp
//  Algorithms-CPP
//
//  Created by 장우진 on 2020/04/17.
//  Copyright © 2020 장우진. All rights reserved.
//
/*
 해설: 입력값이 왔다갔다 하는데, 이를 내림차 순으로 강제로 만들고 투포인터를 이용하여 푼다.
 알고리즘: 투포인터
 */
#include <iostream>
#include <vector>
using namespace std;

int hole[300000], disk[300000];
int n, q;

int solve() {
	int pos_hole = 0, pos_disk = 0, ret = 0;
	while (pos_hole != n && pos_disk != q) {
		if (hole[n - pos_hole - 1] >= disk[pos_disk]) {
			ret = n - pos_hole;
			++pos_hole;
			++pos_disk;
		}
		else ++pos_hole;
	}
	if (pos_hole == n && pos_disk != q)
		return 0;
	return ret;
}

int main() {
	ios::sync_with_stdio(false); cin.tie(0);
	int T;
	cin >> T;
	for (int tc = 1; tc <= T; ++tc) {
		cin >> n >> q;
		int temp = 1e9;
		for (int i = 0; i < n; ++i) {
			int x; cin >> x;
			if (x <= temp) {
				hole[i] = x;
				temp = x;
			}
			else hole[i] = hole[i-1];
		}
		for (int i = 0; i < q; ++i)
			cin >> disk[i];
		cout << '#' << tc << ' ' << solve() << '\n';
	}
	return 0;
}
