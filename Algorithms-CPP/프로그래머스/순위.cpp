//
//  순위.cpp
//  Algorithms-CPP
//
//  Created by 장우진 on 2020/06/20.
//  Copyright © 2020 장우진. All rights reserved.
//
// 플로이드와셜

#include <iostream>
#include <string>
#include <vector>

using namespace std;

int solution(int n, vector<vector<int>> results) {
    int answer = 0;
	vector<vector<bool>> player(n+1, vector<bool>(n+1, 0));
	for (int i = 1; i <= n; ++i) player[i][i] = 1;
	for (int i = 0; i < results.size(); ++i)
		player[results[i][0]][results[i][1]] = 1;
	for (int k = 1; k <= n; ++k)
		for (int i = 1; i <= n; ++i)
			for (int j = 1; j <= n; ++j)
				if (player[i][k] && player[k][j])
					player[i][j] = 1;
    for (int i = 1; i <= n; ++i) {
        bool flag = false;
        for (int j = 1; j <= n; ++j) {
            if (!player[i][j] && !player[j][i])
                flag = true;
        }
		if (!flag) ++answer;
    }
    return answer;
}

int main() {
	vector<vector<int>> results = {
		{4, 3}, {4, 2}, {3, 2}, {1, 2}, {2, 5}
	};
	cout << solution(5, results) << endl;
	return 0;
}
