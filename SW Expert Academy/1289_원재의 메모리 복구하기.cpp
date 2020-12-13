//
//  1289_원재의 메모리 복구하기.cpp
//  Algorithms-CPP
//
//  Created by 장우진 on 2020/04/11.
//  Copyright © 2020 장우진. All rights reserved.
//

#include <iostream>
#include <string>
using namespace std;

int main() {
	int T;
	cin >> T;
	for (int tc = 1; tc <= T; ++tc) {
		string mem, a;
		cin >> mem;
		a.resize(mem.size());
		for (int i = 0; i < mem.size(); ++i)
			a[i] = '0';
		
		int cnt = 0;
		for (int i = 0; i < mem.size(); ++i) {
			if (mem[i] != a[i]) {
				cnt++;
				for (int j = i; j < mem.size(); ++j)
					a[j] = mem[i];
			}
		}
		cout << "#" << tc << " " << cnt << "\n";
	}
	return 0;
}
