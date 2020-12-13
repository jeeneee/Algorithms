//
//  큰 수 만들기.cpp
//  Algorithms-CPP
//
//  Created by 장우진 on 2020/06/16.
//  Copyright © 2020 장우진. All rights reserved.
//

#include <iostream>
#include <string>
#include <vector>
#include <map>

using namespace std;

string solution(string number, int k) {
    string answer = "";
    int n = number.size() - k;
    int maxIdx = -1;
    for (int i = 0; i < n; ++i) {
        char maxNum = '0';
        for (int j = maxIdx+1; j <= k+i; ++j)
            if (number[j] > maxNum) {
                maxNum = number[j];
                maxIdx = j;
            }
        answer += maxNum;
    }
    return answer;
}

int main() {
	cout << solution("4177252841", 4) << endl;
	return 0;
}
