//
//  Winter Coding(~2018)] 점프와 순간 이동.cpp
//  Algorithms-CPP
//
//  Created by 장우진 on 2020/05/19.
//  Copyright © 2020 장우진. All rights reserved.
//

#include <iostream>
using namespace std;

int solution(int n)
{
    int ans = 0;
	while (n) {
		if (n & 1) {
			++ans;
			--n;
		} else
			n >>= 1;
	}
    return ans;
}

int main() {
	cout << solution(6) << endl;
	return 0;
}
