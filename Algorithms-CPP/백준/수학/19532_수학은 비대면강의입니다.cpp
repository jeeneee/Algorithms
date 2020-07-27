//
//  19532_수학은 비대면강의입니다.cpp
//  Algorithms-CPP
//
//  Created by 장우진 on 2020/07/27.
//  Copyright © 2020 장우진. All rights reserved.
//

#include <iostream>
using namespace std;

int main() {
	int a, b, c, d, e, f;
	cin >> a >> b >> c >> d >> e >> f;
	int x = (c * e - b * f) / (a * e - b * d);
	int y = (c * d - a * f) / (b * d - a * e);
	cout << x << ' ' << y << endl;
	return 0;
}
