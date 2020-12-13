//
//  3752_가능한 시험 점수.cpp
//  Algorithms-CPP
//
//  Created by 장우진 on 2020/04/13.
//  Copyright © 2020 장우진. All rights reserved.
//

#include <iostream>
#include <cstring>
using namespace std;

const int MAX = 10000 + 1;
int a[100];
bool score[MAX];
int n;

int main() {
	int T;
	cin >> T;
	for (int tc = 1; tc <= T; ++tc) {
		memset(score, false, sizeof(score));
		cin >> n;
		int sum = 0;
		for (int i = 0; i < n; ++i) {
			cin >> a[i];
			sum += a[i];
		}
		score[0] = true;
		for (int i = 0; i < n; ++i)
			for (int j = sum; j >= 0; --j)
				if (score[j])
					score[j + a[i]] = true;
		int ans = 0;
		for (int i = 0; i < MAX; ++i)
			if (score[i]) ++ans;
		cout << "#" << tc << " " << ans << "\n";
	}
	return 0;
}
