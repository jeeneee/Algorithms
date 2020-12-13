//
//  1057_토너먼트.cpp
//  Algorithms-CPP
//
//  Created by 장우진 on 2020/02/29.
//  Copyright © 2020 장우진. All rights reserved.
//

#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;

int main() {
	int n, a, b, round = 1;
	cin >> n >> a >> b;
	while (n > 2) {
		a = (a+1)/2;
		b = (b+1)/2;
		n = (n+1)/2;
		if (a == b)
			break;
		++round;
	}
	cout << round << endl;
	return 0;
}
